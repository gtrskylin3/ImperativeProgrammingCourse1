#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void push(int* st, int* size, int val){
    st[(*size)++] = val;
}

int pop(int* st, int* size){
    return st[--(*size)];
}


int main(){
    int n;
    scanf("%d", &n);
    int *stack = malloc(sizeof(int) * n);
    int *minStack = malloc(sizeof(int) * n);
    int *maxStack = malloc(sizeof(int) * n);
    int size = 0;
    int sizeMin = 0;
    int sizeMax = 0;
    for (int i =0 ; i < n; ++i){
        char buffer[5];
        int val;
        scanf("%s", buffer);
        if (strcmp(buffer, "push")==0){
            scanf(" %d", &val);
            if (sizeMin == 0 || val <= minStack[sizeMin -1]){
                push(minStack, &sizeMin, val);
            }
            if (sizeMax == 0 || val >= maxStack[sizeMax -1]){
                push(maxStack, &sizeMax, val);
            }
            push(stack, &size, val);
        }
        else if (strcmp(buffer, "pop")==0){
            int val = pop(stack, &size);
            if (sizeMin > 0 && val == minStack[sizeMin-1]){
                pop(minStack, &sizeMin);
            }
            if (sizeMax > 0 && val == maxStack[sizeMax-1]){
                pop(maxStack, &sizeMax);
            }
            printf("%d\n", val);
        }
        else if (strcmp(buffer, "max")==0){
            if (sizeMax > 0)
                printf("%d\n", maxStack[sizeMax-1]);
        }
        else if (strcmp(buffer, "min")==0){
            if (sizeMin > 0)
                printf("%d\n", minStack[sizeMin-1]);
        }

        
    }
    free(stack);
    free(minStack);
    free(maxStack);
}