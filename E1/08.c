#include <stdio.h>

void main() {
    int c=0;
    int b=0;
    int t=0;
    int n=0;
    while ((c = getchar()) != EOF){
        if (c == '\n'){
            ++n;
        }
        if (c == '\t'){
            ++t;
        }
        if (c == ' '){
            ++b;
        }
    }

    printf("Blanks: %d\nTabs: %d\nNew Lines: %d\n", b, t, n);

}
