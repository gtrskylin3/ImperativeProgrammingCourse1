#include <stdio.h>
#include <stdlib.h>

typedef struct stack_s{
    int* data;
    int size;
    int capacity;
} stack;


stack* init_stack(){
    stack* new_stack = malloc(sizeof(stack));
    if (!new_stack)
        return NULL;
    new_stack->capacity = 8;
    new_stack->size = 0;
    new_stack->data = malloc(sizeof(int)*new_stack->capacity);
    if (!new_stack->data){
        free(new_stack);
        return NULL;
    }
    return new_stack;
}

void push(stack* st, int val){
    if (st->size == st->capacity){
        int new_cap = st->capacity*2;
        int* tmp = realloc(st->data, sizeof(int)*new_cap);
        if (!tmp){
            return;
        }
        st->data = tmp;
        st->capacity = new_cap;
    }
    st->data[st->size++] = val;
}

int pop(stack* st){
    if (st->size == 0){
        return -1;
    }
    return st->data[--st->size];
}

int top(stack* st){
    if (st->size == 0){
        return -1;
    }
    return st->data[st->size-1];
}

void stack_destroy(stack* st){
    free(st->data);
    free(st);
}


int main(){
    stack* new_stack = init_stack();
    if (!new_stack)
        return 1;
    push(new_stack, 1);
    push(new_stack, 2);
    push(new_stack, 3);
    printf("%d\n", pop(new_stack));
    printf("%d\n", pop(new_stack));
    printf("%d\n", pop(new_stack));

    stack_destroy(new_stack);
}