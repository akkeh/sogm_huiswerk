CC = g++
CFLAGS = -Wall
LIBS = 

OBJ= main.o scheduler.o

all: tools

tools: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LIBS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o


