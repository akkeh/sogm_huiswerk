#CC-compiler:
CC=g++
CFLAGS = -Wall

DIR=outp

OBJ =  iir.o wavio.o

all: test

test: ${OBJ}
	${CC} -o $@ ${CFLAGS} ${OBJ}

.cpp.p:
	${CC} -c $< ${CFlAGS}

clean:
	rm -rf *.o
