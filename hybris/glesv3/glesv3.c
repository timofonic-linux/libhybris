/*
 * Copyright (c) 2012 Carsten Munk <carsten.munk@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#define GL_GLEXT_PROTOTYPES
#include <GLES3/gl3.h>
#include <GLES3/gl2ext.h>
#include <dlfcn.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include <egl/ws.h>
#include <hybris/common/binding.h>
#include <hybris/common/floating_point_abi.h>

static void *_libglesv3 = NULL;

/* Only functions with floating point argument need a wrapper to change the call convention correctly */

#define GLES3_LOAD(sym)  { *(&_ ## sym) = (void *) android_dlsym(_libglesv3, #sym);  }

void (*_glActiveTexture) (GLenum texture) FP_ATTRIB = NULL;
void (*_glAttachShader) (GLuint program, GLuint shader) FP_ATTRIB = NULL;
void (*_glBindAttribLocation) (GLuint program, GLuint index, const GLchar *name) FP_ATTRIB = NULL;
void (*_glBindBuffer) (GLenum target, GLuint buffer) FP_ATTRIB = NULL;
void (*_glBindFramebuffer) (GLenum target, GLuint framebuffer) FP_ATTRIB = NULL;
void (*_glBindRenderbuffer) (GLenum target, GLuint renderbuffer) FP_ATTRIB = NULL;
void (*_glBindTexture) (GLenum target, GLuint texture) FP_ATTRIB = NULL;
void (*_glBlendColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) FP_ATTRIB = NULL;
void (*_glBlendEquation) (GLenum mode) FP_ATTRIB = NULL;
void (*_glBlendEquationSeparate) (GLenum modeRGB, GLenum modeAlpha) FP_ATTRIB = NULL;
void (*_glBlendFunc) (GLenum sfactor, GLenum dfactor) FP_ATTRIB = NULL;
void (*_glBlendFuncSeparate) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) FP_ATTRIB = NULL;
void (*_glBufferData) (GLenum target, GLsizeiptr size, const void *data, GLenum usage) FP_ATTRIB = NULL;
void (*_glBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data) FP_ATTRIB = NULL;
GLenum (*_glCheckFramebufferStatus) (GLenum target) FP_ATTRIB = NULL;
void (*_glClear) (GLbitfield mask) FP_ATTRIB = NULL;
void (*_glClearColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) FP_ATTRIB = NULL;
void (*_glClearDepthf) (GLfloat d) FP_ATTRIB = NULL;
void (*_glClearStencil) (GLint s) FP_ATTRIB = NULL;
void (*_glColorMask) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) FP_ATTRIB = NULL;
void (*_glCompileShader) (GLuint shader) FP_ATTRIB = NULL;
void (*_glCompressedTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) FP_ATTRIB = NULL;
void (*_glCompressedTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) FP_ATTRIB = NULL;
void (*_glCopyTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) FP_ATTRIB = NULL;
void (*_glCopyTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) FP_ATTRIB = NULL;
GLuint (*_glCreateProgram) (void) FP_ATTRIB = NULL;
GLuint (*_glCreateShader) (GLenum type) FP_ATTRIB = NULL;
void (*_glCullFace) (GLenum mode) FP_ATTRIB = NULL;
void (*_glDeleteBuffers) (GLsizei n, const GLuint *buffers) FP_ATTRIB = NULL;
void (*_glDeleteFramebuffers) (GLsizei n, const GLuint *framebuffers) FP_ATTRIB = NULL;
void (*_glDeleteProgram) (GLuint program) FP_ATTRIB = NULL;
void (*_glDeleteRenderbuffers) (GLsizei n, const GLuint *renderbuffers) FP_ATTRIB = NULL;
void (*_glDeleteShader) (GLuint shader) FP_ATTRIB = NULL;
void (*_glDeleteTextures) (GLsizei n, const GLuint *textures) FP_ATTRIB = NULL;
void (*_glDepthFunc) (GLenum func) FP_ATTRIB = NULL;
void (*_glDepthMask) (GLboolean flag) FP_ATTRIB = NULL;
void (*_glDepthRangef) (GLfloat n, GLfloat f) FP_ATTRIB = NULL;
void (*_glDetachShader) (GLuint program, GLuint shader) FP_ATTRIB = NULL;
void (*_glDisable) (GLenum cap) FP_ATTRIB = NULL;
void (*_glDisableVertexAttribArray) (GLuint index) FP_ATTRIB = NULL;
void (*_glDrawArrays) (GLenum mode, GLint first, GLsizei count) FP_ATTRIB = NULL;
void (*_glDrawElements) (GLenum mode, GLsizei count, GLenum type, const void *indices) FP_ATTRIB = NULL;
void (*_glEnable) (GLenum cap) FP_ATTRIB = NULL;
void (*_glEnableVertexAttribArray) (GLuint index) FP_ATTRIB = NULL;
void (*_glFinish) (void) FP_ATTRIB = NULL;
void (*_glFlush) (void) FP_ATTRIB = NULL;
void (*_glFramebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) FP_ATTRIB = NULL;
void (*_glFramebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) FP_ATTRIB = NULL;
void (*_glFrontFace) (GLenum mode) FP_ATTRIB = NULL;
void (*_glGenBuffers) (GLsizei n, GLuint *buffers) FP_ATTRIB = NULL;
void (*_glGenerateMipmap) (GLenum target) FP_ATTRIB = NULL;
void (*_glGenFramebuffers) (GLsizei n, GLuint *framebuffers) FP_ATTRIB = NULL;
void (*_glGenRenderbuffers) (GLsizei n, GLuint *renderbuffers) FP_ATTRIB = NULL;
void (*_glGenTextures) (GLsizei n, GLuint *textures) FP_ATTRIB = NULL;
void (*_glGetActiveAttrib) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) FP_ATTRIB = NULL;
void (*_glGetActiveUniform) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) FP_ATTRIB = NULL;
void (*_glGetAttachedShaders) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) FP_ATTRIB = NULL;
GLint (*_glGetAttribLocation) (GLuint program, const GLchar *name) FP_ATTRIB = NULL;
void (*_glGetBooleanv) (GLenum pname, GLboolean *data) FP_ATTRIB = NULL;
void (*_glGetBufferParameteriv) (GLenum target, GLenum pname, GLint *params) FP_ATTRIB = NULL;
GLenum (*_glGetError) (void) FP_ATTRIB = NULL;
void (*_glGetFloatv) (GLenum pname, GLfloat *data) FP_ATTRIB = NULL;
void (*_glGetFramebufferAttachmentParameteriv) (GLenum target, GLenum attachment, GLenum pname, GLint *params) FP_ATTRIB = NULL;
void (*_glGetIntegerv) (GLenum pname, GLint *data) FP_ATTRIB = NULL;
void (*_glGetProgramiv) (GLuint program, GLenum pname, GLint *params) FP_ATTRIB = NULL;
void (*_glGetProgramInfoLog) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) FP_ATTRIB = NULL;
void (*_glGetRenderbufferParameteriv) (GLenum target, GLenum pname, GLint *params) FP_ATTRIB = NULL;
void (*_glGetShaderiv) (GLuint shader, GLenum pname, GLint *params) FP_ATTRIB = NULL;
void (*_glGetShaderInfoLog) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) FP_ATTRIB = NULL;
void (*_glGetShaderPrecisionFormat) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) FP_ATTRIB = NULL;
void (*_glGetShaderSource) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) FP_ATTRIB = NULL;
const GLubyte * (*_glGetString) (GLenum name) FP_ATTRIB = NULL;
void (*_glGetTexParameterfv) (GLenum target, GLenum pname, GLfloat *params) FP_ATTRIB = NULL;
void (*_glGetTexParameteriv) (GLenum target, GLenum pname, GLint *params) FP_ATTRIB = NULL;
void (*_glGetUniformfv) (GLuint program, GLint location, GLfloat *params) FP_ATTRIB = NULL;
void (*_glGetUniformiv) (GLuint program, GLint location, GLint *params) FP_ATTRIB = NULL;
GLint (*_glGetUniformLocation) (GLuint program, const GLchar *name) FP_ATTRIB = NULL;
void (*_glGetVertexAttribfv) (GLuint index, GLenum pname, GLfloat *params) FP_ATTRIB = NULL;
void (*_glGetVertexAttribiv) (GLuint index, GLenum pname, GLint *params) FP_ATTRIB = NULL;
void (*_glGetVertexAttribPointerv) (GLuint index, GLenum pname, void **pointer) FP_ATTRIB = NULL;
void (*_glHint) (GLenum target, GLenum mode) FP_ATTRIB = NULL;
GLboolean (*_glIsBuffer) (GLuint buffer) FP_ATTRIB = NULL;
GLboolean (*_glIsEnabled) (GLenum cap) FP_ATTRIB = NULL;
GLboolean (*_glIsFramebuffer) (GLuint framebuffer) FP_ATTRIB = NULL;
GLboolean (*_glIsProgram) (GLuint program) FP_ATTRIB = NULL;
GLboolean (*_glIsRenderbuffer) (GLuint renderbuffer) FP_ATTRIB = NULL;
GLboolean (*_glIsShader) (GLuint shader) FP_ATTRIB = NULL;
GLboolean (*_glIsTexture) (GLuint texture) FP_ATTRIB = NULL;
void (*_glLineWidth) (GLfloat width) FP_ATTRIB = NULL;
void (*_glLinkProgram) (GLuint program) FP_ATTRIB = NULL;
void (*_glPixelStorei) (GLenum pname, GLint param) FP_ATTRIB = NULL;
void (*_glPolygonOffset) (GLfloat factor, GLfloat units) FP_ATTRIB = NULL;
void (*_glReadPixels) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) FP_ATTRIB = NULL;
void (*_glReleaseShaderCompiler) (void) FP_ATTRIB = NULL;
void (*_glRenderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height) FP_ATTRIB = NULL;
void (*_glSampleCoverage) (GLfloat value, GLboolean invert) FP_ATTRIB = NULL;
void (*_glScissor) (GLint x, GLint y, GLsizei width, GLsizei height) FP_ATTRIB = NULL;
void (*_glShaderBinary) (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length) FP_ATTRIB = NULL;
void (*_glShaderSource) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) FP_ATTRIB = NULL;
void (*_glStencilFunc) (GLenum func, GLint ref, GLuint mask) FP_ATTRIB = NULL;
void (*_glStencilFuncSeparate) (GLenum face, GLenum func, GLint ref, GLuint mask) FP_ATTRIB = NULL;
void (*_glStencilMask) (GLuint mask) FP_ATTRIB = NULL;
void (*_glStencilMaskSeparate) (GLenum face, GLuint mask) FP_ATTRIB = NULL;
void (*_glStencilOp) (GLenum fail, GLenum zfail, GLenum zpass) FP_ATTRIB = NULL;
void (*_glStencilOpSeparate) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) FP_ATTRIB = NULL;
void (*_glTexImage2D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) FP_ATTRIB = NULL;
void (*_glTexParameterf) (GLenum target, GLenum pname, GLfloat param) FP_ATTRIB = NULL;
void (*_glTexParameterfv) (GLenum target, GLenum pname, const GLfloat *params) FP_ATTRIB = NULL;
void (*_glTexParameteri) (GLenum target, GLenum pname, GLint param) FP_ATTRIB = NULL;
void (*_glTexParameteriv) (GLenum target, GLenum pname, const GLint *params) FP_ATTRIB = NULL;
void (*_glTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) FP_ATTRIB = NULL;
void (*_glUniform1f) (GLint location, GLfloat v0) FP_ATTRIB = NULL;
void (*_glUniform1fv) (GLint location, GLsizei count, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glUniform1i) (GLint location, GLint v0) FP_ATTRIB = NULL;
void (*_glUniform1iv) (GLint location, GLsizei count, const GLint *value) FP_ATTRIB = NULL;
void (*_glUniform2f) (GLint location, GLfloat v0, GLfloat v1) FP_ATTRIB = NULL;
void (*_glUniform2fv) (GLint location, GLsizei count, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glUniform2i) (GLint location, GLint v0, GLint v1) FP_ATTRIB = NULL;
void (*_glUniform2iv) (GLint location, GLsizei count, const GLint *value) FP_ATTRIB = NULL;
void (*_glUniform3f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2) FP_ATTRIB = NULL;
void (*_glUniform3fv) (GLint location, GLsizei count, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glUniform3i) (GLint location, GLint v0, GLint v1, GLint v2) FP_ATTRIB = NULL;
void (*_glUniform3iv) (GLint location, GLsizei count, const GLint *value) FP_ATTRIB = NULL;
void (*_glUniform4f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) FP_ATTRIB = NULL;
void (*_glUniform4fv) (GLint location, GLsizei count, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glUniform4i) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3) FP_ATTRIB = NULL;
void (*_glUniform4iv) (GLint location, GLsizei count, const GLint *value) FP_ATTRIB = NULL;
void (*_glUniformMatrix2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glUniformMatrix3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glUniformMatrix4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glUseProgram) (GLuint program) FP_ATTRIB = NULL;
void (*_glValidateProgram) (GLuint program) FP_ATTRIB = NULL;
void (*_glVertexAttrib1f) (GLuint index, GLfloat x) FP_ATTRIB = NULL;
void (*_glVertexAttrib1fv) (GLuint index, const GLfloat *v) FP_ATTRIB = NULL;
void (*_glVertexAttrib2f) (GLuint index, GLfloat x, GLfloat y) FP_ATTRIB = NULL;
void (*_glVertexAttrib2fv) (GLuint index, const GLfloat *v) FP_ATTRIB = NULL;
void (*_glVertexAttrib3f) (GLuint index, GLfloat x, GLfloat y, GLfloat z) FP_ATTRIB = NULL;
void (*_glVertexAttrib3fv) (GLuint index, const GLfloat *v) FP_ATTRIB = NULL;
void (*_glVertexAttrib4f) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) FP_ATTRIB = NULL;
void (*_glVertexAttrib4fv) (GLuint index, const GLfloat *v) FP_ATTRIB = NULL;
void (*_glVertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) FP_ATTRIB = NULL;
void (*_glViewport) (GLint x, GLint y, GLsizei width, GLsizei height) FP_ATTRIB = NULL;
void (*_glReadBuffer) (GLenum src) FP_ATTRIB = NULL;
void (*_glDrawRangeElements) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) FP_ATTRIB = NULL;
void (*_glTexImage3D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) FP_ATTRIB = NULL;
void (*_glTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) FP_ATTRIB = NULL;
void (*_glCopyTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) FP_ATTRIB = NULL;
void (*_glCompressedTexImage3D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) FP_ATTRIB = NULL;
void (*_glCompressedTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) FP_ATTRIB = NULL;
void (*_glGenQueries) (GLsizei n, GLuint *ids) FP_ATTRIB = NULL;
void (*_glDeleteQueries) (GLsizei n, const GLuint *ids) FP_ATTRIB = NULL;
GLboolean (*_glIsQuery) (GLuint id) FP_ATTRIB = NULL;
void (*_glBeginQuery) (GLenum target, GLuint id) FP_ATTRIB = NULL;
void (*_glEndQuery) (GLenum target) FP_ATTRIB = NULL;
void (*_glGetQueryiv) (GLenum target, GLenum pname, GLint *params) FP_ATTRIB = NULL;
void (*_glGetQueryObjectuiv) (GLuint id, GLenum pname, GLuint *params) FP_ATTRIB = NULL;
GLboolean (*_glUnmapBuffer) (GLenum target) FP_ATTRIB = NULL;
void (*_glGetBufferPointerv) (GLenum target, GLenum pname, void **params) FP_ATTRIB = NULL;
void (*_glDrawBuffers) (GLsizei n, const GLenum *bufs) FP_ATTRIB = NULL;
void (*_glUniformMatrix2x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glUniformMatrix3x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glUniformMatrix2x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glUniformMatrix4x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glUniformMatrix3x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glUniformMatrix4x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glBlitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) FP_ATTRIB = NULL;
void (*_glRenderbufferStorageMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) FP_ATTRIB = NULL;
void (*_glFramebufferTextureLayer) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) FP_ATTRIB = NULL;
void *(*_glMapBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) FP_ATTRIB = NULL;
void (*_glFlushMappedBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length) FP_ATTRIB = NULL;
void (*_glBindVertexArray) (GLuint array) FP_ATTRIB = NULL;
void (*_glDeleteVertexArrays) (GLsizei n, const GLuint *arrays) FP_ATTRIB = NULL;
void (*_glGenVertexArrays) (GLsizei n, GLuint *arrays) FP_ATTRIB = NULL;
GLboolean (*_glIsVertexArray) (GLuint array) FP_ATTRIB = NULL;
void (*_glGetIntegeri_v) (GLenum target, GLuint index, GLint *data) FP_ATTRIB = NULL;
void (*_glBeginTransformFeedback) (GLenum primitiveMode) FP_ATTRIB = NULL;
void (*_glEndTransformFeedback) (void) FP_ATTRIB = NULL;
void (*_glBindBufferRange) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) FP_ATTRIB = NULL;
void (*_glBindBufferBase) (GLenum target, GLuint index, GLuint buffer) FP_ATTRIB = NULL;
void (*_glTransformFeedbackVaryings) (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) FP_ATTRIB = NULL;
void (*_glGetTransformFeedbackVarying) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) FP_ATTRIB = NULL;
void (*_glVertexAttribIPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) FP_ATTRIB = NULL;
void (*_glGetVertexAttribIiv) (GLuint index, GLenum pname, GLint *params) FP_ATTRIB = NULL;
void (*_glGetVertexAttribIuiv) (GLuint index, GLenum pname, GLuint *params) FP_ATTRIB = NULL;
void (*_glVertexAttribI4i) (GLuint index, GLint x, GLint y, GLint z, GLint w) FP_ATTRIB = NULL;
void (*_glVertexAttribI4ui) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) FP_ATTRIB = NULL;
void (*_glVertexAttribI4iv) (GLuint index, const GLint *v) FP_ATTRIB = NULL;
void (*_glVertexAttribI4uiv) (GLuint index, const GLuint *v) FP_ATTRIB = NULL;
void (*_glGetUniformuiv) (GLuint program, GLint location, GLuint *params) FP_ATTRIB = NULL;
GLint (*_glGetFragDataLocation) (GLuint program, const GLchar *name) FP_ATTRIB = NULL;
void (*_glUniform1ui) (GLint location, GLuint v0) FP_ATTRIB = NULL;
void (*_glUniform2ui) (GLint location, GLuint v0, GLuint v1) FP_ATTRIB = NULL;
void (*_glUniform3ui) (GLint location, GLuint v0, GLuint v1, GLuint v2) FP_ATTRIB = NULL;
void (*_glUniform4ui) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) FP_ATTRIB = NULL;
void (*_glUniform1uiv) (GLint location, GLsizei count, const GLuint *value) FP_ATTRIB = NULL;
void (*_glUniform2uiv) (GLint location, GLsizei count, const GLuint *value) FP_ATTRIB = NULL;
void (*_glUniform3uiv) (GLint location, GLsizei count, const GLuint *value) FP_ATTRIB = NULL;
void (*_glUniform4uiv) (GLint location, GLsizei count, const GLuint *value) FP_ATTRIB = NULL;
void (*_glClearBufferiv) (GLenum buffer, GLint drawbuffer, const GLint *value) FP_ATTRIB = NULL;
void (*_glClearBufferuiv) (GLenum buffer, GLint drawbuffer, const GLuint *value) FP_ATTRIB = NULL;
void (*_glClearBufferfv) (GLenum buffer, GLint drawbuffer, const GLfloat *value) FP_ATTRIB = NULL;
void (*_glClearBufferfi) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) FP_ATTRIB = NULL;
const GLubyte *(*_glGetStringi) (GLenum name, GLuint index) FP_ATTRIB = NULL;
void (*_glCopyBufferSubData) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) FP_ATTRIB = NULL;
void (*_glGetUniformIndices) (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) FP_ATTRIB = NULL;
void (*_glGetActiveUniformsiv) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) FP_ATTRIB = NULL;
GLuint (*_glGetUniformBlockIndex) (GLuint program, const GLchar *uniformBlockName) FP_ATTRIB = NULL;
void (*_glGetActiveUniformBlockiv) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) FP_ATTRIB = NULL;
void (*_glGetActiveUniformBlockName) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) FP_ATTRIB = NULL;
void (*_glUniformBlockBinding) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) FP_ATTRIB = NULL;
void (*_glDrawArraysInstanced) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount) FP_ATTRIB = NULL;
void (*_glDrawElementsInstanced) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) FP_ATTRIB = NULL;
GLsync (*_glFenceSync) (GLenum condition, GLbitfield flags) FP_ATTRIB = NULL;
GLboolean (*_glIsSync) (GLsync sync) FP_ATTRIB = NULL;
void (*_glDeleteSync) (GLsync sync) FP_ATTRIB = NULL;
GLenum (*_glClientWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout) FP_ATTRIB = NULL;
void (*_glWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout) FP_ATTRIB = NULL;
void (*_glGetInteger64v) (GLenum pname, GLint64 *data) FP_ATTRIB = NULL;
void (*_glGetSynciv) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) FP_ATTRIB = NULL;
void (*_glGetInteger64i_v) (GLenum target, GLuint index, GLint64 *data) FP_ATTRIB = NULL;
void (*_glGetBufferParameteri64v) (GLenum target, GLenum pname, GLint64 *params) FP_ATTRIB = NULL;
void (*_glGenSamplers) (GLsizei count, GLuint *samplers) FP_ATTRIB = NULL;
void (*_glDeleteSamplers) (GLsizei count, const GLuint *samplers) FP_ATTRIB = NULL;
GLboolean (*_glIsSampler) (GLuint sampler) FP_ATTRIB = NULL;
void (*_glBindSampler) (GLuint unit, GLuint sampler) FP_ATTRIB = NULL;
void (*_glSamplerParameteri) (GLuint sampler, GLenum pname, GLint param) FP_ATTRIB = NULL;
void (*_glSamplerParameteriv) (GLuint sampler, GLenum pname, const GLint *param) FP_ATTRIB = NULL;
void (*_glSamplerParameterf) (GLuint sampler, GLenum pname, GLfloat param) FP_ATTRIB = NULL;
void (*_glSamplerParameterfv) (GLuint sampler, GLenum pname, const GLfloat *param) FP_ATTRIB = NULL;
void (*_glGetSamplerParameteriv) (GLuint sampler, GLenum pname, GLint *params) FP_ATTRIB = NULL;
void (*_glGetSamplerParameterfv) (GLuint sampler, GLenum pname, GLfloat *params) FP_ATTRIB = NULL;
void (*_glVertexAttribDivisor) (GLuint index, GLuint divisor) FP_ATTRIB = NULL;
void (*_glBindTransformFeedback) (GLenum target, GLuint id) FP_ATTRIB = NULL;
void (*_glDeleteTransformFeedbacks) (GLsizei n, const GLuint *ids) FP_ATTRIB = NULL;
void (*_glGenTransformFeedbacks) (GLsizei n, GLuint *ids) FP_ATTRIB = NULL;
GLboolean (*_glIsTransformFeedback) (GLuint id) FP_ATTRIB = NULL;
void (*_glPauseTransformFeedback) (void) FP_ATTRIB = NULL;
void (*_glResumeTransformFeedback) (void) FP_ATTRIB = NULL;
void (*_glGetProgramBinary) (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) FP_ATTRIB = NULL;
void (*_glProgramBinary) (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) FP_ATTRIB = NULL;
void (*_glProgramParameteri) (GLuint program, GLenum pname, GLint value) FP_ATTRIB = NULL;
void (*_glInvalidateFramebuffer) (GLenum target, GLsizei numAttachments, const GLenum *attachments) FP_ATTRIB = NULL;
void (*_glInvalidateSubFramebuffer) (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) FP_ATTRIB = NULL;
void (*_glTexStorage2D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) FP_ATTRIB = NULL;
void (*_glTexStorage3D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) FP_ATTRIB = NULL;
void (*_glGetInternalformativ) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params) FP_ATTRIB = NULL;
void (*_glEGLImageTargetTexture2DOES) (GLenum target, GLeglImageOES image) FP_ATTRIB = NULL;

