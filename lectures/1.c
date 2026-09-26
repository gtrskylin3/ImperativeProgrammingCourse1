//L2 arays & pointers

#define N 100
#include <stdio.h>

int main1 () {
    int a[N]; // n * 4 bytes
    
    for (int i = 0; i < N; ++i){
        a[i]= i;
    }
}

int main2 () {
    int a[5] = {1};
    int* p = a;
    // p[0] = 1;
    *p = 1;
    for (int i= 1 ; i < 5; ++i){
        p[i] = p[i - 1] * 3;
        // printf("%d\n", p[i]);
    }
    for (int i= 0 ; i < 5; ++i){
        printf("%d\n", p[i]);
    }
}

int main3 () {
    int a[5] = {0};
    int* p = a;
    *p = 1;
    ++p; // + 4 
    *p = 2;
    ++p;
    *p = 3;
    for (int i = 0; i  < 5; ++ i){
        printf("%d\n", a[i]);
    }
}

int main4 () {
    int a[5] = {0};
    int* p = a;
    // int* p2 = &a[4]; 
    // &a[n] == a + n
    // *&a[n] == a[n] == *(a + n)
    int* p2 = a + 4;
    int diff = p2 - p; 
    printf("%d\n", diff);
}

int main5(){
    int a[5] = {1,2,3,4,5};
    int* p = a;
    for (int i = 0 ; i < 5 ; ++ i){
        ++*p++; // (++(*(p++)))
    }
    *--p = 0; // last element
    for (int i = 0 ; i < 5 ; ++ i){
        printf("%d\n", a[i]);
    }
}

void f(int* p) {
    *p = 10;
}
int p2;

void f2(int** p){
    p = &p2;
}

int main(){
    // int n;
    // int* ptr_n = &n;
    // scnaf("%d", ptr_n);
    // f(&n);
    // printf("%d", n);
    // int a[3];
    // for (int i = 0 ; i < 3 ; ++ i){
    //     f(a+i);
    // }
    // for (int i = 0 ; i < 3 ; ++i ){
    //     printf("%d\n", a[i]);
    // // }
    // int* p = NULL;
    // if (...){
    //     p = &n;
    // }
    // if (p) {
    //     *p = ...;
    // }
}

// Асимптотика
// T(n) = O (g(n)) <=> En0, C : An > n0 -> T(n) < C * g(n)
// пробежать по массиву O(n)
// определить простое число или нет O(sqrt(N))
// пробежать k вложенных циклов по N элементов O(N ** k)

// Сколько операций в секунду делает проц
//  N Ghz N милиардов операций которые делятся на такты 




