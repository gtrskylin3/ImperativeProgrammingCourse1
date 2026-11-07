#include <stdio.h>

int word_count(const char* str){
    int cnt = 0; 
    int is_word = 0;
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] != ' '){
            is_word = 1;
        } else {
            if (is_word){
                cnt++;
                is_word = 0;
            }
        }
        i++;
    }
    
    return cnt;
}

int main (){
    char string[100];
    fgets(string, sizeof(string), stdin);
    int wc = word_count(string);
    printf("Word count: %d\n", wc);
}