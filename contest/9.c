#include <stdio.h>

int main(){
    // a <= b <= c
    long long n;
    scanf("%lld", &n);
    long long cnt = 0; 
    for (long long a = 1; a * a * a <= n; ++a){ // a <= N^3{
        for (long long b = a; b * b * a <= n; ++b){ //  a <= b <= n{
            long long max_c = n / (a * b); 
            cnt += max_c - b + 1;
            //max_c мы можем узнать из n / (a * b) так как a*b*c <= n 
            // c <= n / (a * b) 
            // c начинается с b значит
            // max_c - b это итерации от b до max_c
            // не включительно из за этого добавляем еще 1
        }
    }
    printf("%lld", cnt);
}

