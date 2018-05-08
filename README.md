# clog
A simple yet fast and bare minimal asynchronous logging library for C

### Installation
On Linux/Unix systems including macOS, shared libraries can be built using the following commands
```sh
mkdir build
cd build
cmake ..
make
sudo make install
```


### Usage
#### Logging can be done by,
Include the header file, `#include<clog/clog.h>`
```c
const char *TAG = "TEST";
log_inf(TAG, "%s", "test"); // log info
log_war(TAG, "%s", "test"); // log warning
log_err(TAG, "%s", "test"); // log error
log_per(TAG, "%s", "test"); // similar to error but calls perror
log_fat(TAG, "%s", "test"); // log fatal errors
```

#### Debug and Production builds
clog by default prints to stderr but can be changed to print to any given `FILE *`. This includes the stdout, normal files, sockets, etc.
```c
#include <stdio.o>
...
FILE *fp = fopen("log.txt", "w");
clog_out(fp);
```