#CC-compiler:
CC=g++
CFLAGS = -Wall
CLIBS = -lasound
DIR=outp

OBJ = fir_analyse.o psplt/psplt.o play.o wavio.o

all: fir_analiser

fir_analiser: ${OBJ}
	${CC} -o $@ ${CFLAGS} ${OBJ} ${CLIBS}

.cpp.p:
	${CC} -c $< ${CFlAGS}

clean:
	rm -rf *.o
