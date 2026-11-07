#include <stdio.h>

int main(void){
    // int arg;
    // int *p = &arg;
    // *p = 1;
    // printf("%d\n", *p);

    int ar[5] = {1,2,3,4,5};

    for (int i = 0; i < sizeof(ar)/sizeof(ar[0]); ++i){
        printf("%d\n", *(ar + i));
    }
}