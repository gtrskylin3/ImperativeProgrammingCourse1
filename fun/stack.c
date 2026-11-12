#include <stdio.h>
#include <stdlib.h>


typedef struct top_obj{
    int data;
    struct top_obj* next;
} OBJ;

OBJ* push(OBJ* st, int val){
    OBJ* new = malloc(sizeof(OBJ));
    new->data = val;
    new->next = st;
    return new;
}

OBJ* pop(OBJ* st){
    if (st==NULL)
        return st;
    
    printf("Deleted top: %d\n", st->data);
    OBJ* ptr_next = st->next;
    free(st);
    return ptr_next;
}


int main(){
    OBJ* top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    return 0;
}