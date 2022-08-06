# See LICENSE file for copyright and license details.

include config.mk

SRC = clog.c

all: libclog.a

options:
	@echo clog build options:
	@echo "CFLAGS   = $(IICFLAGS)"
	@echo "LDFLAGS  = $(LDFLAGS)"
	@echo "CC       = $(CC)"

libclog.a: clog.o
	$(AR) cr $@ *.o

install: all
	mkdir -p ${DESTDIR}${PREFIX}/lib
	mkdir -p ${DESTDIR}${PREFIX}/include
	cp -f libclog.a ${DESTDIR}${PREFIX}/lib
	cp -f clog.h ${DESTDIR}${PREFIX}/include
	chmod 755 ${DESTDIR}${PREFIX}/lib/libclog.a

uninstall:
	rm -f ${DESTDIR}${PREFIX}/lib/libclog.a \
		${DESTDIR}${PREFIX}/include/clog.h

clog_test: test/test.c test/clog_functions.h test/long_message.h libclog.a
	$(CC) $< -I. -Itest -L. -lclog -o $@


test_clog_functions: clog_test
	./clog_test clog_functions

test_long_message: clog_test
	./clog_test long_message

test_all: test_clog_functions test_long_message

test: test_all

clean:
	rm -f libclog.a clog_test *.o

dist: clean
	mkdir -p libclog-${VERSION}
	cp -R LICENSE Makefile README config.mk \
		${SRC} clog.h test libclog-${VERSION}
	tar -cf libclog-${VERSION}.tar libclog-${VERSION}
	gzip libclog-${VERSION}.tar
	rm -rf libclog-${VERSION}
