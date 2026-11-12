#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int *arr = malloc(sizeof(int)*n);
    int left = 0;
    for (int i = 0; i < n; ++i){
        // int count = 0;
        scanf("%d", &arr[i]);
        // if (cur > m){
        //     min = cur - m;
        // }
        // arr[size++] = cur;
        // for (int j = 0; j < size; ++j){
        //     if (arr[j] >= min){
        //         count++;
        //     }
        // }
        while (arr[i] - arr[left] > m){
            left++;
        }
        printf("%d\n", i - left + 1);
    }

    free(arr);
}