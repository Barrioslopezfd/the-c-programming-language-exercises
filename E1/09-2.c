#include <stdio.h>

void main() {
    int c;
    int b;
    while ((c = getchar()) != EOF) {
        if (!((b == ' ' || b == '	') && c == b)) {
			b = c;
			putchar(c);
        }
    }
}
