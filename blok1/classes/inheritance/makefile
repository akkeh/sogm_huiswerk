CC = g++
CFLAGS = -Wall

OBJ = song.o playable_song.o song_main.o

all: main

main: ${OBJ}
	${CC} -o $@ ${CFLAGS} ${OBJ}

.cpp.p:
	${CC} -c $< ${CFLAGS}

clean:
	rm -rf *.o
	
	
