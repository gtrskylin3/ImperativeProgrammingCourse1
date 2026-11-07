#include <stdio.h>
#include <stdlib.h>

void createStr(int size, char*** arrOfStr, int* idx){
    (*arrOfStr)[*idx] = malloc(sizeof(char)*(size+1)); 
    if (!(*arrOfStr)[*idx])
        return;
    for (int i = 0; i < size; i++) {
        scanf(" %c", &(*arrOfStr)[*idx][i]);
    }
    (*arrOfStr)[*idx][size] = '\0';
    (*idx)++;
}

void removeStr(int idx, char** arrOfStr){
    if (arrOfStr[idx] != NULL) {
        free(arrOfStr[idx]);
        arrOfStr[idx] = NULL; 
    }
}

void printStr(int idx, char** arrOfStr){
     if (arrOfStr[idx] != NULL) {
        printf("%s\n", arrOfStr[idx]);
    }
}

void countInStr(int idx, char sym, char** arrOfStr){
    if (arrOfStr[idx] == NULL) return;
    int cnt = 0;
    for (int i = 0; arrOfStr[idx][i] != '\0'; ++i){
        if (arrOfStr[idx][i] == sym){
            cnt++;
        }
    }
    printf("%d\n", cnt);
}

void freeAll(char** arrOfStr, int arrSize){
    for (int i = 0; i < arrSize; ++i){
        if (arrOfStr[i]){
            free(arrOfStr[i]);
        }
    }
    free(arrOfStr);
}



int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int st = 0;
    char** stringStorage = calloc(n, sizeof(char*));
    if (stringStorage == NULL) {
        return 1;
    }
    for (int i = 0; i < n ; ++i){
        int t;
        scanf("%d", &t);
        int idx;
        int size; 
        char sym;
        switch (t){
            case 0:
                scanf("%d", &size);
                createStr(size, &stringStorage, &st);
                break;
            case 1:
                scanf("%d", &idx);
                removeStr(idx, stringStorage);
                break;
            case 2:
                scanf("%d", &idx);
                printStr(idx, stringStorage);
                break;
            case 3:
                scanf("%d %c", &idx, &sym);
                countInStr(idx, sym, stringStorage);
                break;
        }

    }
    freeAll(stringStorage, st);
    return 0;
}