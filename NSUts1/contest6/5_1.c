#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000001

typedef struct list_s{
    char string[8];
    struct list_s* next;
} list;


list* arr[SIZE] = {NULL};
int main(){
    int n;
    scanf("%d", &n);

    int key;
    
    for (int i = 0; i < n; ++i){
        scanf("%d", &key);
        list* newNode = malloc(sizeof(list));
        scanf("%s", newNode->string);
        newNode->next = NULL;
        if (arr[key]==NULL){
            arr[key] = newNode;
        } else {
            list* current = arr[key];
            while(current->next != NULL){
                current = current->next;
            }
            current->next = newNode;
        }
    }

    for (int i = 0; i < SIZE; i++){
        if (arr[i]!=NULL){
            list* current = arr[i];
            while(current != NULL){
                printf("%d %s\n", i, current->string);
                current = current->next;
            }
        }
    }

    for (int i = 0; i < SIZE; i++){
        list* current = arr[i];
        while(current != NULL){
            list* temp = current;
            current = current->next;
            free(temp);
        }
    }

}