static void  __attribute__((constructor)) _init_androidglesv3()  {
    _libglesv3 = (void *) android_dlopen(getenv("LIBGLESV3") ? getenv("LIBGLESV3") : "libGLESv3.so", RTLD_NOW);

    GLES3_LOAD(glActiveTexture);
    GLES3_LOAD(glAttachShader);
    GLES3_LOAD(glBindAttribLocation);
    GLES3_LOAD(glBindBuffer);
    GLES3_LOAD(glBindFramebuffer);
    GLES3_LOAD(glBindRenderbuffer);
    GLES3_LOAD(glBindTexture);
    GLES3_LOAD(glBlendColor);
    GLES3_LOAD(glBlendEquation);
    GLES3_LOAD(glBlendEquationSeparate);
    GLES3_LOAD(glBlendFunc);
    GLES3_LOAD(glBlendFuncSeparate);
    GLES3_LOAD(glBufferData);
    GLES3_LOAD(glBufferSubData);
    GLES3_LOAD(glCheckFramebufferStatus);
    GLES3_LOAD(glClear);
    GLES3_LOAD(glClearColor);
    GLES3_LOAD(glClearDepthf);
    GLES3_LOAD(glClearStencil);
    GLES3_LOAD(glColorMask);
    GLES3_LOAD(glCompileShader);
    GLES3_LOAD(glCompressedTexImage2D);
    GLES3_LOAD(glCompressedTexSubImage2D);
    GLES3_LOAD(glCopyTexImage2D);
    GLES3_LOAD(glCopyTexSubImage2D);
    GLES3_LOAD(glCreateProgram);
    GLES3_LOAD(glCreateShader);
    GLES3_LOAD(glCullFace);
    GLES3_LOAD(glDeleteBuffers);
    GLES3_LOAD(glDeleteFramebuffers);
    GLES3_LOAD(glDeleteProgram);
    GLES3_LOAD(glDeleteRenderbuffers);
    GLES3_LOAD(glDeleteShader);
    GLES3_LOAD(glDeleteTextures);
    GLES3_LOAD(glDepthFunc);
    GLES3_LOAD(glDepthMask);
    GLES3_LOAD(glDepthRangef);
    GLES3_LOAD(glDetachShader);
    GLES3_LOAD(glDisable);
    GLES3_LOAD(glDisableVertexAttribArray);
    GLES3_LOAD(glDrawArrays);
    GLES3_LOAD(glDrawElements);
    GLES3_LOAD(glEnable);
    GLES3_LOAD(glEnableVertexAttribArray);
    GLES3_LOAD(glFinish);
    GLES3_LOAD(glFlush);
    GLES3_LOAD(glFramebufferRenderbuffer);
    GLES3_LOAD(glFramebufferTexture2D);
    GLES3_LOAD(glFrontFace);
    GLES3_LOAD(glGenBuffers);
    GLES3_LOAD(glGenerateMipmap);
    GLES3_LOAD(glGenFramebuffers);
    GLES3_LOAD(glGenRenderbuffers);
    GLES3_LOAD(glGenTextures);
    GLES3_LOAD(glGetActiveAttrib);
    GLES3_LOAD(glGetActiveUniform);
    GLES3_LOAD(glGetAttachedShaders);
    GLES3_LOAD(glGetAttribLocation);
    GLES3_LOAD(glGetBooleanv);
    GLES3_LOAD(glGetBufferParameteriv);
    GLES3_LOAD(glGetError);
    GLES3_LOAD(glGetFloatv);
    GLES3_LOAD(glGetFramebufferAttachmentParameteriv);
    GLES3_LOAD(glGetIntegerv);
    GLES3_LOAD(glGetProgramiv);
    GLES3_LOAD(glGetProgramInfoLog);
    GLES3_LOAD(glGetRenderbufferParameteriv);
    GLES3_LOAD(glGetShaderiv);
    GLES3_LOAD(glGetShaderInfoLog);
    GLES3_LOAD(glGetShaderPrecisionFormat);
    GLES3_LOAD(glGetShaderSource);
    GLES3_LOAD(glGetString);
    GLES3_LOAD(glGetTexParameterfv);
    GLES3_LOAD(glGetTexParameteriv);
    GLES3_LOAD(glGetUniformfv);
    GLES3_LOAD(glGetUniformiv);
    GLES3_LOAD(glGetUniformLocation);
    GLES3_LOAD(glGetVertexAttribfv);
    GLES3_LOAD(glGetVertexAttribiv);
    GLES3_LOAD(glGetVertexAttribPointerv);
    GLES3_LOAD(glHint);
    GLES3_LOAD(glIsBuffer);
    GLES3_LOAD(glIsEnabled);
    GLES3_LOAD(glIsFramebuffer);
    GLES3_LOAD(glIsProgram);
    GLES3_LOAD(glIsRenderbuffer);
    GLES3_LOAD(glIsShader);
    GLES3_LOAD(glIsTexture);
    GLES3_LOAD(glLineWidth);
    GLES3_LOAD(glLinkProgram);
    GLES3_LOAD(glPixelStorei);
    GLES3_LOAD(glPolygonOffset);
    GLES3_LOAD(glReadPixels);
    GLES3_LOAD(glReleaseShaderCompiler);
    GLES3_LOAD(glRenderbufferStorage);
    GLES3_LOAD(glSampleCoverage);
    GLES3_LOAD(glScissor);
    GLES3_LOAD(glShaderBinary);
    GLES3_LOAD(glShaderSource);
    GLES3_LOAD(glStencilFunc);
    GLES3_LOAD(glStencilFuncSeparate);
    GLES3_LOAD(glStencilMask);
    GLES3_LOAD(glStencilMaskSeparate);
    GLES3_LOAD(glStencilOp);
    GLES3_LOAD(glStencilOpSeparate);
    GLES3_LOAD(glTexImage2D);
    GLES3_LOAD(glTexParameterf);
    GLES3_LOAD(glTexParameterfv);
    GLES3_LOAD(glTexParameteri);
    GLES3_LOAD(glTexParameteriv);
    GLES3_LOAD(glTexSubImage2D);
    GLES3_LOAD(glUniform1f);
    GLES3_LOAD(glUniform1fv);
    GLES3_LOAD(glUniform1i);
    GLES3_LOAD(glUniform1iv);
    GLES3_LOAD(glUniform2f);
    GLES3_LOAD(glUniform2fv);
    GLES3_LOAD(glUniform2i);
    GLES3_LOAD(glUniform2iv);
    GLES3_LOAD(glUniform3f);
    GLES3_LOAD(glUniform3fv);
    GLES3_LOAD(glUniform3i);
    GLES3_LOAD(glUniform3iv);
    GLES3_LOAD(glUniform4f);
    GLES3_LOAD(glUniform4fv);
    GLES3_LOAD(glUniform4i);
    GLES3_LOAD(glUniform4iv);
    GLES3_LOAD(glUniformMatrix2fv);
    GLES3_LOAD(glUniformMatrix3fv);
    GLES3_LOAD(glUniformMatrix4fv);
    GLES3_LOAD(glUseProgram);
    GLES3_LOAD(glValidateProgram);
    GLES3_LOAD(glVertexAttrib1f);
    GLES3_LOAD(glVertexAttrib1fv);
    GLES3_LOAD(glVertexAttrib2f);
    GLES3_LOAD(glVertexAttrib2fv);
    GLES3_LOAD(glVertexAttrib3f);
    GLES3_LOAD(glVertexAttrib3fv);
    GLES3_LOAD(glVertexAttrib4f);
    GLES3_LOAD(glVertexAttrib4fv);
    GLES3_LOAD(glVertexAttribPointer);
    GLES3_LOAD(glViewport);
    GLES3_LOAD(glReadBuffer);
    GLES3_LOAD(glDrawRangeElements);
    GLES3_LOAD(glTexImage3D);
    GLES3_LOAD(glTexSubImage3D);
    GLES3_LOAD(glCopyTexSubImage3D);
    GLES3_LOAD(glCompressedTexImage3D);
    GLES3_LOAD(glCompressedTexSubImage3D);
    GLES3_LOAD(glGenQueries);
    GLES3_LOAD(glDeleteQueries);
    GLES3_LOAD(glIsQuery);
    GLES3_LOAD(glBeginQuery);
    GLES3_LOAD(glEndQuery);
    GLES3_LOAD(glGetQueryiv);
    GLES3_LOAD(glGetQueryObjectuiv);
    GLES3_LOAD(glUnmapBuffer);
    GLES3_LOAD(glGetBufferPointerv);
    GLES3_LOAD(glDrawBuffers);
    GLES3_LOAD(glUniformMatrix2x3fv);
    GLES3_LOAD(glUniformMatrix3x2fv);
    GLES3_LOAD(glUniformMatrix2x4fv);
    GLES3_LOAD(glUniformMatrix4x2fv);
    GLES3_LOAD(glUniformMatrix3x4fv);
    GLES3_LOAD(glUniformMatrix4x3fv);
    GLES3_LOAD(glBlitFramebuffer);
    GLES3_LOAD(glRenderbufferStorageMultisample);
    GLES3_LOAD(glFramebufferTextureLayer);
    GLES3_LOAD(glMapBufferRange);
    GLES3_LOAD(glFlushMappedBufferRange);
    GLES3_LOAD(glBindVertexArray);
    GLES3_LOAD(glDeleteVertexArrays);
    GLES3_LOAD(glGenVertexArrays);
    GLES3_LOAD(glIsVertexArray);
    GLES3_LOAD(glGetIntegeri_v);
    GLES3_LOAD(glBeginTransformFeedback);
    GLES3_LOAD(glEndTransformFeedback);
    GLES3_LOAD(glBindBufferRange);
    GLES3_LOAD(glBindBufferBase);
    GLES3_LOAD(glTransformFeedbackVaryings);
    GLES3_LOAD(glGetTransformFeedbackVarying);
    GLES3_LOAD(glVertexAttribIPointer);
    GLES3_LOAD(glGetVertexAttribIiv);
    GLES3_LOAD(glGetVertexAttribIuiv);
    GLES3_LOAD(glVertexAttribI4i);
    GLES3_LOAD(glVertexAttribI4ui);
    GLES3_LOAD(glVertexAttribI4iv);
    GLES3_LOAD(glVertexAttribI4uiv);
    GLES3_LOAD(glGetUniformuiv);
    GLES3_LOAD(glGetFragDataLocation);
    GLES3_LOAD(glUniform1ui);
    GLES3_LOAD(glUniform2ui);
    GLES3_LOAD(glUniform3ui);
    GLES3_LOAD(glUniform4ui);
    GLES3_LOAD(glUniform1uiv);
    GLES3_LOAD(glUniform2uiv);
    GLES3_LOAD(glUniform3uiv);
    GLES3_LOAD(glUniform4uiv);
    GLES3_LOAD(glClearBufferiv);
    GLES3_LOAD(glClearBufferuiv);
    GLES3_LOAD(glClearBufferfv);
    GLES3_LOAD(glClearBufferfi);
    GLES3_LOAD(glGetStringi);
    GLES3_LOAD(glCopyBufferSubData);
    GLES3_LOAD(glGetUniformIndices);
    GLES3_LOAD(glGetActiveUniformsiv);
    GLES3_LOAD(glGetUniformBlockIndex);
    GLES3_LOAD(glGetActiveUniformBlockiv);
    GLES3_LOAD(glGetActiveUniformBlockName);
    GLES3_LOAD(glUniformBlockBinding);
    GLES3_LOAD(glDrawArraysInstanced);
    GLES3_LOAD(glDrawElementsInstanced);
    GLES3_LOAD(glFenceSync);
    GLES3_LOAD(glIsSync);
    GLES3_LOAD(glDeleteSync);
    GLES3_LOAD(glClientWaitSync);
    GLES3_LOAD(glWaitSync);
    GLES3_LOAD(glGetInteger64v);
    GLES3_LOAD(glGetSynciv);
    GLES3_LOAD(glGetInteger64i_v);
    GLES3_LOAD(glGetBufferParameteri64v);
    GLES3_LOAD(glGenSamplers);
    GLES3_LOAD(glDeleteSamplers);
    GLES3_LOAD(glIsSampler);
    GLES3_LOAD(glBindSampler);
    GLES3_LOAD(glSamplerParameteri);
    GLES3_LOAD(glSamplerParameteriv);
    GLES3_LOAD(glSamplerParameterf);
    GLES3_LOAD(glSamplerParameterfv);
    GLES3_LOAD(glGetSamplerParameteriv);
    GLES3_LOAD(glGetSamplerParameterfv);
    GLES3_LOAD(glVertexAttribDivisor);
    GLES3_LOAD(glBindTransformFeedback);
    GLES3_LOAD(glDeleteTransformFeedbacks);
    GLES3_LOAD(glGenTransformFeedbacks);
    GLES3_LOAD(glIsTransformFeedback);
    GLES3_LOAD(glPauseTransformFeedback);
    GLES3_LOAD(glResumeTransformFeedback);
    GLES3_LOAD(glGetProgramBinary);
    GLES3_LOAD(glProgramBinary);
    GLES3_LOAD(glProgramParameteri);
    GLES3_LOAD(glInvalidateFramebuffer);
    GLES3_LOAD(glInvalidateSubFramebuffer);
    GLES3_LOAD(glTexStorage2D);
    GLES3_LOAD(glTexStorage3D);
    GLES3_LOAD(glGetInternalformativ);
    GLES3_LOAD(glEGLImageTargetTexture2DOES);
}

