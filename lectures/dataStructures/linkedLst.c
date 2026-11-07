#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int value;
    struct node_s* next;
} node;

node* createNode(int value){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL){
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void pushFront(node** head, int value){
    node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void printList(node* head){
    for (node* current = head; current != NULL; current = current->next){
        printf("%d -> ", current->value);
    } 
    printf("NULL\n");    
}

void freeList(node* head){
    node* tmp;
    while (head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(){
    node* head = NULL;
    pushFront(&head, 1);
    pushFront(&head, 2);
    pushFront(&head, 3);
    printList(head);
    freeList(head);
}