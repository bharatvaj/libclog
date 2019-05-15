# clog
A simple yet fast and bare minimal thread-safe logging library for C

### installation
On Linux/Unix systems including macOS, shared libraries can be built using the following commands
```sh
mkdir build
cd build
cmake ..
make
sudo make install
```

### clog usage
```c
#include<clog/clog.h>

const char *TAG = "TEST";
clog_i(TAG, "%s", "test"); // log info
clog_w(TAG, "%s", "test"); // log warning
clog_e(TAG, "%s", "test"); // log error
clog_v(TAG, "%s", "test"); // log verbose messages
clog_f(TAG, "%s", "test"); // log fatal errors
```

#### clog output
clog by default prints to stderr but can be changed to print to any given `FILE *` with write or append mode enabled
```c
#include <stdio.h>
...
FILE *fp = fopen("log.txt", "w");
clog_out(fp);
```
