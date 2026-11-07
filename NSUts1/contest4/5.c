#include <stdio.h>
#include <string.h>
#define SIZE 500

typedef struct longNum_s {
    int len;
    int arr[SIZE];
} longNum;


int main(){
    int n; 
    scanf("%d", &n);
    int n1, n2;
    if (n <= 2){
        printf("1");
    }
    longNum fib1 = {1, {0}};
    fib1.arr[SIZE-1] = 1;
    longNum fib2 = {1, {0}};
    fib2.arr[SIZE-1] = 1;
    longNum fib3 = {1, {0}};
    for (int i = 2; i < n; ++i){
        int nextInc = 0;
        
        for (int i = SIZE-1; i >= 0; --i){
            int sum = fib1.arr[i] + fib2.arr[i];
            if (nextInc){
                fib3.arr[i]++;
                nextInc = 0;
                sum++;
            }
            if (sum > 9){
                nextInc = 1;      
                fib3.arr[i] = sum - 10;
            } else{
                fib3.arr[i] = sum;
            }

        }
        fib1 = fib2;
        fib2 = fib3;
    }
    int start =0;
    for (int i = 0; i < SIZE; ++i){
        if (fib3.arr[i] != 0) start = 1;
        if (start) printf("%d", fib3.arr[i]);
    }
}

