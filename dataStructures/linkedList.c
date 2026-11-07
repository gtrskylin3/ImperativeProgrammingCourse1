#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s{
    double value;
    struct Node_s* next;
} Node;


Node* initLinkedList(double var){
    Node* head = malloc(sizeof(Node));
    head->next = NULL;
    head->value = var;
    return head;
}

void addBackLinkedList(Node* head, double var){
    Node* newNode = initLinkedList(var);
    Node* current = head;
    while (current->next)
    {
        current = current->next;
    }
    
    current->next = newNode;
}
// addFront	Добавляет узел в начало
// addBack	Добавляет узел в конец
// removeFront	Удаляет первый узел
// removeBack

void addFrontLinkedList(Node** head, double var){
    Node* newNode = initLinkedList(var);
    newNode->next = *head;
    *head = newNode;
}

void removeFrontLinkedList(Node** head){
    Node* cur = *head;
    *head = (*head)->next;
    free(cur);
}

void removeBackLinkedList(Node* head){
    Node* current = head;
    Node* prev = NULL;
    while (current->next != NULL){
        prev = current;
        current=current->next;
    }
    prev->next = NULL;
}

void removeLinkedList(Node* head, double var){
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL && current->value != var)
    {
        prev = current;
        current = current->next;
    }
    if (current->value != var){
        return;
    }
    if(!current)
        return;

    prev->next = current->next;
}

void reveseLinkedList(Node** head){
    Node* prev = NULL;
    Node* cur  = *head;
    Node* next = NULL;

    while (cur){
        next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }
    *head = prev;
}

void printLinkedList(Node* head){
    Node* current = head;
    while(current->next){
        printf("%.2lf -> ", current->value);
        current = current->next;
    } 
    printf("%.2lf", current->value);
    
    printf("\n");
}


void destoryLinkedList(Node* head){
    free(head);
}

int main(){
    Node* head = initLinkedList(2);
    addBackLinkedList(head, 3);
    addBackLinkedList(head, 4);
    addBackLinkedList(head, 5);
    addFrontLinkedList(&head, 5);
    removeBackLinkedList(head);
    removeFrontLinkedList(&head);
    // reveseLinkedList(&head);
    printLinkedList(head);
    // removeLinkedList(head, 3);
    // printLinkedList(head);
    // destoryLinkedList(head);
}