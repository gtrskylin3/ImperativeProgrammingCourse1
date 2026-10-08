#include <stdio.h>
#include <stdlib.h>
#define TYPE int

typedef struct{
    TYPE* arr;
    int next, last;
} queue;

queue* init_vector(){
    queue* result = (queue*)malloc(sizeof(queue));
    result->arr = (TYPE*)malloc(sizeof(TYPE));
    return result;
}

void enqueue(queue* q, TYPE elem){
    q->arr[q->last++] = elem;
}
TYPE dequeue(queue* q, TYPE elem){
    return q->arr[q->next--];
}

int get_size(queue* q){
    return q->last - q->next;
}


int main(){
    
}