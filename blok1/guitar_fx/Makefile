CC = g++
CFLAGS = -Wall
LIBS = -lasound

OBJ= guitarfx.o amp.o del.o play.o

all: guitarfx

guitarfx: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LIBS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o


