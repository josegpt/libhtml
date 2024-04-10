PREFIX?=	${DESTDIR}/usr/local
INCDIR=		${PREFIX}/include
LIBDIR=		${PREFIX}/lib

CFLAGS=		-W -g -Wall -Wextra -Werror -ansi -pedantic

all: libhtml.so libhtml.a

.c.o: libhtml.c
	${CC} ${CFLAGS} -c $?

libhtml.so: libhtml.c
	${CC} ${CFLAGS} -fPIC -shared -o $@ $?

libhtml.a: libhtml.o
	ar rcs libhtml.a libhtml.o

test: libhtml.o test.c
	${CC} ${CFLAGS} -o $@ $?

install: all
	mkdir -p ${INCDIR} ${LIBDIR}
	cp -p html.h ${INCDIR}
	cp -p libhtml.{so,a} ${LIBDIR}

uninstall:
	rm -rf ${INCDIR}/html.h ${LIBDIR}/libhtml.{so,a}

clean:
	rm -rf *.o *.a *.so *.gch *.core test

.PHONY: all install uninstall clean
