#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// int isPrime(int cur){
//     if (cur == 2) return 1;
//     if (cur < 2) return 0;
//     for (int i = 2; i < sqrt((double)cur)+1; ++i ){

//         if ((cur % i) == 0){
//             return 0;
//         }
//     }
//     return 1;
// }

int reshetoEretesfen(int* nums, int size){
    nums[0] = 1;
    nums[1] = 1;
    for (int i = 2; i * i <= size; ++i){
        if (nums[i] == 0){
            for (int j = i*i; j <= size; j+=i){
                nums[j] = 1;
            } 
        }
       
    }
}

int main(){
    int n, q, cur;
    scanf("%d %d", &n, &q);
    int* reshoto = calloc(n+1, sizeof(int));
    reshetoEretesfen(reshoto, n);
    for (int i = 0; i < q; ++i){
        scanf("%d", &cur);
        int prime = !reshoto[cur];
        if (prime){
            printf("%d prime\n", cur);
        } else {
            printf("%d not\n", cur);
        }
    }
    free(reshoto);
}