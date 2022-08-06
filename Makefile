# See LICENSE file for copyright and license details.

include config.mk


all: libclog.a

test: test_all

options:
	@echo clog build options:
	@echo "CFLAGS   = $(IICFLAGS)"
	@echo "LDFLAGS  = $(LDFLAGS)"
	@echo "CC       = $(CC)"

libclog.a: clog.o
	$(AR) cr $@ *.o

clog_test: test/test.c test/clog_functions.h test/long_message.h libclog.a
	$(CC) $< -I. -Itest -L. -lclog -o $@

install: all
	mkdir -p ${DESTDIR}${PREFIX}/lib
	cp -f libclog.a ${DESTDIR}${PREFIX}/lib
	chmod 755 ${DESTDIR}${PREFIX}/lib/libclog.a

test_all: clog_test
	./clog_test clog_functions
	./clog_test long_message

clean:
	rm -f libclog.a clog_test *.o
