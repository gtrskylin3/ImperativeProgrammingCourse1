#include <stdio.h>
#include <stdlib.h>

// int main(){
//     unsigned char i = -1;
//     printf("%d", i);
// }

typedef struct list_t{
    int val;
    struct list_t* next;    
} list_t;

list_t* list_reverse(list_t* head){
    list_t* prev = NULL;
    list_t* next;
    // поменять 2 указателя next на prev и указтель следующей на текущую
    while (head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}


int main(){

    list_t* head = malloc(sizeof(list_t));
    head->val = 1;

    head->next = malloc(sizeof(list_t));
    head->next->val = 2;

    head->next->next = malloc(sizeof(list_t));
    head->next->next->val = 3;
    
    // ВАЖНО: последний элемент должен указывать на NULL
    head->next->next->next = NULL; 

    // Разворачиваем список
    list_t* new_head = list_reverse(head);

    while (new_head!=NULL){
        printf("%d ", new_head->val);
        new_head = new_head->next;
    }

} 