#include <stdio.h>

int main() {
    char cur;
    scanf("%c", &cur);
    int isWord = 0;
    int cnt = 0;
    while (cur != '\n'){
        if (cur != '.'){
            if (isWord == 0){
                cnt++;
                isWord = 1;
            }
        } else {
            isWord = 0;
        }
        scanf("%c", &cur);
    }
    printf("%d\n", cnt);
}