void glEGLImageTargetTexture2DOES(GLenum target, GLeglImageOES image)
{
    struct egl_image *img = image;
    return (*_glEGLImageTargetTexture2DOES)(target, img ? img->egl_image : NULL);
}

void glActiveTexture (GLenum texture) 
{
    _glActiveTexture(texture);
}


void glAttachShader (GLuint program, GLuint shader) 
{
    _glAttachShader(program, shader);
}


void glBindAttribLocation (GLuint program, GLuint index, const GLchar *name) 
{
    _glBindAttribLocation(program, index, name);
}


void glBindBuffer (GLenum target, GLuint buffer) 
{
    _glBindBuffer(target, buffer);
}


void glBindFramebuffer (GLenum target, GLuint framebuffer) 
{
    _glBindFramebuffer(target, framebuffer);
}


void glBindRenderbuffer (GLenum target, GLuint renderbuffer) 
{
    _glBindRenderbuffer(target, renderbuffer);
}


void glBindTexture (GLenum target, GLuint texture) 
{
    _glBindTexture(target, texture);
}


void glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) 
{
    _glBlendColor(red, green, blue, alpha);
}


void glBlendEquation (GLenum mode) 
{
    _glBlendEquation(mode);
}


void glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha) 
{
    _glBlendEquationSeparate(modeRGB, modeAlpha);
}


