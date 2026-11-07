#include <stdio.h>
#include <string.h>
#define SIZE 100001


char arr[SIZE];

int convert_dec(char arr[], int size){
    int dec = 0;
    int power = 0;
    for (int i = 0; i <= size; ++i){
        dec += (arr[i] - '0') << power;
        power++;
    }
    return dec;
}


int main(){
    int n ; 
    scanf("%d ", &n);

    fgets(arr, n+1, stdin);
    
    char b[8];

    int id = 0;
    
    for (int i = 0; i < n; ++i){        
        if (i % 8 == 0 && i != 0){
            int dec = convert_dec(b, id-1);
            printf("%d ", dec);
            memset(b, 0, sizeof(b));
            id = 0;
        }
        b[id] = arr[i];
        id++;
    }
    int dec = convert_dec(b, id-1);
    printf("%d ", dec);
}