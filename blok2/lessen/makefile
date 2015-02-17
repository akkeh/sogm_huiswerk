CC = g++
CFLAGS = -Wall
LIBS = -lpthread

OBJ= multithread.o

all: multithread

multithread: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LIBS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o


