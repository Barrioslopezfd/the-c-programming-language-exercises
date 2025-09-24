#include <stdio.h>

void main() {
    int c;
    int b;
    while ((c = getchar()) != EOF) {
        if (b == ' ' && c == b) {
            continue;
        }
        b = c;
        putchar(c);
    }
}
