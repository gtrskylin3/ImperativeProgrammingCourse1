#include <stdio.h>
#define N 27

int arr[N];


int bubbleSort(int arr[],  int size){
    for (int i = 0; i < size - 1 ; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j+1] < arr[j]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp; 
            }
        }
    }
}

int find_diff(int size, int arr[]){
    for (int i = size-1; i > 0 ; i--){
        if (arr[i] > arr[i-1]){
            return i - 1;
        }
    }
}


int main(){
    int n;
    scanf("%d", &n);
    char cur; 
    for (int i = 0; i < n; ++i){
        scanf(" %c", &cur);
        arr[i] = (int)cur;
    }
    // нашли точку где можно получить больше
    int idx = find_diff(n, arr);
    // нужно поменять ее с меньшим из больших
    for (int i = n - 1; i > idx; i --){
        if (arr[i] > arr[idx]){
            int tmp = arr[idx];
            arr[idx] = arr[i];
            arr[i] = tmp;
            break;
        }
    }
    // сортируем все что после чтобы получить минимальный ответ
    int tail_size = n - idx - 1;
    bubbleSort(&arr[idx+1], tail_size);
    for (int i = 0; i < n; i++){
        printf("%c ", (char)arr[i]);
    }
}