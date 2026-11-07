#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i){
        int current;
        scanf("%d", &current);
        arr[i] = current;
    }
    
    for (int i = 0; i < n; i++){
        int cnt = 0;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[i]){
                cnt++;
            }
        }
        printf("%d ", cnt);
    }
}