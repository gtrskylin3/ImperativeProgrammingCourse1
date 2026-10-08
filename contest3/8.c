#include <stdio.h>
#define N 5001

int nums[N] = {0};

int main(){
    int n ;
    scanf("%d", &n);
    for (int i = 2; i * i <= n; ++i){
        if (nums[i] == 0){
            for (int j = i*i; j <= n; j+=i){
                nums[j] = 1;
            } 
        }
       
    }

    for (int i = 2; i <= n; ++i){
        if (nums[i] == 0){
            printf("%d\n", i);
        }
    }

    return 0;
}


// int get_size(){
//     struct X { struct X* p[4]; };
//     return sizeof(struct X);
// }
