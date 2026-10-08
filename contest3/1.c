#include <stdio.h>


void printTime(int* hours, int* minutes, int* seconds){
    printf("%02d:%02d:%02d\n", *hours, *minutes, *seconds);
}

int main(){
    int n, h, m, s; 
    scanf("%d", &n);
    
    for (int i =0 ; i < n; ++i){
        scanf("%d %d %d", &h, &m, &s);
        printTime(&h, &m, &s);
    }
}