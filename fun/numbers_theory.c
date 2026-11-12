#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// bool is_prime(int n) {
//     for (int d = 2; d * d <= n ; ++d){
//         if (n % d == 0){
//             return false;
//         }
//     }
//     return n != 1;
// }

//ALGORITHM EVKLIDA
int gcd(int a, int b){
    if (b  == 0){
        return a;
    }
    return gcd(b, a % b);
}


int main(){
    int n;
    scanf("%d", &n);
    // for (int i = 1; i <= n; ++i){
    //     if (n % i == 0){
    //         printf("%d ", i);
    //     }
    // }
    // int cnt = 0;
    // for (int i = 1; i * i <= n; ++i){
    //     if (n % i == 0){
    //         cnt++;
    //         if (i != n / i){
    //             cnt++;
    //             printf("%d %d ", i, n / i);
    //         }else{
    //             printf("%d ", i);
    //         }
    //     }
    // }
    // printf("\n%d ", cnt);
    // // проверка на простоту
    // if (cnt == 2){
    //     printf("yes\n");
    // }else{
    //     printf("no\n");
    // }
    // простое число имеет 2 делителя 1 не простое


    // любое число можно представить как произведение простых делителей

    // int nums[100] = {0};
    // int size =0 ;
    // for (int d = 2; d * d <= n; d++){
    //     if (n % d == 0){
    //         if (is_prime(d)){
    //             nums[size++] = d;
    //         }
    //         if (d != n / d){
    //             if (is_prime(n / d)){
    //                 nums[size++] = n / d;
    //             }
    //         }
    //     }
    // }
    // for (int i = 0; i < size; ++i){
    //     printf("%d ", nums[i]);
    // }
    // int nums[100] = {0};
    // int size =0 ;
    // for (int d = 2; d * d <= n; d++){
    //     while (n % d == 0){
    //         nums[size++] = d;
    //         n /= d;
    //     }
    // }
    // if (n != 1){
    //     nums[size++] = n;
    // }
    // for (int i = 0; i < size; ++i){
    //     printf("%d ", nums[i]);
    // }


    // int* is_prime = malloc(sizeof(int) * n);
    // for (int i = 0; i < n; ++i){
    //     is_prime[i] = 1;
    // }
    // is_prime[0] = is_prime[1] = 0;
    // for (int i =2; i <= n; ++i){
    //     if (is_prime[i]){
    //         for (int j = i*i; j <= n; j+=i){
    //             is_prime[j] = 0;
    //         }
    //     }
    // }
    // for (int i = 0 ; i < n; ++i){
    //     if (is_prime[i] == 1){
    //         printf("%d ", i);
    //     }
    // }
    // free(is_prime);
    // return 0;

    // НОД(a,b) и НОК(a,b)


}