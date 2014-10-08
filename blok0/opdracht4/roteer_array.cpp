#include <fstream>
#include <cstdlib>

//roteer array met 'stap'-stappen
int* roteer(const int a[], int length, int stap) {
	int* out = new int[length];
	for(int i=0; i<length; i++) {
		out[i] = a[(i+length+stap) % length];	//waarom i+length+stap: 
												//	-1 % x = -1
	}
	return out;
}


int main(int argc, const char* argv[]) {
	int length;
	int* a;
	int stap = 0;
	if(argc < 3) {
		a = new int[5];
		printf("using random values\n");
		for(int i=0; i<5; i++) {
			a[i] = rand() % 10;
			printf("val: %i\n", a[i]);
		}
		length = 5;
		stap = -1;
	} else {
		a = new int[argc];
		for(int i=0; i<argc-2; i++) {
			a[i] = argv[i+2][0]-48;
		}
		length = argc-2;
		stap = 1; //argv[1][0]-48;
	}
	int* b = roteer(a, length, stap);
	for(int i=0; i<length; i++) {
		printf("a: %i; b: %i\n", a[i], b[i]);
	}
}
