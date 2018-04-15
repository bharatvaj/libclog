#ifndef CLOG_H
#ifdef __cplusplus
extern "C" {
#endif
#define CLOG_H

#ifdef ENABLE_CLOG_CLOG_COLOR
#define CLOG_COLOR_RED     "\x1b[31m"
#define CLOG_COLOR_GREEN   "\x1b[32m"
#define CLOG_COLOR_YELLOW  "\x1b[33m"
#define CLOG_COLOR_BLUE    "\x1b[34m"
#define CLOG_COLOR_MAGENTA "\x1b[35m"
#define CLOG_COLOR_CYAN    "\x1b[36m"
#define CLOG_COLOR_RESET   "\x1b[0m"
#else
#define CLOG_COLOR_RED     ""
#define CLOG_COLOR_GREEN   ""
#define CLOG_COLOR_YELLOW  ""
#define CLOG_COLOR_BLUE    ""
#define CLOG_COLOR_MAGENTA ""
#define CLOG_COLOR_CYAN    ""
#define CLOG_COLOR_RESET   ""
#endif

void log_inf(const char *, const char *, ...);
void log_err(const char *, const char *, ...);
void log_per(const char *, const char *, ...);
void log_fat(const char *, const char *, ...);

#ifdef __cplusplus
}
#endif
#endif
