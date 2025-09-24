#include <stdio.h>

#define BLANK ' '
#define NONBLANK 'a'

void main() {
    int c, last_char;
    last_char = NONBLANK;

    while ((c = getchar()) != EOF) {
        if (last_char == BLANK && c == last_char) {
            continue;
        }
        last_char = c;
        if (c == BLANK) {
            printf("\n");
            continue;
        }
        putchar(c);

    }
}
