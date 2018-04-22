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

int __n = 2;
static int *__writefd = &__n; //for different socket support

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) //TODO siblings
pthread_mutex_t _lock;
pthread_mutex_t plock;
#else
//windows locks
#endif
const void init_clog()
{
#ifdef ENABLE_CLOG
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	pthread_mutex_init(&_lock, NULL);
	pthread_mutex_init(&plock, NULL);
#else
//windows mutex init
#endif
#endif
}

/** Changes the default printing socket
 * @param sockfd The socket descriptor to write to
 */
void change_out_socket(int *sockfd)
{
#ifdef ENABLE_CLOG
	__writefd = sockfd;
#endif
}

void log_inf(const char *tag, const char *msg, ...)
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
	printf("[I] %s: %s\n", tag, str);
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	pthread_mutex_unlock(&_lock);
#endif
#endif
}

void log_war(const char *tag, const char *msg, ...)
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
	printf("%s[!]%s %s: %s\n", CLOG_COLOR_YELLOW, CLOG_COLOR_RESET, tag, str);
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	pthread_mutex_unlock(&_lock);
#endif
#endif
}

void log_err(const char *tag, const char *msg, ...)
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
	printf("[X] %s: %s\n", tag, str);
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	pthread_mutex_unlock(&_lock);
#endif
#endif
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
#ifdef ENABLE_CLOG
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	pthread_mutex_lock(&_lock);
#endif
	char *str = (char *)malloc(strlen(msg));
	va_list vl;
	va_start(vl, msg);
	vsprintf(str, msg, vl);
	va_end(vl);
	printf("[FATAL] %s: %s\n", tag, str);
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	pthread_mutex_unlock(&_lock);
#endif
#endif
}
