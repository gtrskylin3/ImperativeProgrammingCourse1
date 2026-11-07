#include <stdio.h>
#include <stdlib.h>

int bin_search(int* arr, int size, int target){
    int right = size-1;
    int left = 0;
    while (right >= left){
        int mid = (right + left) / 2;
        if (arr[mid] == target){
            if (mid < size-1 && arr[mid+1]==target){
                left = mid+1;
                continue;
            }
            return mid;
        } else if (arr[mid] > target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n, q;
    scanf("%d", &n);
    int* arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i ){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &q);
    int pred_answ = 0;

    for (int i = 0 ; i < q; ++i){
        int xi;
        scanf("%d", &xi);
        xi += pred_answ;
        int res = bin_search(arr, n, xi);
        pred_answ = res;
        printf("%d\n", res);
    }

    free(arr);
}
