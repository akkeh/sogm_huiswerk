DIR=temp

all: dir telop print_array array_max roteer_array

dir:
	mkdir -p ${DIR}

telop: optellen.cpp
	g++ -c optellen.cpp -o ${DIR}/$@.o	#creates $@.o file
	g++ -o $@ ${DIR}/$@.o			#creates exe from .o file 


print_array: print_array.cpp
	g++ -c print_array.cpp -o ${DIR}/$@.o
	g++ -o $@ ${DIR}/$@.o

array_max: array_max.cpp
	g++ -c array_max.cpp -o ${DIR}/$@.o
	g++ -o $@ ${DIR}/$@.o

roteer_array: roteer_array.cpp
	g++ -c roteer_array.cpp -o ${DIR}/$@.o
	g++ -o $@ ${DIR}/$@.o

clean:
	rm -f ${DIR}/*.o
