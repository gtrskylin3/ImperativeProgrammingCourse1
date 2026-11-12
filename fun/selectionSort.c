#include <stdio.h>

void printArr(const int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n; ++i){
        int minIdx = i;
        for (int j = i+1; j < n; ++j){
            if (a[minIdx] > a[j]){
                minIdx = j;
            }
        }
        int tmp = a[i];
        a[i] = a[minIdx];
        a[minIdx] = tmp;
    }
}

int main(void) {
    int data[] = {29, 10, 14, 37, 13, 5};
    int n = sizeof(data) / sizeof(data[0]);
    printf("Before: ");
    printArr(data, n);
    selectionSort(data, n);
    printf("After:  ");
    printArr(data, n);
    return 0;
}