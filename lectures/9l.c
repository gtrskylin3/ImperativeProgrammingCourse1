#include <stdio.h>


// int f(){
//     static int n;
//     return n++;
// }

// void x() {
//     init_x();
//     static int inited = 0; 
//     if (!inited){
//         init_x();
//         inited = 1;
//     }
// }


// int main(){
//     printf("%d\n",f()); 
//     printf("%d\n",f()); 
//     printf("%d\n",f()); 
//     printf("%d\n",f()); 
//     printf("%d\n",f()); 

// }


// int main(){
//     double d = 0;
//     *((long long*)&d) = 0x3FF0LL << 48;
//     printf("%lf\n", d);
//     // printf("%lld", *(long long*)&d);
//     return 0;
// }


// int main(){
//     int n = 0x01020304; 
//     char* p = (char*)&n;
    
//     for (int i = 0; i < 4; ++i){
//         printf("%x\n", (int)p[i]);
//     }
// }


// union int_or_four_chars {
//     int i;
//     char c[4];
// };

// int main(){
//     union int_or_four_chars x;
//     x.i = 0x01020304;
//     x.i = 258;
//     x.i = -2;
//     x.i = -256;
//     // почему так 

//     for (int i = 0; i < 4; ++i){
//         printf("%d\n", x.c[i]);
//     }

// }

# define P(X) printf("%p %s\n", &X, #X);
# include <stdlib.h>

int global;

int jopa(){
    printf("jopa");
}


int main(){
    int local;
    int local_v2;
    static int static_var;
    int *heap_var = malloc(sizeof(int));
    int *heap_var_2 = malloc(sizeof(int));

    P(main);
    P(global);
    P(static_var);
    P(local);
    P(local_v2);
    P(*heap_var);
    P(*heap_var_2);
}