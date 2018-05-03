#include <clog/clog.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#if defined(__APPLE__) && defined(__MACH__) || defined(__linux__) //TODO add Unix and Solaris
#include <unistd.h>
#include <pthread.h>
#define SEPARATOR ('/')
#elif _WIN32
#include <Windows.h>
#define SEPARATOR ('\\')
#else
#error Platform not supprted
#endif

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#define _CLOG_LOCK() pthread_mutex_lock(&_lock);
#elif defined(_WIN32)
#define _CLOG_LOCK()
#endif

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#define _CLOG_UNLOCK() pthread_mutex_unlock(&_lock);
#elif defined(_WIN32)
#define _CLOG_UNLOCK()
#endif

#if defined(ENABLE_CLOG_COLOR)
#define _CLOG_PRINT(__CLOG_FORMAT, __CLOG__FORMAT_COLORED, __CLOG_COLOR) fprintf(stderr, __CLOG__FORMAT_COLORED, __CLOG_COLOR, CLOG_COLOR_RESET, tag, str);
#else
#define _CLOG_PRINT(__CLOG_FORMAT, __CLOG__FORMAT_COLORED, __CLOG_COLOR) fprintf(stderr, __CLOG_FORMAT, tag, str);
#endif

#if defined(ENABLE_CLOG)
#define _CLOG(__CLOG_FORMAT, __CLOG__FORMAT_COLORED, __CLOG_COLOR)        \
	{                                                                     \
		_CLOG_LOCK();                                                     \
		char *str = (char *)malloc(strlen(msg));                          \
		va_list vl;                                                       \
		va_start(vl, msg);                                                \
		vsprintf(str, msg, vl);                                           \
		va_end(vl);                                                       \
		_CLOG_PRINT(__CLOG_FORMAT, __CLOG__FORMAT_COLORED, __CLOG_COLOR); \
		_CLOG_UNLOCK();                                                   \
	}
#else
#define _CLOG(__CLOG_FORMAT, __CLOG__FORMAT_COLORED, __CLOG_COLOR)
#endif

static int __n = 2;
static int *__writefd = &__n; //for different socket support

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) //TODO siblings
static pthread_mutex_t _lock = PTHREAD_MUTEX_INITIALIZER;
#else
//windows locks
#endif

/*!
 * \brief - Changes the default printing socket
 * \param sockfd - The socket descriptor to write to
 */
void change_socket(int *sockfd)
{
#ifdef ENABLE_CLOG
	__writefd = sockfd;
#endif
}

void log_inf(const char *tag, const char *msg, ...)
{
	_CLOG("[I] %s: %s\n", "%s[I]%s %s: %s\n", CLOG_COLOR_YELLOW);
}

void log_war(const char *tag, const char *msg, ...)
{
	_CLOG("[!] %s: %s\n", "%s[!]%s %s: %s\n", CLOG_COLOR_MAGENTA);
}

void log_err(const char *tag, const char *msg, ...)
{
	_CLOG("[X] %s: %s\n", "%s[X]%s %s: %s\n", CLOG_COLOR_RED);
}

void log_per(const char *tag, const char *msg, ...)
{
#ifdef ENABLE_CLOG
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	pthread_mutex_lock(&_lock);
#endif
	char *str = (char *)malloc(strlen(msg));
	va_list vl;
	va_start(vl, msg);
	vsprintf(str, msg, vl);
	va_end(vl);
	perror(str);
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	pthread_mutex_unlock(&_lock);
#endif
#endif
}

void log_fat(const char *tag, const char *msg, ...)
{
	_CLOG("[FATAL] %s: %s\n", "%s[FATAL]%s %s: %s\n", CLOG_COLOR_RED);
}
