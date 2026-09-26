#include <stdio.h>

int main(){
    int n;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int cur;
        scanf("%d", &cur);
        if (cur % 2 == 0){
            sum += cur;
        }
    }
    printf("%d", sum);
    return 0;
}