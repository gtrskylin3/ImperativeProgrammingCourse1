#include <stdio.h>
#include <stdlib.h>

typedef struct list_t
{
    int value;
    struct list_t* next;
} list_t;


list_t* new_node(int value){
    list_t* res = malloc(sizeof(list_t));
    printf("alloc %p\n", res);
    res->value = value;
    res->next = NULL;
    return res;
}

void insert_after(list_t* cur, int value){
    list_t* node  = new_node(value);
    node->next = cur->next;
    cur->next = node;
}

void insert_head(list_t** head, int value){
    list_t* node = new_node(value);
    node->next = *head;
    *head = node;
}

int main() {
    list_t *head = NULL;
    insert_head(&head, 2);
    insert_head(&head, 3);
    list_t* x  = head->next->next;
    insert_after(x, 4);
    insert_after(x, 5);
    insert_after(x, 6);
    for (list_t* cur = head; cur; cur = cur->next){
        printf("%d\n", cur->value);
    }

    list_t* tmp_next = NULL;
    for (list_t* cur = head; cur; cur = tmp_next){
        tmp_next = cur->next;
        free(cur);
        printf("free %p\n", cur);
    }

}

