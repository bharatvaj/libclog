#ifndef CLOG_H
#ifdef __cplusplus
extern "C" {
#endif
#define CLOG_H

#ifdef ENABLE_CLOG_COLOR
#define CLOG_COLOR_RED     "\x1b[31m"
#define CLOG_COLOR_GREEN   "\x1b[32m"
#define CLOG_COLOR_YELLOW  "\x1b[33m"
#define CLOG_COLOR_BLUE    "\x1b[34m"
#define CLOG_COLOR_MAGENTA "\x1b[35m"
#define CLOG_COLOR_CYAN    "\x1b[36m"
#define CLOG_COLOR_RESET   "\x1b[0m"
#endif


/*!
 * \brief - Log message as information
 * \param tag - The tag or context of the log
 * \param msg - The message to be printed
 */
void log_inf(const char *, const char *, ...);

/*!
 * \brief - Log message as warning
 * \param tag - The tag or context of the log
 * \param msg - The message to be printed
 */
void log_war(const char *, const char *, ...);

/*!
 * \brief - Log message as error
 * \param tag - The tag or context of the log
 * \param msg - The message to be printed
 */
void log_err(const char *, const char *, ...);

/*!
 * \brief - Log message as error but get error message from errno
 * \param tag - The tag or context of the log
 * \param msg - The message to be printed
 */
void log_per(const char *, const char *, ...);

/*!
 * \brief - Log message as fatal error
 * \param tag - The tag or context of the log
 * \param msg - The message to be printed
 */
void log_fat(const char *, const char *, ...);

#ifdef __cplusplus
}
#endif
#endif
