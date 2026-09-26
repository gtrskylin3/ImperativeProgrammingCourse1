#include <stdio.h>
#include <stdlib.h>
#define SIZE 10001


void bubbleSort(int arr[SIZE], int size){
    for (int i = 0 ; i < size - 1; i++){
        for (int j = 0 ; j < size - 1 - i; j++){
            if (arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }       
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[SIZE];
    for (int i = 0; i < n; ++i){
        int cur;
        scanf("%d", &cur);
        arr[i] = cur;
    }   
    bubbleSort(arr, n);
    for (int i = 0 ; i < n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}