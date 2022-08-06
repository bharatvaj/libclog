# clog version
VERSION = 0.0.6
PREFIX = /usr/local

# Customize below to fit your system

# paths
PREFIX = /usr/local

# flags
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=200809L -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}

INCS=-I.

CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os ${INCS} ${CPPFLAGS}

# compiler and linker
CC = cc
