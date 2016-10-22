#ifndef WRAPPER_CODE_H
#define WRAPPER_CODE_H

#ifdef __cplusplus
extern "C" {
#endif

void wrapper_code_generic() __attribute__((naked,noinline));

#ifdef __cplusplus
}
#endif

#endif /* WRAPPER_CODE_H */
