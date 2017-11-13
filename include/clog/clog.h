#ifndef CLOG_H
#define CLOG_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#if defined(__APPLE__) && defined(__MACH__) || defined (__linux__) //TODO add Unix and Solaris
#include <unistd.h>
#include <pthread.h>
#define SEPARATOR ('/')
#elif _WIN32
#include <Windows.h>
#define SEPARATOR ('\\')
#else
#error Platform not supprted
#endif

#ifdef ENABLE_CLOG_COLOR
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"
#else
#define COLOR_RED     ""
#define COLOR_GREEN   ""
#define COLOR_YELLOW  ""
#define COLOR_BLUE    ""
#define COLOR_MAGENTA ""
#define COLOR_CYAN    ""
#define COLOR_RESET   ""
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 256
#endif

void log_inf(const char *, const char *, ...);
void log_err(const char *, const char *, ...);
void log_per(const char *, const char *, ...);
void log_fat(const char *, const char *, ...);

#endif
