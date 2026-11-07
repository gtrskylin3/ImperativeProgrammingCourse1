#include <stdio.h>
#define SIZE 3000
typedef struct longNum
{
    int arr[SIZE];
} longNum;

int main(){
    int n;
    scanf("%d", &n);
    longNum a1 = {{0}};
    a1.arr[SIZE-1] = 1;
    int next = 0;
    for (int c = 2; c <= n; c++) {       
        for (int i = SIZE-1; i >= 0; --i){
            int mult = a1.arr[i] * c + next;
            if (mult > 9){
                a1.arr[i] = mult % 10;
                next = mult / 10;
            } else {
                a1.arr[i] = mult;
                next = 0;
            }
        }
    }
    int start =0;
    for (int i = 0; i < SIZE; ++i){
        if (a1.arr[i] != 0) start = 1;
        if (start) printf("%d", a1.arr[i]);
    }
}



// 1 * 2 * 3 * 4 * 5

// [0,0,0,0,0,1]
// [0,0,0,0,0,2]
// [0,0,0,0,0,6]
// [0,0,0,0,2,4]
// [0,0,0,0,2,0] 20 % 10 20 / 10 
// [0,0,0,1,2,0] 10 % 10 10 / 10