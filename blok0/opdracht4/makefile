DIR=outp

all: dir telop print_array array_max roteer_array

dir:
	mkdir -p ${DIR}

telop: optellen.cpp
	g++ -c optellen.cpp -o ${DIR}/optellen.o
	g++ -o $@ optellen.o 


print_array: print_array.cpp
	g++ -c print_array.cpp -o ${DIR}/print_array.o
	g++ -o $@ print_array.o

array_max: array_max.cpp
	g++ -c array_max.cpp -o ${DIR}/array_max.o
	g++ -o $@ array_max.o

roteer_array: roteer_array.cpp
	g++ -c roteer_array.cpp -o 
	g++ -o $@ roteer_array.o
