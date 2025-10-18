#include <stdio.h>

void main(){
    while (getchar() != EOF) {
        printf("%d\n", getchar() != EOF);
    }
    printf("\n%d\n", getchar() != EOF);
}
