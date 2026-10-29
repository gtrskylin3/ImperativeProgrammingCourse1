#include <stdio.h>
#include <stdlib.h>

typedef struct list_s{
    int prev;
    int next;
    int value;
} list;

int find_last_idx(list* arr, int first){
    int last_idx;
    while (first != -1){
        if (arr[first].next == -1){
            last_idx = first;
        }
        first = arr[first].next;
    }
    return last_idx;
}

void add_forward(list* arr, int idx, int new_value, int* first, int* size){
    (*size)++;
    int new_idx = (*size) - 1;
    arr[(*size)-1].value = new_value;
    printf("%d\n", (*size)-1);
    if (idx == -1){
        arr[*first].prev = (*size)-1;
        arr[(*size)-1].next = *first;   
        arr[(*size)-1].prev = -1;
        *first = (*size)-1;
        return;   
    }
    // [] -> []
    // |      |
    // [] ----
    // new = arr[(*size)-1];
    int next_idx = arr[idx].next;
    arr[idx].next = new_idx;
    arr[new_idx].next = next_idx;
    arr[new_idx].prev = idx;
    if (next_idx != -1) {
        arr[next_idx].prev = new_idx;
    }
}

void add_backward(list* arr, int idx, int new_value, int* last_idx, int* size){
    (*size)++;
    
    // [] <- []
    // |      |
    // |-----[]
    // new = arr[(*size)-1];
    int new_idx = (*size)++;
    arr[new_idx].value = new_value;
    printf("%d\n", (*size)-1);
    if (idx == -1){
        if (*last_idx != -1) {
            arr[*last_idx].next = new_idx;
        }
        arr[new_idx].prev = *last_idx;
        arr[new_idx].next = -1;
        *last_idx = new_idx;
        return;
    }
    
    int prev_idx = arr[idx].prev;
    arr[idx].prev = new_idx;
    arr[new_idx].next = idx;
    arr[new_idx].prev = prev_idx;
    if (prev_idx != -1) {
        arr[prev_idx].next = new_idx;
    }
}

void delete_node(list* arr, int idx, int* first){
    printf("%d\n", arr[idx].value);
    if (arr[idx].prev == -1){
        *first = arr[idx].next;
        if (*first != -1){
            arr[*first].prev = -1;
        }
        return;
    }
    
    int prev_idx = arr[idx].prev;
    int next_idx = arr[idx].next;

    arr[prev_idx].next = next_idx;
    if (next_idx != -1) {
        arr[next_idx].prev = prev_idx;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i){
        int n, print_idx, last_idx, operations;
        scanf("%d %d %d %d", &n, &print_idx, &last_idx, &operations);
        list* arr = calloc(n + operations, sizeof(list));
        int size = n;       
        if (!arr){
            return 0;
        }
        int last;
        for (int j = 0; j < n; ++j){
            //-1, если одного из них нет
            scanf("%d %d %d", &arr[j].value, &arr[j].next, &arr[j].prev);
        }
        
        for (int o = 0; o < operations; ++o){
            int type, idx;
            scanf("%d %d", &type, &idx);
            if (type != 0){
                int new_value;
                scanf("%d", &new_value);
                if (type == 1){
                    add_forward(arr, idx, new_value, &print_idx, &size);
                } else{
                    add_backward(arr, idx, new_value, &last_idx, &size);
                }
            } else {
                delete_node(arr, idx, &print_idx);
            }
        }
        printf("===\n");
        while (print_idx != -1){
            printf("%d\n", arr[print_idx].value);
            print_idx = arr[print_idx].next;
        }
        printf("===\n");
        free(arr);
    }
}