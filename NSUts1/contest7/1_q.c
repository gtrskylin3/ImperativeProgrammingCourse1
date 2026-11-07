#include <stdio.h>
#include <stdlib.h>

typedef struct item_s 
{
    int idx;
    char** strings;
    int cnt;
} item;


void bubbleSort(item* list, int size){
    for (int i =0 ; i < size; ++i){
        for (int j = 0 ; j < size - i - 1; ++j){
            if (list[j].idx > list[j+1].idx){
                item tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            }
        }
    }
};

int main(){
    int n;
    scanf("%d", &n);
    item* arr = calloc(n, sizeof(item));

    for (int i = 0 ; i < n; ++i){
        scanf("%d", &arr[i].idx);
        int current_cap = arr[i].cnt;
        arr[i].cnt++;
        char** tmp = realloc(arr[i].strings, sizeof(char**)*arr[i].cnt);
        if (!tmp)
            return 0;
        arr[i].strings = tmp;
        arr[i].strings[current_cap] = malloc(8 * sizeof(char));
        scanf("%s", arr[i].strings[current_cap]);
    }

    bubbleSort(arr, n);

    for (int i= 0; i < n; ++i){
        int c = 0;
        while (c < arr[i].cnt){
            printf("%d %s\n", arr[i].idx, arr[i].strings[c]);
            c ++;
        } 
    }

    for (int i = 0; i < n; ++i){
        int c = 0;
        while (c < arr[i].cnt){
            free(arr[i].strings[c]);
            c++;
        }
        free(arr[i].strings); 
    }
    free(arr);
    return 0;
}