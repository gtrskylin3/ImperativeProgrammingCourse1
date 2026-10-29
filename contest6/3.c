#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* create_string(int length, char data[], char** strings){
    char* new = malloc(sizeof(char)*length);
    strcpy(data, new);
    return new;

    strings[]
}

void delete_string(int id, char** strings){
    free(strings[id]);
}

void print_string(int id, char** strings){
    printf("%s\n", strings[id]);
}


int main(){

}