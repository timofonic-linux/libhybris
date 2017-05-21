
/**
 * Copyright (c) 2013, Franz-Josef Haider <f_haider@gmx.at>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **/

#include "wrappers.h"
#include "wrapper_code.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/mman.h>
#include <stdint.h>
#include <assert.h>

static int trace_dynhooked = 1;
static int trace_unhooked = 1;
// code resides in apkenv but is not very useful because most functions break:
//static int trace_arm_injection = 0;
//static int trace_thumb_injection = 0;
static int trace_hooked = 1;

static int release_registered = 0;

static int trace_calls_checked = 0;

static const char *msg_unhooked = "calling unhooked method";
static const char *msg_dynhook = "calling dynamically loaded method";
static const char *msg_hooked = "calling hooked method";

struct wrapper {
    char *name;
    void *ptr;
    unsigned int size;
    int type;
    struct wrapper *next;
};

struct wrapper *wrappers = NULL;

int wrapper_cmp(void *a, void *b) {
    struct wrapper *key = (struct wrapper*)a;
    struct wrapper *elem = (struct wrapper*)b;
    int c = strcmp(key->name, elem->name);
    if(0 == c) {
        return (key->type - elem->type);
    }
    return c;
}

void register_wrapper(void *wrapper_ptr, unsigned int size, char *name, int type)
{
    struct wrapper *it = wrappers;
    struct wrapper *last = NULL;
    while(NULL != it)
    {
        last = it;
        it = it->next;
    }
    struct wrapper *w = (struct wrapper*)malloc(sizeof(struct wrapper));
    w->name = name;
    w->ptr = wrapper_ptr;
    w->type = type;
    w->size = size;
    w->next = NULL;
    if(NULL == last)
    {
        wrappers = w;
    }
    else
    {
        last->next = w;
    }

    if(!release_registered)
    {
        atexit(release_all_wrappers);
    }
}

int is_traceable(const char *symbol)
{
    if(!trace_calls_checked)
    {
        trace_hooked = getenv("HYBRIS_TRACE_HOOKED") ? atoi(getenv("HYBRIS_TRACE_HOOKED")) : 0;
        trace_unhooked = getenv("HYBRIS_TRACE_UNHOOKED") ? atoi(getenv("HYBRIS_TRACE_UNHOOKED")) : 0;
        trace_dynhooked = getenv("HYBRIS_TRACE_DYNHOOKED") ? atoi(getenv("HYBRIS_TRACE_DYNHOOKED")) : 0;

        trace_calls_checked = 1;
    }

    return trace_hooked | trace_unhooked | trace_dynhooked;
}

void trace_callback(void *function, char *name, char *msg)
{
    fprintf(stderr, "%s: %s@%p\n", msg, name, function);
}

static size_t
get_wrapper_code_size(void *wrapper)
{
    // Find first occurence of 0xFFFFFFFF in the code object,
    // which is the placeholder for the attached data words
    uint32_t *ptr = wrapper;
    while (*ptr != 0xFFFFFFFF) {
        ptr++;
    }
    return ((void *)ptr - (void *)wrapper);
}

void *create_wrapper(const char *symbol, void *function, int wrapper_type)
{   
    size_t wrapper_size = 0;
    uint32_t wrapper_code = NULL;
    void *wrapper_addr = NULL;
    int helper = 0;

    const char *msg = NULL;

    switch(wrapper_type)
    {
        case WRAPPER_HOOKED:
            if(!trace_hooked) return function;
            break;
        case WRAPPER_UNHOOKED:
            if(!trace_unhooked) return function;
            break;
        case WRAPPER_DYNHOOK:
            if(!trace_dynhooked) return function;
            break;
        default:
            assert(NULL == "ERROR: invalid wrapper type!\n");
    };
    
    if(!is_traceable(symbol))
        return function;
    
    // get wrapper size and setup msg
    switch(wrapper_type)
    {
        // XXX: libhybris is compiled in thumb mode so we have to adjust.
        case WRAPPER_HOOKED:
            wrapper_code = (uint32_t)((char*)wrapper_code_generic) & (0xFFFFFFFE);
            msg = msg_hooked;
            break;
        case WRAPPER_UNHOOKED:
            wrapper_code = (uint32_t)((char*)wrapper_code_generic) & (0xFFFFFFFE);
            msg = msg_unhooked;
            break;
        case WRAPPER_DYNHOOK:
            wrapper_code = (uint32_t)((char*)wrapper_code_generic) & (0xFFFFFFFE);
            msg = msg_dynhook;
            break;
        default:
            assert(NULL == "ERROR: invalid wrapper type!\n");
    }

    wrapper_size = get_wrapper_code_size(wrapper_code);

    // 4 additional longs for data storage, see below
    wrapper_size += 4 * sizeof(uint32_t);
    
    // reserve memory for the generated wrapper
    wrapper_addr = mmap(NULL, wrapper_size,
        PROT_READ | PROT_WRITE | PROT_EXEC,
        MAP_ANONYMOUS | MAP_PRIVATE,
        0, 0);
    
    if(MAP_FAILED == wrapper_addr)
    {
        printf("ERROR: failed to create wrapper for %s@%x (mmap failed).\n", symbol, function);
        return function;
    }

    memcpy(wrapper_addr, wrapper_code, wrapper_size);

    // Helper = offset of data fields in wrapper_addr (interpreted as int32_t)
    helper = wrapper_size / sizeof(uint32_t) - 4;

    switch(wrapper_type)
    {
        case WRAPPER_HOOKED:
        case WRAPPER_UNHOOKED:
        case WRAPPER_DYNHOOK:
            ((int32_t*)wrapper_addr)[helper++] = (uint32_t)symbol;
            ((int32_t*)wrapper_addr)[helper++] = (uint32_t)function;
            ((int32_t*)wrapper_addr)[helper++] = (uint32_t)trace_callback;
            ((int32_t*)wrapper_addr)[helper++] = (uint32_t)msg;
            break;
        default:
            assert(0);
            break;
    };
    
    register_wrapper(wrapper_addr, wrapper_size, symbol, wrapper_type);

    return (void*)wrapper_addr;
}

void release_all_wrappers()
{
    struct wrapper *it = wrappers;
    while(NULL != it)
    {
        struct wrapper *next = it->next;
        munmap(it->ptr,it->size);
        free(it);
        it = next;
    }
}

