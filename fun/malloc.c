#include <stdio.h>
#include <stdlib.h>

short* append(short* arr, size_t* capacity, size_t* length, short value){
    if (*length >= *capacity){
        short *ar = realloc(arr, sizeof(short)*(*capacity)*2);
        if (!ar){
            return arr;
        }
        (*capacity)*=2;
    }
    arr[*length] = value;
    (*length)++; 
    return arr;
}


int main(){
    size_t capacity = 10;
    size_t length = 0;
    short* arr = malloc(sizeof(short)*capacity);

    for (int i = 0; i < 100; ++i){
        arr = append(arr, &capacity, &length, rand() % 40 - 20);
    }

    printf("length = %zu, capacity = %zu\n", length, capacity);

    for (int i = 0; i < 11; ++i){
        printf("%d ", arr[i]);
    }
    free(arr);
}