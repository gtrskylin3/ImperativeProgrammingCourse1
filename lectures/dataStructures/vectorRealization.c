#include <stdio.h>
#include <stdlib.h>
#define TYPE int

typedef struct {
    TYPE* arr;
    int size;
    int cap;
} vector;

vector* init_vector(int capacity){
    vector* result = (vector*)malloc(sizeof(vector));
    result->arr = (TYPE*)malloc(capacity*sizeof(TYPE));
    result->cap = capacity;
    result->size = 0;
    return result;
}

void push_back(vector* vec, int elem){
    if (vec->size >= vec->cap){
        vec->cap *= 2;
        vec->arr = (TYPE*)realloc(vec->arr, vec->cap * sizeof(TYPE));
    }

    vec->arr[vec->size++] = elem;
}

int get_elem(vector* vec, int index){
    return  vec->arr[index];
}

int pop(vector* vec, int index){
    return vec->arr[--vec->size];
}

int main(){
    vector* vec = init_vector(10);
    for (int i = 0; i < 10; ++i){
        push_back(vec, i);
    }
    for (int i =0 ; i< 10; ++i){
        printf("%d\n", get_elem(vec, i));
    }
    for (int i = 0; i < 10; ++i){
        pop(vec, i);
    }
    printf("size %d\n", vec->size);
}