void glBlendFunc (GLenum sfactor, GLenum dfactor) 
{
    _glBlendFunc(sfactor, dfactor);
}


void glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) 
{
    _glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}


void glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage) 
{
    _glBufferData(target, size, data, usage);
}


void glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void *data) 
{
    _glBufferSubData(target, offset, size, data);
}


GLenum glCheckFramebufferStatus (GLenum target)
{
    return _glCheckFramebufferStatus(target);
}


void glClear (GLbitfield mask) 
{
    _glClear(mask);
}


void glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) 
{
    _glClearColor(red, green, blue, alpha);
}


void glClearDepthf (GLfloat d) 
{
    _glClearDepthf(d);
}


void glClearStencil (GLint s) 
{
    _glClearStencil(s);
}


void glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) 
{
    _glColorMask(red, green, blue, alpha);
}


void glCompileShader (GLuint shader) 
{
    _glCompileShader(shader);
}


void glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) 
{
    _glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}


void glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) 
{
    _glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}


void glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) 
{
    _glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}


void glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) 
{
    _glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}


GLuint glCreateProgram (void)
{
    return _glCreateProgram();
}


GLuint glCreateShader (GLenum type)
{
    return _glCreateShader(type);
}


void glCullFace (GLenum mode) 
{
    _glCullFace(mode);
}


