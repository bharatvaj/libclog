#include <clog/clog.h>
#include <stdio.h>

static const char *TAG = "TEST";
int main(int argc, char *argv[]){
    clog_enable();
    clog_i(TAG, "Info function testing");
    clog_w(TAG, "Warning function testing");
    clog_e(TAG, "Error function testing");
    clog_f(TAG, "Fatal function testing");
    clog_v(TAG, "Verbose function testing");
    char *hostname = "localhost";
    int port = 7500;
    clog_i(TAG, "connection established successfully to %s on port %d", hostname, port);
    //testing long texts
    return 0;
}
