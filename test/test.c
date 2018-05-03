#include <clog/clog.h>

#define TAG "TEST"
int main(int argc, char *argv[]){
    log_inf(TAG, "Info function testing");
    log_war(TAG, "Warning function testing");
    log_err(TAG, "Error function testing");
    log_per(TAG, "Perror function testing");
    log_fat(TAG, "Fatal function testing");
    return 0;
}