void glDeleteBuffers (GLsizei n, const GLuint *buffers) 
{
    _glDeleteBuffers(n, buffers);
}


void glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers) 
{
    _glDeleteFramebuffers(n, framebuffers);
}


void glDeleteProgram (GLuint program) 
{
    _glDeleteProgram(program);
}


void glDeleteRenderbuffers (GLsizei n, const GLuint *renderbuffers) 
{
    _glDeleteRenderbuffers(n, renderbuffers);
}


void glDeleteShader (GLuint shader) 
{
    _glDeleteShader(shader);
}


void glDeleteTextures (GLsizei n, const GLuint *textures) 
{
    _glDeleteTextures(n, textures);
}


void glDepthFunc (GLenum func) 
{
    _glDepthFunc(func);
}


void glDepthMask (GLboolean flag) 
{
    _glDepthMask(flag);
}


void glDepthRangef (GLfloat n, GLfloat f) 
{
    _glDepthRangef(n, f);
}


void glDetachShader (GLuint program, GLuint shader) 
{
    _glDetachShader(program, shader);
}


void glDisable (GLenum cap) 
{
    _glDisable(cap);
}


void glDisableVertexAttribArray (GLuint index) 
{
    _glDisableVertexAttribArray(index);
}


void glDrawArrays (GLenum mode, GLint first, GLsizei count) 
{
    _glDrawArrays(mode, first, count);
}


