#include <stdio.h>

enum {max_length=1024};

int main(){
    // const char* str[] = {
    //     "привет привет",
    //     "как дела",
    //     "HELLO"
    // };
    // FILE* fp = fopen("my_file.txt", "w");
    // if (fp == NULL){
    //     perror("my_file.txt");
    //     return -1;
    // }

    // for (int i =0 ; i < sizeof(str) / sizeof(*str); ++i){
    //     fputs(str[i], fp);
    //     fputs("\n", fp);
    // }

    // fclose(fp);
    // return 0;
 
    // char buffer[100];

    // FILE* fp = fopen("my_file.txt", "r");

    // if (fp == NULL){
    //     perror("my_file.txt");
    //     return -1;
    // }

    // while (fgets(buffer, sizeof(buffer), fp)){
    //     char *ptr = strchr(buffer, '\n');
    //     if (ptr != NULL)
    //         *ptr = '\0';
    //     puts(buffer);
    // }

    // fclose(fp);
    // return 0;
 
    double rub_usd[max_length] = {0.0};
    unsigned length = 0;

    FILE* fp = fopen("data.csv", "r");

    if (fp == NULL){
        perror("data.csv");
        return -1;
    }

    while (fscanf(fp, "%lf; ", &rub_usd[length]) == 1){
        length++;
    }

    fclose(fp);

    for (int i = 0; i < length; ++i){
        printf("%.3f ", rub_usd[i]);
    }
    return 0;

    return 0;
}