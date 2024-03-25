CFLAGS=	-W -g -Wall -Wextra -Werror -Wswitch-enum -ansi -pedantic

all: test

.c.o:
	${CC} ${CFLAGS} -c $<

test: test.o
	${CC} -o $@ $?

clean:
	rm -rf *.o *.core test

.PHONY: all clean