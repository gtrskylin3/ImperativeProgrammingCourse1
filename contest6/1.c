#include <stdio.h>
#include <stdlib.h>

typedef struct list_s
{
    double value;
    int next;
    /* data */
} list;


int main(){
    int n, f;
    scanf("%d %d", &n, &f);
    list* arr = malloc(sizeof(list) * n);

    
    for (int i = 0; i < n; ++i){
        scanf("%lf %d", &arr[i].value, &arr[i].next);    
    }
    
    while (f != -1){
        printf("%0.3lf\n", arr[f].value);
        f = arr[f].next;
    }

    free(arr);
}