#include <stdio.h>
#define N_SIZE 301
#define M_SIZE 90001

int countX[N_SIZE];
int P[N_SIZE];
int countY[M_SIZE];




void initP(int sizeN, int P[]){
    for (int i = 0; i <= sizeN-1; ++i){
        P[i] = i+1;
    }
}

int isDefined(int sizeN, int P[], int count[]){
    for (int i = 0; i < sizeN; ++i){
        if (count[P[i]] == 0){
            return 0;
        } 
    }
    return 2;
}

int main(){
    int n, m;
    int isInj = 1;
    int isFunc = 1;
    int isSur = 1;
    int isDef = 1;
    scanf("%d %d", &n, &m);
    initP(n, P);
    int x, y;
    for (int i = 0; i < m; ++i){
        scanf("%d %d", &x, &y);
        countX[x]++;
        countY[y]++;
        if (countX[x] > 1){
            isFunc = 0;
        }
        if (countY[y] > 1){
            isInj = 0;
        }
    }
    if (!isFunc){
        printf("0");
        return 0;
    }
    printf("1 ");
    isDef = isDefined(n, P, countX);
    isSur = isDefined(n, P, countY);
    if (isDef){
        printf("2 ");
    }
    if (isInj){
        printf("3 ");
    }
    if (isSur){
        printf("4 ");
    }
    if (isInj && isSur && isDef){
        printf("5");
    }
}