// #include <stdio.h>
// #include <stdlib.h>
// int main(){    
//     int n = 5;
//     int* arr = malloc(n*sizeof(int));
//     for (int i = 0; i < n; ++i){
//         int one = 0;
//         int num = i;
//         while (num > 0){
//             if (i % 2 == 1){
//                 one ++;
//             }
//             num = num >> 1;
//         }
//         arr[i] = one;
//         printf("%d ", arr[i]);
//     }
//     free(arr);
// }
#include <stdio.h>
int main(){
    int size = 31;
    unsigned long long res = 0;
    while (n > 0){
        if (n & 1){
            res += 1 << size;
        }
        size--;
        n = n >> 1;
    }
    printf("%lld",res);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalSubsets = 1 << numsSize;
    *returnSize = totalSubsets; 
    int **arr = malloc(totalSubsets * sizeof(*arr));
    *returnColumnSizes = malloc(totalSubsets * sizeof(int));  
    
    for (int i = 0; i < totalSubsets; ++i){
        int len = 0;
        for (int j = 0; j < numsSize; ++j){
            if ((i>>j) & 1){
                len++;
            }
        }
        (*returnColumnSizes)[i] = len;
        arr[i] = malloc(sizeof(int)*len);
        int idx = 0;
        for (int j = 0; j < numsSize; ++j){
            if ((i>>j) & 1){
                arr[i][idx++] = j;
            }
        }
    }
    return arr;
}

