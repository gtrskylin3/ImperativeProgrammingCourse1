#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

ListNode* addListNode(ListNode* l, int data){
    ListNode* t = (ListNode*)malloc(sizeof(ListNode));
    t->data = data;
    t->next = l;
    return t;
}

ListNode* delListNode(ListNode* ln, int data){
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* t = ln;
    while(t && (t->data != data)){
        prev = t;
        t = t->next;
    }
    if (!t) return ln;
    if (!prev){
        next = t->next;
        free(t);
        return next;
    } else {
        prev->next = t->next;
        free(t);
        return ln;
    }
}

void freeList(ListNode* ln){
    ListNode* t;
    while(ln) {
        t = ln->next;
        free(ln);
        ln = t;
    }
}


int main(){
    ListNode* ln = NULL;

    for (int i = 0; i < 10; ++i){
        ln = addListNode(ln, i);
    }

    ListNode* t = ln;
    while (t){
        printf("%d ", t->data);
        t = t->next;
    }
    
    printf("\n--------------------\n");

    ln = delListNode(ln, 0);
    t = ln;
    while (t){
        printf("%d ", t->data);
        t = t->next;
    }

    freeList(ln);
    
    return 0;
}