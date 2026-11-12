#include <stdio.h>
#include <stdlib.h>

typedef struct list_s{
    int val;
    struct list_s* next;
} list_t;


list_t* add(list_t* head, int val){
    list_t* new = malloc(sizeof(list_t));
    new->val = val;
    new->next = head;
    return new;
}

void printLinkedList(list_t* head){
    list_t* cur = head;
    while (cur){
        printf("%d ", cur->val);
        cur = cur->next;
    }    
}

list_t* reverse(list_t* head){
    
    list_t* prev = NULL;
    list_t* cur = head;
    list_t* next = NULL;

    while (cur){
        next = cur->next;
        cur->next = prev;
        prev = cur; 
        cur = next;
    }
    return prev;
}
list_t* reverse(list_t* head){
    
    list_t* prev = NULL;
    list_t* cur = head;
    list_t* next = NULL;

    while (cur){
        next = cur->next;
        cur->next = prev;
        prev = cur; 
        cur = next;
    }
    return prev;
}


int main(){
    list_t* head = NULL;
    head = add(head, 1);
    head = add(head, 2);
    head = add(head, 3);
    head = reverse(head);
    printLinkedList(head);

}


typedef struct stack_t{
    int data[10];
    int size;
} stack_t;

void push_stack(stack_t* st, int x){
}

int pop_stack(stack_t* st){
}

typedef struct queue_t{
    stack_t* st_in;
    stack_t* st_out;
}queue_t;

void enqueue(queue_t* que, int val){
    push_stack(que->st_in, val);
}

int dequeue(queue_t* que){
    if (!que->st_out){
        while (que->st_in){
            push_stack(que->st_out, pop_stack(que));
        }
    }
    return pop_stack(que->st_out);
}

bool empty(){
    
}