#include <stdio.h>
#define N 1001
#define K 1001

double C[N][K];

void makeCnk(){
    for (int n = 0; n < N; ++n){
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; ++k){
            C[n][k] = C[n-1][k-1] + C[n-1][k];
        }    
    }
}

int main(){
    int c, n, k;
    makeCnk();
    scanf("%d", &c);

    for (int i = 0; i < c; ++i){
        scanf("%d %d", &n, &k);
        printf("%0.10g\n", C[n][k]);
    }
}