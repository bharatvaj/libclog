#include <clog.h>

int clog_functions() {
	CLOG_I("Info function testing");
	CLOG_W("Warning function testing");
	CLOG_E("Error function testing");
	CLOG_V("Verbose function testing");
	const char *hostname = "localhost";
	int port = 7500;
	CLOG_I("connection established successfully to %s on port %d", hostname, port);
	return 0;
}
