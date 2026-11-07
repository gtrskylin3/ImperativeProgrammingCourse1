#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* arr;
    int next, size, last, capacity;
} queue;

queue* init_queue(){
    queue* que = malloc(sizeof(queue));
    que->next = 0;
    que->last = 0;
    que->size = 0;
    que->capacity = 8;
    que->arr = malloc(sizeof(int) * que->capacity);
    return que;
}

void enqueue(queue* que, int val){
      if (que->last == que->capacity) {
        que->capacity *= 2;
        int* tmp = realloc(que->arr, sizeof(int) * que->capacity);
        if (!tmp) {
            fprintf(stderr, "Out of memory!\n");
            exit(EXIT_FAILURE);
        }
        que->arr = tmp;
    }
    
    que->size++;
    que->arr[que->last++] = val;
}

int dequeue(queue* que){
    que->size--;
    return que->arr[que->next++];
}

int main(){
    queue* que = init_queue();
    enqueue(que, 1);
    enqueue(que, 1);
    enqueue(que, 1);
    enqueue(que, 2);
    enqueue(que, 2);
    enqueue(que, 2);
    enqueue(que, 3);
    enqueue(que, 3);
    enqueue(que, 4);
    printf("%d\n", dequeue(que));
    printf("%d\n", dequeue(que));
    printf("%d\n", dequeue(que));
    printf("%d\n", dequeue(que));
    printf("%d\n", dequeue(que));
    printf("%d\n", dequeue(que));
    printf("%d\n", dequeue(que));
}