void glDrawElements (GLenum mode, GLsizei count, GLenum type, const void *indices) 
{
    _glDrawElements(mode, count, type, indices);
}


void glEnable (GLenum cap) 
{
    _glEnable(cap);
}


void glEnableVertexAttribArray (GLuint index) 
{
    _glEnableVertexAttribArray(index);
}


void glFinish (void) 
{
    _glFinish();
}


void glFlush (void) 
{
    _glFlush();
}


void glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) 
{
    _glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}


void glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) 
{
    _glFramebufferTexture2D(target, attachment, textarget, texture, level);
}


void glFrontFace (GLenum mode) 
{
    _glFrontFace(mode);
}


void glGenBuffers (GLsizei n, GLuint *buffers) 
{
    _glGenBuffers(n, buffers);
}


void glGenerateMipmap (GLenum target) 
{
    _glGenerateMipmap(target);
}


void glGenFramebuffers (GLsizei n, GLuint *framebuffers) 
{
    _glGenFramebuffers(n, framebuffers);
}


void glGenRenderbuffers (GLsizei n, GLuint *renderbuffers) 
{
    _glGenRenderbuffers(n, renderbuffers);
}


void glGenTextures (GLsizei n, GLuint *textures) 
{
    _glGenTextures(n, textures);
}


void glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) 
{
    _glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}


void glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) 
{
    _glGetActiveUniform(program, index, bufSize, length, size, type, name);
}


void glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) 
{
    _glGetAttachedShaders(program, maxCount, count, shaders);
}


GLint glGetAttribLocation (GLuint program, const GLchar *name)
{
    return _glGetAttribLocation(program, name);
}


void glGetBooleanv (GLenum pname, GLboolean *data) 
{
    _glGetBooleanv(pname, data);
}


void glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params) 
{
    _glGetBufferParameteriv(target, pname, params);
}


GLenum glGetError (void)
{
    return _glGetError();
}


void glGetFloatv (GLenum pname, GLfloat *data) 
{
    _glGetFloatv(pname, data);
}


void glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params) 
{
    _glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}


void glGetIntegerv (GLenum pname, GLint *data) 
{
    _glGetIntegerv(pname, data);
}


void glGetProgramiv (GLuint program, GLenum pname, GLint *params) 
{
    _glGetProgramiv(program, pname, params);
}


void glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) 
{
    _glGetProgramInfoLog(program, bufSize, length, infoLog);
}


void glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params) 
{
    _glGetRenderbufferParameteriv(target, pname, params);
}


void glGetShaderiv (GLuint shader, GLenum pname, GLint *params) 
{
    _glGetShaderiv(shader, pname, params);
}


void glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) 
{
    _glGetShaderInfoLog(shader, bufSize, length, infoLog);
}


void glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) 
{
    _glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}


void glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) 
{
    _glGetShaderSource(shader, bufSize, length, source);
}


const GLubyte *glGetString (GLenum name)
{
    return _glGetString(name);
}

void glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params) 
{
    _glGetTexParameterfv(target, pname, params);
}


void glGetTexParameteriv (GLenum target, GLenum pname, GLint *params) 
{
    _glGetTexParameteriv(target, pname, params);
}


void glGetUniformfv (GLuint program, GLint location, GLfloat *params) 
{
    _glGetUniformfv(program, location, params);
}


void glGetUniformiv (GLuint program, GLint location, GLint *params) 
{
    _glGetUniformiv(program, location, params);
}


GLint glGetUniformLocation (GLuint program, const GLchar *name)
{
    return _glGetUniformLocation(program, name);
}


void glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params) 
{
    _glGetVertexAttribfv(index, pname, params);
}


void glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params) 
{
    _glGetVertexAttribiv(index, pname, params);
}


void glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer) 
{
    _glGetVertexAttribPointerv(index, pname, *pointer);
}


void glHint (GLenum target, GLenum mode) 
{
    _glHint(target, mode);
}


GLboolean glIsBuffer (GLuint buffer)
{
    return _glIsBuffer(buffer);
}


GLboolean glIsEnabled (GLenum cap)
{
    return _glIsEnabled(cap);
}


GLboolean glIsFramebuffer (GLuint framebuffer)
{
    return _glIsFramebuffer(framebuffer);
}


GLboolean glIsProgram (GLuint program)
{
    return _glIsProgram(program);
}


GLboolean glIsRenderbuffer (GLuint renderbuffer)
{
    return _glIsRenderbuffer(renderbuffer);
}


GLboolean glIsShader (GLuint shader)
{
    return _glIsShader(shader);
}


GLboolean glIsTexture (GLuint texture)
{
    return _glIsTexture(texture);
}


void glLineWidth (GLfloat width) 
{
    _glLineWidth(width);
}


void glLinkProgram (GLuint program) 
{
    _glLinkProgram(program);
}


void glPixelStorei (GLenum pname, GLint param) 
{
    _glPixelStorei(pname, param);
}


void glPolygonOffset (GLfloat factor, GLfloat units) 
{
    _glPolygonOffset(factor, units);
}


void glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) 
{
    _glReadPixels(x, y, width, height, format, type, pixels);
}


void glReleaseShaderCompiler (void) 
{
    _glReleaseShaderCompiler();
}


void glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height) 
{
    _glRenderbufferStorage(target, internalformat, width, height);
}


void glSampleCoverage (GLfloat value, GLboolean invert) 
{
    _glSampleCoverage(value, invert);
}


void glScissor (GLint x, GLint y, GLsizei width, GLsizei height) 
{
    _glScissor(x, y, width, height);
}


void glShaderBinary (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length) 
{
    _glShaderBinary(count, shaders, binaryformat, binary, length);
}


void glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) 
{
    _glShaderSource(shader, count, string, length);
}


void glStencilFunc (GLenum func, GLint ref, GLuint mask) 
{
    _glStencilFunc(func, ref, mask);
}


void glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask) 
{
    _glStencilFuncSeparate(face, func, ref, mask);
}


void glStencilMask (GLuint mask) 
{
    _glStencilMask(mask);
}


