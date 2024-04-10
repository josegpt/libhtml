CFLAGS=	-W -g -Wall -Wextra -Werror -ansi -pedantic

all: libhtml.so libhtml.so test

.c.o: libhtml.c
	${CC} ${CFLAGS} -c $?

libhtml.so: libhtml.c
	${CC} ${CFLAGS} -fPIC -shared -o $@ $?

libhtml.a: libhtml.o
	ar rcs libhtml.a libhtml.o

test: libhtml.o test.c
	${CC} ${CFLAGS} -o $@ $?

clean:
	rm -rf *.o *.a *.so *.gch *.core test

.PHONY: all clean
