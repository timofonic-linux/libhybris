lib_LTLIBRARIES = \
	libsurfaceflinger.la

libsurfaceflinger_la_SOURCES = surfaceflinger.c
libsurfaceflinger_la_CFLAGS = -I$(top_srcdir)/include
if WANT_TRACE
libsurfaceflinger_la_CFLAGS += -DDEBUG
endif
if WANT_DEBUG
libsurfaceflinger_la_CFLAGS += -ggdb -O0
endif
libsurfaceflinger_la_LDFLAGS = \
	$(top_builddir)/common/libhybris-common.la \
	-version-info "1":"0":"0"

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libsurfaceflinger.pc