void glStencilMaskSeparate (GLenum face, GLuint mask) 
{
    _glStencilMaskSeparate(face, mask);
}


void glStencilOp (GLenum fail, GLenum zfail, GLenum zpass) 
{
    _glStencilOp(fail, zfail, zpass);
}


void glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) 
{
    _glStencilOpSeparate(face, sfail, dpfail, dppass);
}


void glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) 
{
    _glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}


void glTexParameterf (GLenum target, GLenum pname, GLfloat param) 
{
    _glTexParameterf(target, pname, param);
}


void glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params) 
{
    _glTexParameterfv(target, pname, params);
}


void glTexParameteri (GLenum target, GLenum pname, GLint param) 
{
    _glTexParameteri(target, pname, param);
}


void glTexParameteriv (GLenum target, GLenum pname, const GLint *params) 
{
    _glTexParameteriv(target, pname, params);
}


void glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) 
{
    _glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}


void glUniform1f (GLint location, GLfloat v0) 
{
    _glUniform1f(location, v0);
}


void glUniform1fv (GLint location, GLsizei count, const GLfloat *value) 
{
    _glUniform1fv(location, count, value);
}


void glUniform1i (GLint location, GLint v0) 
{
    _glUniform1i(location, v0);
}


void glUniform1iv (GLint location, GLsizei count, const GLint *value) 
{
    _glUniform1iv(location, count, value);
}


void glUniform2f (GLint location, GLfloat v0, GLfloat v1) 
{
    _glUniform2f(location, v0, v1);
}


void glUniform2fv (GLint location, GLsizei count, const GLfloat *value) 
{
    _glUniform2fv(location, count, value);
}


void glUniform2i (GLint location, GLint v0, GLint v1) 
{
    _glUniform2i(location, v0, v1);
}


void glUniform2iv (GLint location, GLsizei count, const GLint *value) 
{
    _glUniform2iv(location, count, value);
}


void glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2) 
{
    _glUniform3f(location, v0, v1, v2);
}


void glUniform3fv (GLint location, GLsizei count, const GLfloat *value) 
{
    _glUniform3fv(location, count, value);
}


void glUniform3i (GLint location, GLint v0, GLint v1, GLint v2) 
{
    _glUniform3i(location, v0, v1, v2);
}


void glUniform3iv (GLint location, GLsizei count, const GLint *value) 
{
    _glUniform3iv(location, count, value);
}


void glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) 
{
    _glUniform4f(location, v0, v1, v2, v3);
}


void glUniform4fv (GLint location, GLsizei count, const GLfloat *value) 
{
    _glUniform4fv(location, count, value);
}


void glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3) 
{
    _glUniform4i(location, v0, v1, v2, v3);
}


void glUniform4iv (GLint location, GLsizei count, const GLint *value) 
{
    _glUniform4iv(location, count, value);
}


void glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) 
{
    _glUniformMatrix2fv(location, count, transpose, value);
}


void glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) 
{
    _glUniformMatrix3fv(location, count, transpose, value);
}


void glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) 
{
    _glUniformMatrix4fv(location, count, transpose, value);
}


void glUseProgram (GLuint program) 
{
    _glUseProgram(program);
}


void glValidateProgram (GLuint program) 
{
    _glValidateProgram(program);
}


void glVertexAttrib1f (GLuint index, GLfloat x) 
{
    _glVertexAttrib1f(index, x);
}


void glVertexAttrib1fv (GLuint index, const GLfloat *v) 
{
    _glVertexAttrib1fv(index, v);
}


void glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y) 
{
    _glVertexAttrib2f(index, x, y);
}


void glVertexAttrib2fv (GLuint index, const GLfloat *v) 
{
    _glVertexAttrib2fv(index, v);
}


void glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z) 
{
    _glVertexAttrib3f(index, x, y, z);
}


void glVertexAttrib3fv (GLuint index, const GLfloat *v) 
{
    _glVertexAttrib3fv(index, v);
}


void glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) 
{
    _glVertexAttrib4f(index, x, y, z, w);
}


void glVertexAttrib4fv (GLuint index, const GLfloat *v) 
{
    _glVertexAttrib4fv(index, v);
}


void glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) 
{
    _glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}


void glViewport (GLint x, GLint y, GLsizei width, GLsizei height) 
{
    _glViewport(x, y, width, height);
}


void glReadBuffer (GLenum src) 
{
    _glReadBuffer(src);
}


void glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) 
{
    _glDrawRangeElements(mode, start, end, count, type, indices);
}


void glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) 
{
    _glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
}


void glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) 
{
    _glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}


void glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) 
{
    _glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}


void glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) 
{
    _glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
}


void glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) 
{
    _glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}


void glGenQueries (GLsizei n, GLuint *ids) 
{
    _glGenQueries(n, ids);
}


void glDeleteQueries (GLsizei n, const GLuint *ids) 
{
    _glDeleteQueries(n, ids);
}


GLboolean glIsQuery (GLuint id)
{
    return _glIsQuery(id);
}


void glBeginQuery (GLenum target, GLuint id) 
{
    _glBeginQuery(target, id);
}


void glEndQuery (GLenum target) 
{
    _glEndQuery(target);
}


void glGetQueryiv (GLenum target, GLenum pname, GLint *params) 
{
    _glGetQueryiv(target, pname, params);
}


void glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params) 
{
    _glGetQueryObjectuiv(id, pname, params);
}


GLboolean glUnmapBuffer (GLenum target)
{
    return _glUnmapBuffer(target);
}


void glGetBufferPointerv (GLenum target, GLenum pname, void **params) 
{
    _glGetBufferPointerv(target, pname, *params);
}


void glDrawBuffers (GLsizei n, const GLenum *bufs) 
{
    _glDrawBuffers(n, bufs);
}


void glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) 
{
    _glUniformMatrix2x3fv(location, count, transpose, value);
}


void glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) 
{
    _glUniformMatrix3x2fv(location, count, transpose, value);
}


void glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) 
{
    _glUniformMatrix2x4fv(location, count, transpose, value);
}


void glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) 
{
    _glUniformMatrix4x2fv(location, count, transpose, value);
}


void glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) 
{
    _glUniformMatrix3x4fv(location, count, transpose, value);
}


void glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) 
{
    _glUniformMatrix4x3fv(location, count, transpose, value);
}


void glBlitFramebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) 
{
    _glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}


void glRenderbufferStorageMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) 
{
    _glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
}


void glFramebufferTextureLayer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) 
{
    _glFramebufferTextureLayer(target, attachment, texture, level, layer);
}


void *glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
    return _glMapBufferRange(target, offset, length, access);
}

void glFlushMappedBufferRange (GLenum target, GLintptr offset, GLsizeiptr length) 
{
    _glFlushMappedBufferRange(target, offset, length);
}


void glBindVertexArray (GLuint array) 
{
    _glBindVertexArray(array);
}


void glDeleteVertexArrays (GLsizei n, const GLuint *arrays) 
{
    _glDeleteVertexArrays(n, arrays);
}


void glGenVertexArrays (GLsizei n, GLuint *arrays) 
{
    _glGenVertexArrays(n, arrays);
}


GLboolean glIsVertexArray (GLuint array)
{
    return _glIsVertexArray(array);
}


void glGetIntegeri_v (GLenum target, GLuint index, GLint *data) 
{
    _glGetIntegeri_v(target, index, data);
}


void glBeginTransformFeedback (GLenum primitiveMode) 
{
    _glBeginTransformFeedback(primitiveMode);
}


void glEndTransformFeedback (void) 
{
    _glEndTransformFeedback();
}


void glBindBufferRange (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) 
{
    _glBindBufferRange(target, index, buffer, offset, size);
}


void glBindBufferBase (GLenum target, GLuint index, GLuint buffer) 
{
    _glBindBufferBase(target, index, buffer);
}


void glTransformFeedbackVaryings (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) 
{
    _glTransformFeedbackVaryings(program, count, varyings, bufferMode);
}


