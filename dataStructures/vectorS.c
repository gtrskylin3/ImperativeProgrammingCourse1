#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Vector{
    unsigned int count;
    unsigned int block_size;
    char *data;
} vector;

vector* create_vector(unsigned int block_size){
    vector* v = (vector*)malloc(sizeof(vector));
    v->count = 0;
    v->block_size = block_size;
    v->data = NULL;
    return v;
}

vector* push_back(vector* v, void* el){
    v->count++;
    v->data = (char*)realloc(v->data, v->count*v->block_size);
    memcpy(&v->data[(v->count-1)*v->block_size], el, v->block_size);
    return v;
}

void setVectorEl(vector* v, unsigned int i, void* el) {
    memcpy(&v->data[i*v->block_size], el, v->block_size);
}


void* get_el(vector* v, unsigned int i){
    return &v->data[i*v->block_size];
}

void freeV(vector* v){
    if (v){
        if (v->data)
            free(v->data);
        free(v);
    }
}

int main(int argc, char* argv[]){
    vector* v = create_vector(sizeof(int));
    int a = 1;
    while (a != 0){
        printf("a=");
        scanf("%d", &a);
        if (a == 0) break; 
        push_back(v, &a);
    }
    for (int i = 0; i < v->count; ++i){
        printf("vector[%d] = %d\n", i, *(int*)get_el(v, i));
    }

    freeV(v);
    return 0;
}