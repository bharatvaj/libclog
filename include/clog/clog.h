#ifndef CLOG_H
#define CLOG_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

enum clog_level { CLOG_INFO, CLOG_WARN, CLOG_ERROR, CLOG_FATAL, CLOG_VERBOSE };

typedef struct {
  enum clog_level level;
  const char *tag;
  const char *msg;
} clog_item;

void clog_enable();

void clog_disable();

/*!
 * \brief - Change the destination for log messages
 * \param output_file - The FILE * to where the output will go to
 */
void clog_out(FILE *);

/*!
 * \brief - Log message as information
 * \param tag - The tag or context of the log
 * \param msg - The message to be printed
 */
void clog_i(const char *tag, const char *, ...);

/*!
 * \brief - Log message as warning
 * \param tag - The tag or context of the log
 * \param msg - The message to be printed
 */
void clog_w(const char *, const char *, ...);

/*!
 * \brief - Log message as error
 * \param tag - The tag or context of the log
 * \param msg - The message to be printed
 */
void clog_e(const char *, const char *, ...);

/*!
 * \brief - Log message as verbose
 * \param tag - The tag or context of the log
 * \param msg - The message to be printed
 */
void clog_v(const char *, const char *, ...);

/*!
 * \brief - Log message as fatal error
 * \param tag - The tag or context of the log
 * \param msg - The message to be printed
 */
void clog_f(const char *, const char *, ...);

#ifdef __cplusplus
}
#endif
#endif
