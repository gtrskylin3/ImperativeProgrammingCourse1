// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// // int main(){
// //     char* s = "a";
// //     printf("%zu %zu\n", sizeof("a"), sizeof(s));
// // }

// // char* mystrdup(const char* s) { 
// //     if (!s)
// //         return NULL;
// //     char* res = malloc(strlen(s) + 1);
// //     // проверка
// //     if (!res)
// //         return NULL;
// //     strcpy(res, s); // скопировали все байты из s в res
// //     return res;
// // }

// // int main(){
// //     int n;
// //     scanf("%d", &n);
// //     int* a = (int*)malloc(sizeof(int)*n);
// //     for (int i = 0 ; i < n; ++i){
// //         a[i] = i+1;
// //     }

// //     for (int i = 0 ; i < n; ++i){
// //         printf("%d ", a[i]);
// //     }
// //     printf("\n");
// //     free(a); // нужно передовать тот же аддрес что получили от malloc 
// // }


// typedef struct vector_t{
//     int* arr;
//     size_t size; // размер массива сейчас
//     size_t cap; // размер буфера сколько можно поместить
//     // size достигнет cap то новый элемент положить не можем и нужно делать realloc 
// } vector_t;

// void vector_init(
//     struct vector_t* vector,
//     int cap
// ) {
//     if (!vector)
//         return;
    
//     if (cap <= 0)
//         cap = 4; 
    
//     vector->arr = (int*)malloc(sizeof(int)*cap);
//     vector->cap = cap;
//     vector->size = 0;
// }


// void vector_increase_cap(
//     struct vector_t* vector
// ) {
//     if (!vector)
//         return;
//     // vector->cap++;
//     size_t new_cap = vector->cap * 2;
//     int* tmp = (int*)realloc(vector->arr, sizeof(int)*new_cap);
//     if (!tmp){
//         return;
//     }
//     vector->arr = tmp;
//     vector->cap = new_cap;
// }

// void vector_push(
//     struct vector_t* vector,
//     int value
// ) {
//     if (!vector) 
//         return;

//     if (vector->size >= vector->cap){
//         vector_increase_cap(vector);
//     }
    
//     vector->arr[vector->size] = value;
//     vector->size++;
// }   


// int main(){
//     vector_t v;
//     vector_init(&v, 4);
//         printf("Старт: size = %zu, cap = %zu\n", v.size, v.cap); // 0 и 2

//     vector_push(&v, 10);
//     vector_push(&v, 20); // Теперь вектор заполнен (2 из 2)
    
//     // Этот push автоматически вызовет vector_increase_cap inside
//     vector_push(&v, 30); 
//     vector_push(&v, 40); 
//     vector_push(&v, 50); 
//     vector_push(&v, 60); 
//     vector_push(&v, 70); 
//     vector_push(&v, 80); 
//     vector_push(&v, 90); 
//     vector_push(&v, 100); 
//     vector_push(&v, 30); 
//     vector_push(&v, 40); 
//     vector_push(&v, 50); 
//     vector_push(&v, 60); 
//     vector_push(&v, 70); 
//     vector_push(&v, 80); 
//     vector_push(&v, 90); 
//     vector_push(&v, 100); 
    
//     vector_push(&v, 30); 
//     vector_push(&v, 40); 
//     vector_push(&v, 50); 
//     vector_push(&v, 60); 
//     vector_push(&v, 70); 
//     vector_push(&v, 80); 
//     vector_push(&v, 90); 
//     vector_push(&v, 100); 
//     vector_push(&v, 30); 
//     vector_push(&v, 40); 
//     vector_push(&v, 50); 
//     vector_push(&v, 60); 
//     vector_push(&v, 70); 
//     vector_push(&v, 80); 
//     vector_push(&v, 90); 
//     vector_push(&v, 100); 
    
//     printf("После 6-х push: size = %zu, cap = %zu\n", v.size, v.cap); // 3 и 4 (капа удвоилась!)

//     // Выведем элементы
//     for(size_t i = 0; i < v.size; i++) {
//         printf("v[%zu] = %d\n", i, v.arr[i]);
//     }
// }

// #include <stdio.h>
// int main(){
//     if ('' == NULL){
//         printf("XUI");
//     }
// }

#include <stdio.h>
int main() {
    int a = 0; int* b = &a; int** c = &b;
    ++**c;
    printf("%d\n", a);
    *b *= 2; printf("%d\n", a);
    printf("%d\n", a++);
    return 0;
}