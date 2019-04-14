# clog
A simple yet fast and bare minimal thread-safe logging library for C

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
clog_i(TAG, "%s", "test"); // log info
clog_w(TAG, "%s", "test"); // log warning
clog_e(TAG, "%s", "test"); // log error
clog_v(TAG, "%s", "test"); // log verbose messages
clog_f(TAG, "%s", "test"); // log fatal errors
```

#### Debug and Production builds
clog by default prints to stderr but can be changed to print to any given `FILE *`. This includes the stdout, normal files, sockets, etc.
```c
#include <stdio.h>
...
FILE *fp = fopen("log.txt", "w");
clog_out(fp);
```