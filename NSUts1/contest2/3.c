#include <stdio.h>
#include <stdlib.h>
#define N_SIZE 10001

int main(){
    int n;
    scanf("%d", &n);
    int count_arr[N_SIZE] = {0};
    
    for (int i = 0; i < n; ++i){
        int cur;
        scanf("%d", &cur);
        count_arr[cur]++;
    }

    for (int i = 0; i < N_SIZE; ++i){
        if (count_arr[i] != 0){
            printf("%d: %d\n", i, count_arr[i]);
        }
    }
}