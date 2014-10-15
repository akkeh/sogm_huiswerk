DIR=temp

all: dir telop print_array array_max roteer_array

dir:
	mkdir -p ${DIR}

telop: optellen.cpp
	g++ -c optellen.cpp -o ${DIR}/optellen.o	#creates $@.o file
	g++ -o $@ ${DIR}/optellen.o			#creates exe from .o file 


print_array: print_array.cpp
	g++ -c print_array.cpp -o ${DIR}/print_array.o
	g++ -o $@ ${DIR}/print_array.o

array_max: array_max.cpp
	g++ -c array_max.cpp -o ${DIR}/array_max.o
	g++ -o $@ ${DIR}/array_max.o

roteer_array: roteer_array.cpp
	g++ -c roteer_array.cpp -o ${DIR}/roteer_array.o
	g++ -o $@ ${DIR}/roteer_array.o

clean:
	rm -f ${DIR}/*.o
