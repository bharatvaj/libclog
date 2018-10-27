#include <clog/clog.h>
#include <stdio.h>

static const char *TAG = "TEST";
int main(int argc, char *argv[]){
    clog_enable();
    log_inf(TAG, "Info function testing");
    log_war(TAG, "Warning function testing");
    log_err(TAG, "Error function testing");
    log_per(TAG, "Perror function testing");
    log_fat(TAG, "Fatal function testing");
    char *hostname = "localhost";
    int port = 7500;
    log_inf(TAG, "connection established successfully to %s on port %d", hostname, port);
    return 0;
}
