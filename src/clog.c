#ifndef CLOG_H
#define CLOG_H
#include <clog/clog.h>
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) //TODO siblings
#include<pthread.h>
#else
//Windows headers
#endif

int n = 2;
static int *writefd = &n; //for different socket support
static int is_debug = 0;

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) //TODO siblings
pthread_mutex_t _lock;
pthread_mutex_t plock;
#else
//windows locks
#endif
const void init_clog()
{
#ifdef CLOG_ENABLE
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
#ifdef CLOG_ENABLE
	writefd = sockfd;
#endif
}

void debug_mode(int val)
{
#ifdef CLOG_ENABLE
	is_debug = val;
#endif
}

void log_inf(const char *tag, const char *msg, ...)
{
#ifdef CLOG_ENABLE
	if(is_debug)
	{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		pthread_mutex_lock(&_lock);
#endif
		char *str = (char *)malloc(BUFFER_SIZE);
		va_list vl;
		va_start(vl, msg);
		vsprintf(str, msg, vl);
		va_end(vl);
		printf("%s[!]%s %s: %s\n", COLOR_YELLOW, COLOR_RESET, tag, str);
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		pthread_mutex_unlock(&_lock);
#endif
	}
#endif
}

void log_err(const char *tag, const char *msg, ...) 
{
#ifdef CLOG_ENABLE
	if(is_debug)
	{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		pthread_mutex_lock(&_lock);
#endif
		char *str = (char *)malloc(BUFFER_SIZE);
		va_list vl;
		va_start(vl, msg);
		vsprintf(str, msg, vl);
		va_end(vl);
		printf("[X] %s: %s\n", tag, str);
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		pthread_mutex_unlock(&_lock);
#endif
	}
#endif
}

void log_per(const char *tag, const char *msg, ...)
{
#ifdef CLOG_ENABLE
	if(is_debug)
	{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		pthread_mutex_lock(&_lock);
#endif
		char *str = (char *)malloc(BUFFER_SIZE);
		va_list vl;
		va_start(vl, msg);
		vsprintf(str, msg, vl);
		va_end(vl);
		perror(str);
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		pthread_mutex_unlock(&_lock);
#endif
	}
#endif
}

void log_fat(const char *tag, const char *msg, ...)
{
#ifdef CLOG_ENABLE
	if(is_debug)
	{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		pthread_mutex_lock(&_lock);
#endif
		char *str = (char *)malloc(BUFFER_SIZE);
		va_list vl;
		va_start(vl, msg);
		vsprintf(str, msg, vl);
		va_end(vl);
		printf("[FATAL] %s: %s\n", tag, str);
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		pthread_mutex_unlock(&_lock);
#endif
	}
#endif
}
#endif
