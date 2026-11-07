// левая и правая кодлоды по N перфокарт
// в левой от 1 до N
// в правой от -1 до -N

#include <stdio.h>
#include <stdlib.h>

typedef struct Deck_s
{
    int *arr;
    int size;
    int head;
    int capacity;
} Deck;


int take_top(Deck* d){
    int x = d->arr[d->head];
    d->head = (d->head+1) % d->capacity;
    d->size--;
    return x;
}

int take_bottom(Deck* d){
    int idx = (d->head + d->size - 1) % d->capacity;
    int x = d->arr[idx];
    d->size--;
    return x;
}

void put_top(Deck *d, int x) {
    d->head = (d->head - 1 + d->capacity) % d->capacity;
    d->arr[d->head] = x;
    d->size++;
}

void put_bottom(Deck *d, int x) {
    int idx = (d->head + d->size) % d->capacity;
    d->arr[idx] = x;
    d->size++;
}

void printResult(Deck* left, Deck* right){
    printf("%d ", left->size);
    for (int i = 0 ;  i < left->size; ++i){
        printf("%d ", left->arr[(left->head + i) % left->capacity]);
    }
    printf("\n%d ", right->size);
    for (int i = 0 ;  i < right->size; ++i){
        printf("%d ", right->arr[(right->head + i) % right->capacity]);
    }
}

char* to4bit(int dec){
    char* binDec = malloc(5*sizeof(char)) ;
    if (!binDec) return NULL;

    binDec[4] = '\0';
    for (int i = 3; i >= 0; i--){
        binDec[i] = (char)(dec % 2 + '0');
        dec /= 2;
    }
    return binDec;
}

void process_command(Deck *left, Deck *right, int take, int takeFrom, int put, int putTo){
    //    int take = 0; // 1-right 0-left 
    //     int takeFrom = 0; // 1-top 0-both 
    //     int put = 0; // 1-right 0-left 
    //     int putTo = 0; // 1-top 0-both 
    Deck *src = take ? right : left;
    Deck *dst = put ? right : left;
    
    if (src->size == 0){
        return;
    }
    
    
    int el;
    
    if (takeFrom == 1){
        el = take_top(src);
    } else {
        el = take_bottom(src);
    }
    if (putTo == 1){
        put_top(dst, el);
    } else {
        put_bottom(dst, el);
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    //команда - hex 0000 - 1111  
    Deck left;
    Deck right;
    left.capacity = right.capacity = 2 * n + 1;
    left.head = right.head = 0;
    left.size = right.size = n;
    left.arr = malloc(sizeof(int) * left.capacity);
    right.arr = malloc(sizeof(int) * right.capacity);
    for (int i = 1; i <= n; ++i){
        left.arr[i-1] = i;
        right.arr[i-1] = -i;
    }
    if (m == 0){
        printResult(&left, &right);
        free(left.arr);
        free(right.arr);
        return 0;
    }

    char* binDec;
    char command;
    for (int i = 0; i < m; ++i) {
        scanf(" %c", &command);
        int decHex;
        if (command >= 'A' && command <= 'F'){
            decHex = (int)(command-'A'+10);
        } else {
            decHex = (int)(command - '0');
        }
        binDec = to4bit(decHex);
        int take = 0; // 1-right 0-left 
        int takeFrom = 0; // 1-top 0-both 
        int put = 0; // 1-right 0-left 
        int putTo = 0; // 1-top 0-both 
        if (binDec[0] == '1'){
            take = 1;
        } else {
            take = 0;
        }
        if (binDec[1] == '1'){
            takeFrom = 0;
        } else {
            takeFrom = 1;
        }
        if (binDec[2] == '1'){
            put = 1;
        } else {
            put = 0;
        }
        if (binDec[3] == '1'){
            putTo = 0;
        } else {
            putTo = 1;
        }
        process_command(&left, &right, take, takeFrom, put, putTo);
        free(binDec);
    }
    
    printResult(&left, &right);
    free(left.arr);
    free(right.arr);
    return 0;
}