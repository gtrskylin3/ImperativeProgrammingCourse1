#include <stdio.h>
#include <string.h>
#define SIZE 2008


typedef struct longNum_s
{
    int arr[SIZE];
} longNum;


longNum toLong(char* a){
    longNum s = {{0}};
    int j = 1;
    for (int i = strlen(a)-1; i >= 0; --i){
        s.arr[SIZE-j] = (int)(a[i] - '0');
        j++;
    }
    return s;
}



int main(){
    int a, b;
    char buffer1[1001];
    scanf("%s", buffer1);
    char buffer2[1001];
    scanf("%s", buffer2);
    int m = strcmp(buffer1, buffer2);
    longNum la, lb;
    lb = toLong(buffer1); 
    la = toLong(buffer2); 
    longNum result = {{0}};
    int  shift = 0;
    for (int i = SIZE-1; i >= 0; i--){ 
        int next = 0;
        for (int j = SIZE-1; j >= 0; j--){
            if (j - shift < 0){
                break;
            }
            int mult = result.arr[j-shift] + (la.arr[j] * lb.arr[i]) + next;
            if (mult > 9){
                result.arr[j-shift] = mult % 10;
                next = mult / 10;
            } else {
                result.arr[j-shift] = mult;
                next = 0;
            }
        }
        shift++;
    }

    int start =0;
    for (int i = 0; i < SIZE; ++i){
        if (result.arr[i] != 0) start = 1;
        if (start) printf("%d", result.arr[i]);
    }

}