#include <fstream>

//optellen:
int telop(int a, int b) {
	return a+b;
}

int main(int argc, const char* argv[]) {
	int a, b;
	if(argc < 1) {
		a = 9; b = 6;
		printf("using %i and %i as values\n", a, b);
	} else {
		a = argv[1][0]-48;
		b = argv[2][0]-48;
	}
	printf("%i + %i = %i\n", a, b, telop(a, b));
}
