#ifndef CLOG_H
#ifdef __cplusplus
extern "C" {
#endif
#define CLOG_H

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

void log_inf(const char *, const char *, ...);
void log_err(const char *, const char *, ...);
void log_per(const char *, const char *, ...);
void log_fat(const char *, const char *, ...);

#ifdef __cplusplus
}
#endif
#endif
