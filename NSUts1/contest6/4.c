#include <stdio.h>
#include <stdlib.h>

typedef struct list_s {
    int prev;
    int next;
    int value;
} list;

// Добавление спереди (тип 1)
void add_forward(list* arr, int idx, int new_value, int* first, int* last, int* size) {
    int new_idx = (*size)++;
    arr[new_idx].value = new_value;
    
    printf("%d\n", new_idx); // Выводим индекс нового узла

    if (idx == -1) {
        // Вставка в самый НАЧАЛО списка
        arr[new_idx].next = *first;
        arr[new_idx].prev = -1;
        if (*first != -1) {
            arr[*first].prev = new_idx;
        } else {
            // Если список был пустой, то новый элемент становится и последним тоже
            *last = new_idx;
        }
        *first = new_idx;
        return;   
    }

    int next_idx = arr[idx].next;
    arr[idx].next = new_idx;
    arr[new_idx].next = next_idx;
    arr[new_idx].prev = idx;
    
    if (next_idx != -1) {
        arr[next_idx].prev = new_idx;
    } else {
        // Если вставили после последнего элемента, обновляем last
        *last = new_idx;
    }
}

// Добавление сзади (тип -1)
void add_backward(list* arr, int idx, int new_value, int* first, int* last, int* size) {
    int new_idx = (*size)++;
    arr[new_idx].value = new_value;
    
    printf("%d\n", new_idx); // Выводим индекс нового узла

    if (idx == -1) {
        // Вставка в самый КОНЕЦ списка
        if (*last != -1) {
            arr[*last].next = new_idx;
        }
        arr[new_idx].prev = *last;
        arr[new_idx].next = -1;
        
        if (*first == -1) {
            // Если список был пустой
            *first = new_idx;
        }
        *last = new_idx;
        return;
    }

    int prev_idx = arr[idx].prev;
    arr[idx].prev = new_idx;
    arr[new_idx].next = idx;
    arr[new_idx].prev = prev_idx;
    
    if (prev_idx != -1) {
        arr[prev_idx].next = new_idx;
    } else {
        // Если вставили перед первым элементом, обновляем first
        *first = new_idx;
    }
}

// Удаление узла (тип 0)
void delete_node(list* arr, int idx, int* first, int* last) {
    printf("%d\n", arr[idx].value); // Выводим значение удаленного узла

    int prev_idx = arr[idx].prev;
    int next_idx = arr[idx].next;

    // Если удаляем голову
    if (prev_idx == -1) {
        *first = next_idx;
    } else {
        arr[prev_idx].next = next_idx;
    }

    // Если удаляем хвост
    if (next_idx == -1) {
        *last = prev_idx;
    } else {
        arr[next_idx].prev = prev_idx;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    if (scanf("%d", &t) != 1) return 0;
    
    for (int i = 0; i < t; ++i) {
        int n, first_idx, last_idx, operations;
        scanf("%d %d %d %d", &n, &first_idx, &last_idx, &operations);
        
        // Выделяем память с запасом под новые элементы
        list* arr = calloc(n + operations + 5, sizeof(list));
        int size = n;       
        
        if (!arr) {
            return 0;
        }
        
        for (int j = 0; j < n; ++j) {
            scanf("%d %d %d", &arr[j].value, &arr[j].next, &arr[j].prev);
        }
        
        // Обработка случая, когда изначально список пустой (n = 0, или F = -1, L = -1)
        if (n == 0) {
            first_idx = -1;
            last_idx = -1;
        }
        
        for (int o = 0; o < operations; ++o) {
            int type, idx;
            scanf("%d %d", &type, &idx);
            if (type != 0) {
                int new_value;
                scanf("%d", &new_value);
                if (type == 1) {
                    add_forward(arr, idx, new_value, &first_idx, &last_idx, &size);
                } else {
                    add_backward(arr, idx, new_value, &first_idx, &last_idx, &size);
                }
            } else {
                delete_node(arr, idx, &first_idx, &last_idx);
            }
        }
        
        printf("===\n");
        int curr = first_idx;
        while (curr != -1) {
            printf("%d\n", arr[curr].value);
            curr = arr[curr].next;
        }
        printf("===\n");
        
        free(arr);
    }
    return 0;
}