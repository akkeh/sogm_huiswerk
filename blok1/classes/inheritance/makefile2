CC = g++
CFLAGS = -Wall

all: main

main: song_main.o song.o
	${CC} -o $@ ${CFLAGS} song_main.o song.o

song_main.o: song_main.cpp
	${CC} -c song_main.cpp -o song_main.o

song.o: song.cpp
	${CC} -c song.cpp -o song.o

clean:
	rm -rf *.o
	
	
