#include "clog_functions.h"
#include "long_message.h"
#include <string.h>
int main(int argc, char *argv[]){
  if(argc <= 1){
    return -1;
  }
  if(strcmp(argv[1], "clog_functions") == 0){
    return clog_functions();
  } else if(strcmp(argv[1], "long_message") == 0){
    return long_message();
  }
}
