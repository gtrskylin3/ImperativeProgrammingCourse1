#include <stdio.h>

// int main(void){
//     short ar[10];
//     short *ptr = ar;
//     short *p = &ar[3];

//     printf("ptr = %u, p = %u\n", ptr, p);
//     int res = p - ptr; // количество элементов между 2 указателями res = (p - ptr) / sizeof(short) = 3 имеет смысл при работе с одним массивом
//     printf("res = %d\n", res);
// }

int main(void){

    int g = 476789;
    char* ptr = (char *)&g;

    for (int i = 0; i < sizeof(int); ++i){
        printf("%d\n", *ptr++); // берется значение одной ячейки  // переходим на 1 байт потомучто char* 
    }
    
}