#include <stdio.h>
#include <string.h>

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitCnt){
    int i = 0; 
    while (iStr[i] != '\0') {
        if (iStr[i] >= 'a' && iStr[i] <= 'z'){
            (*oLowerCnt)++;
        } else if (iStr[i] >= 'A' && iStr[i] <= 'Z'){
            (*oUpperCnt)++;
        } else if (iStr[i] >= '0' && iStr[i] <= '9'){
            (*oDigitCnt)++;
        }
        i++;
    }  
    return i;
}

int main(){
    char buffer[102];
    int n = 1;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL){
        int low = 0; 
        int upp = 0; 
        int digit = 0;
        int chars = 0;
        
        buffer[strcspn(buffer, "\n")] = '\0';

        chars = calcLetters(&buffer[0], &low, &upp, &digit);
    
        printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", n, chars, low+upp, low, upp, digit);
        n++;
    }
}