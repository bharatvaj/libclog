#ifndef CLOG_H
#define CLOG_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#ifndef _CLOG_LOCK
#define _CLOG_LOCK
#endif
#ifndef _CLOG_UNLOCK
#define _CLOG_UNLOCK
#endif

static const short CLOG_INFO = 0;
static const short CLOG_WARN = 1;
static const short CLOG_ERROR = 2;
static const short CLOG_VERBOSE = 3;

extern FILE* clog_of_C7404000;
extern short clog_enable_C7404000;
extern const char* log_levels_C7404000[];

#ifdef CLOG_INIT
short clog_enable_C7404000 = 0;
FILE *clog_of_C7404000 = NULL;
const char *log_levels_C7404000[] = {"INFO", "WARN", "ERROR", "VERBOSE"};
#endif

static inline void clog_enable() {
	if(clog_of_C7404000 == NULL){
		clog_of_C7404000 = stderr;
	}
	clog_enable_C7404000 = 1;
}

static inline void clog_disable() {
	clog_enable_C7404000 = 0;
}

#define CLOG_ENSEMBLE_C7404000(__CLOG_LEVEL, __CLOG_FILE, __CLOG_LINE, ...)  \
	if (clog_enable_C7404000 == 1) { \
		_CLOG_LOCK \
		fprintf(clog_of_C7404000, "[%s] %s:%d: ", log_levels_C7404000[__CLOG_LEVEL], __CLOG_FILE, __CLOG_LINE); \
		fprintf(clog_of_C7404000, __VA_ARGS__); \
		fputs("\n", clog_of_C7404000); \
		_CLOG_UNLOCK \
	}

/*!
 * \brief - Change the destination for log messages
 * \param output_file - The FILE * to where the output will go to
 */
static inline void clog_out(FILE *output_file) { 
	clog_of_C7404000 = output_file;
}

#define CLOG_I(...) \
	CLOG_ENSEMBLE_C7404000(CLOG_INFO, __FILE__, __LINE__, __VA_ARGS__)

#define CLOG_W(...) \
	CLOG_ENSEMBLE_C7404000(CLOG_WARN, __FILE__, __LINE__, __VA_ARGS__)

#define CLOG_E(...) \
	CLOG_ENSEMBLE_C7404000(CLOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)

#define CLOG_V(...) \
	CLOG_ENSEMBLE_C7404000(CLOG_VERBOSE, __FILE__, __LINE__, __VA_ARGS__)

#ifdef __cplusplus
}
#endif
#endif
