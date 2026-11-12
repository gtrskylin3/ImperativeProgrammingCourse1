#include <stdio.h>
#include <stdlib.h>

#define SIZE (1000000000 + 7)
#define OPPERATIONS 3
// видим число кладем в стек 
// видим операцию достаем числа из стека 
// применяем операцию и возвращаем в стек


void push(long long* st, int* size, long long val){
    st[(*size)++] = val;
}

long long pop(long long* st, int* size){
    long long val = st[--(*size)];
    return val;
}

void make_operation(long long* stack, int* size, char opperation){
    long long val1, val2, res;
    switch (opperation)
    {
    case '+':
        val1 = pop(stack, size);
        val2 = pop(stack, size);
        res = (val2 + val1) % SIZE;
        push(stack, size, res);
        break;
    
    case '-':
        val1 = pop(stack, size);
        val2 = pop(stack, size);
        res = ((val2 - val1) % SIZE + SIZE) % SIZE;
        push(stack, size, res);
        break;
    
    case '*':
        val1 = pop(stack, size);
        val2 = pop(stack, size);
        res = (val2 * val1) % SIZE;
        push(stack, size, res);
        break;
    
    default:
        break;
    }
}



int main(){
    int n;
    int size = 0;
    scanf("%d", &n);
    getchar();
    long long *stack = malloc(sizeof(long long)*n);
    char opperands[] = {'+', '-', '*'};
    for (int i = 0; i < n; ++i){
        char buffer[20];
        scanf("%s", buffer);
        int is_operation = 0;
        for (int j = 0; j < OPPERATIONS; ++j){
            if (buffer[0] == opperands[j]){
                is_operation = 1;
                make_operation(stack, &size, opperands[j]);
                break;
            }
        }
        
        if(is_operation == 1){
            continue;
        }
        push(stack, &size, atoi(buffer));
    }
    printf("%lld\n", stack[size-1]);
    free(stack);
}   