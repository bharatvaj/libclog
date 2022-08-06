#include <clog.h>

static const char *TAG = "TEST";
int clog_functions() {
    clog_i(TAG, "Info function testing");
    clog_w(TAG, "Warning function testing");
    clog_e(TAG, "Error function testing");
    clog_v(TAG, "Verbose function testing");
    char *hostname = "localhost";
    int port = 7500;
    clog_i(TAG, "connection established successfully to %s on port %d", hostname, port);
    //testing long texts
    return 0;
}
