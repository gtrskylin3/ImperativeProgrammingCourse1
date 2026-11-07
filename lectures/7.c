
// #define MAC(a, b) ((a) > (b)? (a) : (b))

// #define CHECK (call) \
//     do { \
//         int err = call; \
//         if (err != 0) return err;\
//     } while (0);

// int main(){
//     CHECK(10);

// }

// #include <stdio.h>
// #define CHECK(call) \
//     do {\
//         int err = call; \
//         if (err)\
//             return err;} \
//     while (0)


// int g(int n){
//     if (n < 0){
//         return 1;
//     }
//     // ...
//     return 0;
// }

// int f(int n){
//     //..
//     // if (g(n) != 0){
//     //     return 1;
//     // }
    
//     // if (g(n) != 0){
//     //     return 1;
//     // }
    
//     // if (g(n) != 0){
//     //     return 1;
//     // }
//     CHECK(g(n));
//     CHECK(g(n));
//     CHECK(g(n));
//     //,,
//     return 0;
// }
// int main(){
//     int n ;
//     scanf("%d", &n);
//     CHECK(f(n));
//     return 0;
// }
#include <stdio.h>
int main(){ 
    // long long ll; 
    // int i = (int)ll;

    // float f = 0.5;
    // int i = (int)f;

    // int i = 97;
    // char c = (char)i;

    // неявное приведение типов 
    // char <-> short <-> int <-> long 
    // double <-> float 
    // double <-> int <-> float <-> char 
    // void* <-> int* <-> T*
    // 0 -> T*;
    // T[] -> T*
    // int* <-> int 

    // int k = 257;
    // int n = (char)k;
    // printf("%d\n", n);
    // return 0;

    // double k1 = 257.5;
    // double n1 = (char)(int)k1; // 2 явных преобразований и 1 неявное к типу дабл
    // printf("%lf\n", n1);
    // return 0;

    // double + int -> double + double 
    // long long + int -> long long + long long 
    // unsigned + signed -> signed + signed
    // T[] + int -> T* + int

    // char c =1;
    // int x  = 1000;
    // int n =  x + c;
    // printf("%d\n", n);

    int x = 100000000;
    long long n = (long long)x * x;
    printf("%lld\n", n);
    return 0;
}