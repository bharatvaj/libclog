#include <clog/clog.h>

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) && defined(__MACH__) //TODO Add Solaris
#include <unistd.h>
#include <pthread.h>
#define SEPARATOR ('/')
#elif _WIN32
#include <Windows.h>
#define SEPARATOR ('\\')
#else
#error Platform not supprted
#endif

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) && defined(__MACH__) //TODO Add Solaris
#define _CLOG_LOCK() pthread_mutex_lock(&__clog_lock);
#elif defined(_WIN32)
#define _CLOG_LOCK()
#endif

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) && defined(__MACH__) //TODO Add Solaris
#define _CLOG_UNLOCK() pthread_mutex_unlock(&__clog_lock);
#elif defined(_WIN32)
#define _CLOG_UNLOCK()
#endif

#if defined(ENABLE_CLOG)
#define _CLOG_LOG(__CLOG_LEVEL, __CLOG_FILE, __CLOG__LINE)     \
	{                                                          \
		char *str = (char *)malloc(strlen(msg));               \
		va_list vl;                                            \
		va_start(vl, msg);                                     \
		vsprintf(str, msg, vl);                                \
		clog_item *ci = (clog_item *)malloc(sizeof(clog_item)); \
		ci->level = __CLOG_LEVEL;                               \
		ci->tag = tag;                                         \
		ci->msg = str;                                         \
		add_to_stack(ci);                                        \
		va_end(vl);                                            \
	}
#else
#define _CLOG_LOG(__CLOG_LEVEL, __CLOG_FILE, __CLOG__LINE)
#endif

static FILE *__output_file = NULL;

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) && defined(__MACH__) //TODO Add Solaris
static pthread_mutex_t __clog_lock = PTHREAD_MUTEX_INITIALIZER;
#else
//windows locks
#endif

static char *log_levels[] = {
	"INFO",
	"WARN",
	"ERROR",
	"FATAL"};

void add_to_stack(clog_item *ci)
{
	_CLOG_LOCK();
	fprintf(stderr, "%s [%s] %s: %s\n", "", log_levels[ci->level], ci->tag, ci->msg);
	_CLOG_UNLOCK();
}

/*!
 * \brief - Changes the default printing socket
 * \param sockfd - The socket descriptor to write to
 */
void change_socket(FILE *output_file)
{
#ifdef ENABLE_CLOG
	__output_file = output_file;
#endif
}

void log_inf(const char *tag, const char *msg, ...)
{
	_CLOG_LOG(CLOG_INFO, __FILE__, __LINE__);
}

void log_war(const char *tag, const char *msg, ...)
{
	_CLOG_LOG(CLOG_WARN, __FILE__, __LINE__);
}

void log_err(const char *tag, const char *msg, ...)
{
	_CLOG_LOG(CLOG_ERROR, __FILE__, __LINE__);
}

void log_per(const char *tag, const char *msg, ...)
{
#ifdef ENABLE_CLOG
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	pthread_mutex_lock(&__clog_lock);
#endif
	char *str = (char *)malloc(strlen(msg));
	va_list vl;
	va_start(vl, msg);
	vsprintf(str, msg, vl);
	va_end(vl);
	perror(str);
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	pthread_mutex_unlock(&__clog_lock);
#endif
#endif
}

void log_fat(const char *tag, const char *msg, ...)
{
	_CLOG_LOG(CLOG_FATAL, __FILE__, __LINE__);
}
