#include <stdio.h>
#define SIZE 5001

int main () {
    int n, l, r;
    scanf("%d", &n);
    int arr[SIZE] = {0};
    int mxSum = 0;
    for (int i = 0 ; i < n; ++i){
        int cur;
        scanf("%d", &cur);
        arr[i] = cur;
        mxSum += cur;
    } 
    int maxL, maxR;
    maxL = 0;
    maxR = n - 1;
    for (l = 0; l < n; ++l){
        int curSum = 0;
        for (r = l; r < n; ++r){
            curSum+=arr[r];
            if ((curSum > mxSum) || (curSum == mxSum && r < maxR)){
                mxSum = curSum;
                maxL = l;
                maxR = r;
            }
        }
    }
    printf("%d %d %d", maxL, maxR, mxSum);
}