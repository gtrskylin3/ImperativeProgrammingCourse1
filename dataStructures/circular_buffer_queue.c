#include <stdio.h>
#include <stdlib.h>

typedef struct queue_s
{
    int* buffer;
    int size, head, tail, capacity;
} queue;

queue* init_queue(int capacity){
    queue* q = malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    q->capacity = capacity;
    q->buffer = malloc(sizeof(int)*q->capacity);
    return q;
}

void enqueue(queue* q, int val){
    if (q->size == q->capacity){
        int old_capacity = q->capacity;
        q->capacity*=2;
        int* new_buffer = malloc(sizeof(int) * q->capacity);
        if (!new_buffer) {
            fprintf(stderr, "Out of memory!\n");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < q->size; i++){
            new_buffer[i] = q->buffer[(q->tail + i) % old_capacity];
            printf("%d ", new_buffer[i]);
        }
        printf("\n");
        
        free(q->buffer);

        q->buffer = new_buffer;
        q->tail = 0;
        q->head = q->size;
    }
    q->buffer[q->head] = val;
    q->head = (q->head + 1) % q->capacity;
    q->size++;
}

int dequeue(queue* q){
    if (q->size == 0)
        return -1;
    int val = q->buffer[q->tail];
    q->tail = (q->tail + 1) % q->capacity;
    q->size--;
    return val;
}


int main(){
    queue* q = init_queue(3);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 67);
    enqueue(q, 67);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
}
