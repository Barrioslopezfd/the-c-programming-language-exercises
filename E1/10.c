#include <stdio.h>

void main() {
    int c;
    while ((c = getchar()) != EOF){
        if (c == '\\'){
            printf("\\\\");
            continue;
        }
        if (c == '\t'){
            printf("\\t");
            continue;
        }
        if (c == ' '){
            printf("\\b");
            continue;
        }
        putchar(c);
    }
}

