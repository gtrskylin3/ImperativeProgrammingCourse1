#include <stdio.h>
#include <stdlib.h>
#define TYPE int

typedef struct {
    int* arr;
    int last;
} stack;

stack* init_stack(int capacity){
    stack* result = (stack*)malloc(sizeof(stack));
    result->arr = (TYPE*)malloc(capacity*sizeof(TYPE));
    result->last =0 ;
    return result;
}

void push_stack(stack* st, TYPE elem){
    st->arr[st->last++] = elem; 
}

TYPE pop_stack(stack* st){
    return st->arr[st->last--];
}

int main(){
    stack* st = init_stack(10);
    for (int i = 0; i < 10; ++i){
        push_stack(st, i+1);
    }
    for (int i = 0; i < 10; ++i){
        pop_stack(st);
        printf("%d\n", st->last);
    }
    
}