#ifndef CLOG_H
#define CLOG_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdarg.h>

#define CLOG_BUFFER_SIZE 64

#define _CLOG_LOCK
#define _CLOG_UNLOCK


static const short CLOG_INFO = 0;
static const short CLOG_WARN = 1;
static const short CLOG_ERROR = 2;
static const short CLOG_VERBOSE = 3;

extern FILE* clog_of;
extern short __clog_enable;
extern const char* log_levels[];

void clog_enable();

void clog_disable();

#define _CLOG_LOG(__CLOG_LEVEL, __CLOG_FILE, __CLOG_LINE)  \
  if (__clog_enable == 1) { \
    va_list vl;                                             \
    va_start(vl, msg);                                      \
    _CLOG_LOCK \
    fprintf(clog_of, "%s [%s] %s: ", "", log_levels[__CLOG_LEVEL], __CLOG_FILE); \
	vfprintf(clog_of, msg, vl); \
    fputs("\n", clog_of); \
    _CLOG_UNLOCK \
    va_end(vl);                                             \
  }

/*!
 * \brief - Change the destination for log messages
 * \param output_file - The FILE * to where the output will go to
 */
static inline void clog_out(FILE *output_file) { 
		clog_of = output_file;
}

/*!
 * \brief - Log message as fatal error
 * \param tag - The tag or context of the log
 * \param msg - The message to be printed
 */
static inline void clog_i(const char *tag, const char *msg, ...)
{
  _CLOG_LOG(CLOG_INFO, __FILE__, __LINE__);
}

static inline void clog_w(const char *tag, const char *msg, ...)
{
  _CLOG_LOG(CLOG_WARN, __FILE__, __LINE__);
}

static inline void clog_e(const char *tag, const char *msg, ...)
{
  _CLOG_LOG(CLOG_ERROR, __FILE__, __LINE__);
}

static inline void clog_v(const char *tag, const char *msg, ...)
{
    _CLOG_LOG(CLOG_ERROR, __FILE__, __LINE__);
}


#undef _CLOG_LOG
#ifdef __cplusplus
}
#endif
#endif