void glGetTransformFeedbackVarying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) 
{
    _glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
}


void glVertexAttribIPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) 
{
    _glVertexAttribIPointer(index, size, type, stride, pointer);
}


void glGetVertexAttribIiv (GLuint index, GLenum pname, GLint *params) 
{
    _glGetVertexAttribIiv(index, pname, params);
}


void glGetVertexAttribIuiv (GLuint index, GLenum pname, GLuint *params) 
{
    _glGetVertexAttribIuiv(index, pname, params);
}


void glVertexAttribI4i (GLuint index, GLint x, GLint y, GLint z, GLint w) 
{
    _glVertexAttribI4i(index, x, y, z, w);
}


void glVertexAttribI4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) 
{
    _glVertexAttribI4ui(index, x, y, z, w);
}


void glVertexAttribI4iv (GLuint index, const GLint *v) 
{
    _glVertexAttribI4iv(index, v);
}


void glVertexAttribI4uiv (GLuint index, const GLuint *v) 
{
    _glVertexAttribI4uiv(index, v);
}


void glGetUniformuiv (GLuint program, GLint location, GLuint *params) 
{
    _glGetUniformuiv(program, location, params);
}


GLint glGetFragDataLocation (GLuint program, const GLchar *name)
{
    return _glGetFragDataLocation(program, name);
}


void glUniform1ui (GLint location, GLuint v0) 
{
    _glUniform1ui(location, v0);
}


void glUniform2ui (GLint location, GLuint v0, GLuint v1) 
{
    _glUniform2ui(location, v0, v1);
}


void glUniform3ui (GLint location, GLuint v0, GLuint v1, GLuint v2) 
{
    _glUniform3ui(location, v0, v1, v2);
}


void glUniform4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) 
{
    _glUniform4ui(location, v0, v1, v2, v3);
}


void glUniform1uiv (GLint location, GLsizei count, const GLuint *value) 
{
    _glUniform1uiv(location, count, value);
}


void glUniform2uiv (GLint location, GLsizei count, const GLuint *value) 
{
    _glUniform2uiv(location, count, value);
}


void glUniform3uiv (GLint location, GLsizei count, const GLuint *value) 
{
    _glUniform3uiv(location, count, value);
}


void glUniform4uiv (GLint location, GLsizei count, const GLuint *value) 
{
    _glUniform4uiv(location, count, value);
}


void glClearBufferiv (GLenum buffer, GLint drawbuffer, const GLint *value) 
{
    _glClearBufferiv(buffer, drawbuffer, value);
}


void glClearBufferuiv (GLenum buffer, GLint drawbuffer, const GLuint *value) 
{
    _glClearBufferuiv(buffer, drawbuffer, value);
}


void glClearBufferfv (GLenum buffer, GLint drawbuffer, const GLfloat *value) 
{
    _glClearBufferfv(buffer, drawbuffer, value);
}


void glClearBufferfi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) 
{
    _glClearBufferfi(buffer, drawbuffer, depth, stencil);
}


const GLubyte *glGetStringi (GLenum name, GLuint index)
{
    return _glGetStringi(name, index);
}

void glCopyBufferSubData (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) 
{
    _glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
}


void glGetUniformIndices (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) 
{
    _glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
}


void glGetActiveUniformsiv (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) 
{
    _glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
}


GLuint glGetUniformBlockIndex (GLuint program, const GLchar *uniformBlockName)
{
    return _glGetUniformBlockIndex(program, uniformBlockName);
}


void glGetActiveUniformBlockiv (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) 
{
    _glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
}


void glGetActiveUniformBlockName (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) 
{
    _glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}


void glUniformBlockBinding (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) 
{
    _glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}


void glDrawArraysInstanced (GLenum mode, GLint first, GLsizei count, GLsizei instancecount) 
{
    _glDrawArraysInstanced(mode, first, count, instancecount);
}


void glDrawElementsInstanced (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) 
{
    _glDrawElementsInstanced(mode, count, type, indices, instancecount);
}


GLsync glFenceSync (GLenum condition, GLbitfield flags)
{
    return _glFenceSync(condition, flags);
}


GLboolean glIsSync (GLsync sync)
{
    return _glIsSync(sync);
}


void glDeleteSync (GLsync sync) 
{
    _glDeleteSync(sync);
}


GLenum glClientWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout)
{
    return _glClientWaitSync(sync, flags, timeout);
}


void glWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout) 
{
    _glWaitSync(sync, flags, timeout);
}


void glGetInteger64v (GLenum pname, GLint64 *data) 
{
    _glGetInteger64v(pname, data);
}


void glGetSynciv (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) 
{
    _glGetSynciv(sync, pname, bufSize, length, values);
}


void glGetInteger64i_v (GLenum target, GLuint index, GLint64 *data) 
{
    _glGetInteger64i_v(target, index, data);
}


void glGetBufferParameteri64v (GLenum target, GLenum pname, GLint64 *params) 
{
    _glGetBufferParameteri64v(target, pname, params);
}


void glGenSamplers (GLsizei count, GLuint *samplers) 
{
    _glGenSamplers(count, samplers);
}


void glDeleteSamplers (GLsizei count, const GLuint *samplers) 
{
    _glDeleteSamplers(count, samplers);
}


GLboolean glIsSampler (GLuint sampler)
{
    return _glIsSampler(sampler);
}


void glBindSampler (GLuint unit, GLuint sampler) 
{
    _glBindSampler(unit, sampler);
}


void glSamplerParameteri (GLuint sampler, GLenum pname, GLint param) 
{
    _glSamplerParameteri(sampler, pname, param);
}


void glSamplerParameteriv (GLuint sampler, GLenum pname, const GLint *param) 
{
    _glSamplerParameteriv(sampler, pname, param);
}


void glSamplerParameterf (GLuint sampler, GLenum pname, GLfloat param) 
{
    _glSamplerParameterf(sampler, pname, param);
}


void glSamplerParameterfv (GLuint sampler, GLenum pname, const GLfloat *param) 
{
    _glSamplerParameterfv(sampler, pname, param);
}


void glGetSamplerParameteriv (GLuint sampler, GLenum pname, GLint *params) 
{
    _glGetSamplerParameteriv(sampler, pname, params);
}


void glGetSamplerParameterfv (GLuint sampler, GLenum pname, GLfloat *params) 
{
    _glGetSamplerParameterfv(sampler, pname, params);
}


void glVertexAttribDivisor (GLuint index, GLuint divisor) 
{
    _glVertexAttribDivisor(index, divisor);
}


void glBindTransformFeedback (GLenum target, GLuint id) 
{
    _glBindTransformFeedback(target, id);
}


void glDeleteTransformFeedbacks (GLsizei n, const GLuint *ids) 
{
    _glDeleteTransformFeedbacks(n, ids);
}


void glGenTransformFeedbacks (GLsizei n, GLuint *ids) 
{
    _glGenTransformFeedbacks(n, ids);
}


GLboolean glIsTransformFeedback (GLuint id)
{
    return _glIsTransformFeedback(id);
}


void glPauseTransformFeedback (void) 
{
    _glPauseTransformFeedback();
}


void glResumeTransformFeedback (void) 
{
    _glResumeTransformFeedback();
}


void glGetProgramBinary (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) 
{
    _glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
}


void glProgramBinary (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) 
{
    _glProgramBinary(program, binaryFormat, binary, length);
}


void glProgramParameteri (GLuint program, GLenum pname, GLint value) 
{
    _glProgramParameteri(program, pname, value);
}


void glInvalidateFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments) 
{
    _glInvalidateFramebuffer(target, numAttachments, attachments);
}


void glInvalidateSubFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) 
{
    _glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
}


void glTexStorage2D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) 
{
    _glTexStorage2D(target, levels, internalformat, width, height);
}


void glTexStorage3D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) 
{
    _glTexStorage3D(target, levels, internalformat, width, height, depth);
}


void glGetInternalformativ (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params) 
{
    _glGetInternalformativ(target, internalformat, pname, bufSize, params);
}

