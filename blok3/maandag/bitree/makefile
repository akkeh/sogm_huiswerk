#CC-compiler:
CC=g++
CFLAGS = -Wall

DIR=outp

OBJ = bitree.o
all: sortnotes

sortnotes: ${OBJ}
	${CC} -o $@ ${CFLAGS} ${OBJ}

.cpp.p:
	${CC} -c $< ${CFlAGS}

clean:
	rm -rf *.o
