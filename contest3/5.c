#include <stdio.h>
#define  N 1000001
char string[N];

void countWords(char string[N]){
    int i = 0; 
    int isWord = 0;
    int length = 0;
    int upper = 0;
    int wordStart = 0;
    while (string[i] != '\0'){
        if (string[i] >= 'a' && string[i] <= 'z'){
            if (!isWord){
                isWord=1;
                wordStart = i;
            }
            length++;
        } 
        else if (string[i] >= 'A' && string[i] <= 'Z'){
            if (!isWord){
                isWord=1;
                wordStart = i;
            }
            upper++;
            length++;
        } 
        else if (isWord){
            isWord = 0;
            char tmp = string[i];
            string[i] = '\0';
            printf("%d/%d %s\n", upper, length, &string[wordStart]);
            string[i] = tmp;
            length = 0;
            upper = 0;
        }
        i++;
    }
    if (isWord){
        printf("%d/%d %s\n", upper, length, &string[wordStart]);
    }
}

int main(){
    scanf("%s", string);
    countWords(string);
}