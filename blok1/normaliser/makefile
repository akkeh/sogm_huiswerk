CC = g++
CFLAGS = -Wall
LIBS = -lsndfile

all: normalise

normalise: normalise.cpp
	g++ -c normalise.cpp -o $@.o ${CFLAGS} ${LIBS}
	g++ -o $@ $@.o ${CFLAGS} ${LIBS}

clean:
	rm -rf *.o


