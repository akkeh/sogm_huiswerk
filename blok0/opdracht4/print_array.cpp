#include <fstream>
#include <cstdlib>

//print elementen array
void print_array(int a[], int length) {
	for(int i=0; i<(length); i++) {
		printf("%i:\t%i\n", i, a[i]);
	}
}

int main(int argc, const char* argv[]) {
	int length;
	int* a;
	if(argc < 2) {
		a = new int[5];
		printf("using random values\n");
		for(int i=0; i<5; i++) {
			a[i] = rand() % 5;
		}
		length = 5;
	} else {
		a = new int[argc-1];
		for(int i=1; i<argc; i++) {
			a[i] = argv[i][0]-48;
		}
		length = argc;
	}
	print_array(a, length);
}
