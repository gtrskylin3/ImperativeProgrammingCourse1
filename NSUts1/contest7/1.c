#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Item_s
{
    int idx;
    char** strings;
    int cap;
    int iter;
} Item;


int main(){
    int n;
    scanf("%d", &n);
    Item* arr = calloc(n, sizeof(Item));

    for (int i =0 ; i < n; ++i){
        arr[i].cap = -1;
        arr[i].cap = 0;
        arr[i].iter = 0;
        arr[i].strings = malloc(sizeof(char**)*arr[i].cap);
    }


    for (int i = 0; i < n; ++i){
        int idx = 0;
        scanf("%d", &idx);
        int current_cap = arr[idx].cap;
        arr[idx].cap++;
        char** tmp = realloc(arr[idx].strings, sizeof(char**)*arr[idx].cap);
        if (!tmp)
            return 0;
        arr[idx].strings = tmp;
        arr[idx].idx = idx;
        arr[idx].strings[current_cap] = malloc(7 * sizeof(char));
        scanf("%s", arr[idx].strings[current_cap]);
    }

     for (int i = 0 ; i < n ; ++i){
        if(arr[i].idx != -1){
            while (arr[i].iter < arr[i].cap) {
                printf("%d %s\n", arr[i].idx, arr[i].strings[arr[i].iter]);
                arr[i].iter++;
            }
        }
    }
    for (int i = 0 ; i < n ; ++i){
        if (arr[i].strings != NULL){
            for (int j = 0; j < arr[i].cap; ++j){
                free(arr[i].strings[j]);
            }
            free(arr[i].strings);
        }
    }
    free(arr);
}

