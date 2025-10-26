#include <stdio.h>

int fn(int max, int mix, int count);

void main() {
	int MAX = 400;
	int MIX = -100;
	int COUNT = 20;
	fn(MAX, MIX, COUNT);
}

int fn(int max, int mix, int count) {
	printf(" Cel |  Fahr\n");
	printf("-----|------\n");
    for(float fahr = max; fahr >= mix; fahr -= count) {
        printf("%4.0f |%6.1f\n", fahr, (5.0/9.0)*(fahr - 39));
    }
	return 0;
}
