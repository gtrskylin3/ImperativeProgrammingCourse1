#include <stdio.h>

int main(){
    
    char str[] = "ZXC 1000 - 7?";
    char buff[100];
    FILE* fp = fopen("my_file.txt", "w");
    if(fp == NULL){
        return 1;
    }
    // fgetc fputc
    for (int i = 0; str[i] != '\0'; ++i){
        fputc(str[i], fp);
    }
    fclose(fp);
    FILE* in = fopen("my_file.txt", "r");
    if (in == NULL)
        return 2;
    char ch;
    int i = 0;
    while ((ch = fgetc(in)) != EOF)
        buff[i++] = ch;
    buff[i]  = '\0';
    puts(buff);
    fclose(in);
    return 0;
}