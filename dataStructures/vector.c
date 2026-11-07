#include <stdio.h>
#include <stdlib.h>


typedef struct vector_s{
    int* arr;
    int size;
    int capacity;
} vector;

vector init_vector(){
    vector new_v;
    new_v.capacity = 4;
    new_v.size = 0;
    new_v.arr = malloc(sizeof(int) * new_v.capacity);
    return new_v;
}


int vector_grow(vector* v){
    int new_cap = v->capacity * 2;
    int* tmp = realloc(v->arr, sizeof(int)*new_cap);
    if (!tmp){
        puts("Ошибка выделения памяти");
        return 0;
    }
    v->arr = tmp;
    v->capacity = new_cap;
    return 1;
}

void push_back(vector* v, int val){
    if (v->size >= v->capacity){
      if(!vector_grow(v))
        return;
    }
    v->arr[v->size++] = val;
}

int pop_back(vector* v){
    if (v->size > 0){
        int val = v->arr[--v->size];
        return val;
    }
    puts("Вектор и так пустой");
    return -1;
}

int vector_get(vector* v, int idx){
    if (idx < 0 || idx >= v->size){
        puts("Большой индекс");
        return -1;
    }
    return v->arr[idx];
}

void vector_set(vector* v, int idx, int val){
    if (idx < 0 || idx >= v->size){
        puts("Некорректный индекс");
        return;
    }
    v->arr[idx] = val;
}

void vector_destory(vector* v){
    free(v->arr);
}

void vector_insert(vector* v, int idx, int val){
    if (idx < 0 || idx >= v->size) {
        return; 
    }

    if (idx == v->size){
        push_back(v, val);
        return;
    }
    if (v->size >= v->capacity){
        vector_grow(v);
    }
    v->size++;
    for (int i = v->size-1 ; i > idx; i--){
        v->arr[i] = v->arr[i-1];
    }
    v->arr[idx] = val;
}

void vector_erase(vector* v, int idx){
    if (idx < 0 || idx > v->size) {
        return; 
    }
    if (idx == v->size){
        pop_back(v);
        return;
    }

    for (int i = idx; i < v->size; i++){
        v->arr[i] = v->arr[i+1];
    }
    v->size--;

}

void print_v(vector* v){
    printf("\n");
    for (int i = 0; i < v->size; ++i){
        printf("%d ", v->arr[i]);
    }
}

int main(){
    vector v = init_vector();
    push_back(&v, 10);
    push_back(&v, 11);
    push_back(&v, 12);
    push_back(&v, 67);
    vector_insert(&v, 1, 67);
    vector_insert(&v, 3, 67);
    print_v(&v);
    vector_erase(&v, 1);
    vector_erase(&v, 2);
    vector_erase(&v, 3);
    print_v(&v);
    
    
    vector_destory(&v);
}






