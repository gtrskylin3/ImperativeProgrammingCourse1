#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
    int value;
    struct Node_s* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = malloc(sizeof(MyLinkedList));
    obj->head = createNode(0);
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size){
        return -1;
    }
    Node* curr = obj->head->next;
    for (int i = 0; i < index; i ++){
        curr = curr->next;
    }
    return curr->value;
}
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) {
        return;
    }
    if (index < 0) {
        index = 0;
    }
    obj->size++;
    Node* curr = obj->head;
    for (int i = 0 ; i < index ; ++i){
        curr = curr->next;
    }
    Node* newNode = createNode(val);
    newNode->next = curr->next;
    curr->next = newNode;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, obj->size, val);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index > obj->size) {
        return;
    }
    if (index < 0) {
        index = 0;
    }
    Node* curr = obj->head;
    for (int i = 0 ; i < index ; i++){
        curr = curr->next;
    }
    Node* toDel = curr->next;
    curr->next = toDel->next;
    free(toDel);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    if (obj == NULL) return;
    Node* curr = obj->head;
    Node* tmp;
    while (curr != NULL){
        Node* tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    free(obj->head);
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

