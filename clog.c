/* See LICENSE file for copyright and license details. */
#include <clog.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


short __clog_enable = 0;
FILE *clog_of = NULL;
const char *log_levels[] = {"INFO", "WARN", "ERROR", "FATAL", "VERBOSE"};


void clog_enable()
{
  if(clog_of == NULL){
    clog_of = stderr;
  }
  __clog_enable = 1;
}

void clog_disable(){
	__clog_enable = 0;
}

