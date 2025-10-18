#include <stdio.h>

#define BLANK ' '
#define NONBLANK 'a'

void main() {
    int cur_char, last_char;
    last_char = NONBLANK;

    while ((cur_char = getchar()) != EOF) {
        if (last_char == BLANK && cur_char == last_char) {
            continue;
        }
        last_char = cur_char;
        if (cur_char == BLANK) {
            printf("\n");
            continue;
        }
        putchar(cur_char);

    }
}
