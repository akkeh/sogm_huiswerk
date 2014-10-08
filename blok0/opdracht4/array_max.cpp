#include <fstream>
#include <cstdlib>

//print grootste waarde in array
void print_max(int a[], int length) {
	int biggest = -1, index = -1;
	for(int i=0; i<length; i++) {
		if(a[i] > biggest) {
			biggest = a[i];
			index = i;
		}
	}
	printf("index: %i\t waarde: %i\n", index, biggest);
}

int main(int argc, const char* argv[]) {
	int length;
	int* a;
	if(argc < 2) {
		a = new int[5];
		printf("using random values\n");
		for(int i=0; i<5; i++) {
			a[i] = rand() % 10;
			printf("val: %i\n", a[i]);
		}
		length = 5;
	} else {
		a = new int[argc-1];
		for(int i=1; i<argc; i++) {
			a[i] = argv[i][0]-48;
		}
		length = argc-1;
	}
	print_max(a, length);
}
