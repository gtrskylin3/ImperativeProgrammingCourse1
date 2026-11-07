#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArrayStringsByKey{
    int size;
    char** strings;
} arStringsByKey;
// структура которая храрнит размер и массив строк

int main (){
    int n;
    scanf("%d", &n);
    arStringsByKey* keys = calloc(1000001, sizeof(arStringsByKey));   
    // массив структур которые хранят размеры и массивы строк
    if (!keys){
        return -1;
    } 
    char buffer[7];
    // одна строка
    int key;
    for (int i= 0 ; i < n; ++i ){
        scanf("%d %s", &key, buffer);
        // сохраняеем ключ и строку
        keys[key].size++;
        keys[key].strings = realloc(keys[key].strings, keys[key].size * sizeof(char*));
        // выделяем память для строки по ключу в массиве строк по этому ключу
        if (!keys[key].strings)
            return -1;
        int last_idx = keys[key].size-1;
        keys[key].strings[last_idx] = malloc(7*sizeof(char));
        if (!keys[key].strings[last_idx])
            return -1;
        // сохраняем строку по ключу
        strcpy(keys[key].strings[last_idx], buffer);
    }
    
    for (int i = 0; i <= 1000000; ++i){
        if (keys[i].size > 0){
            for (int j = 0; j < keys[i].size; j++){
                printf("%d %s\n", i, keys[i].strings[j]);
            }
        }
    }
    
    for (int i = 0; i <= 1000000; ++i){
        if (keys[i].size > 0){
            for (int j = 0; j < keys[i].size; j++){
                free(keys[i].strings[j]);
            }
            free(keys[i].strings);
        }
    }
    
    free(keys);
}
