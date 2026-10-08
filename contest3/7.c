#include <stdio.h>
#define arrSize 127
int charArr[arrSize];

int main(){
    int c;
    while ((c = getchar()) != EOF){
        if (c >= 32 && c <= 126)
            charArr[c] ++;
    }

    for (int i =0 ; i < arrSize; ++i){
        if (charArr[i] > 0){
            printf("%c ", i);
            for (int j = 0; j < charArr[i]; ++j){
                printf("#");
            }
            printf("\n");
        }
    }
}