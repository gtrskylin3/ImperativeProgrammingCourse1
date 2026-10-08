#include <stdio.h>
#define SIZE 100000*10+10

char pref[SIZE];

char* concat(char* pref, char* stuf){
    int i = 0;
    while (pref[i] != '\0') i++;
    int j = 0;
    while (stuf[j] != '\0'){
        pref[i] = stuf[j];
        i++;
        j++;
    }
    pref[i] = '\0'; 
    return &pref[i];
}

int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", pref);
    char stuf[101];
    char *ptr = pref;
    for (int i = 0 ; i < n-1; ++i){
        scanf("%s", stuf);
        ptr = concat(ptr, stuf);
    
    }
    printf("%s\n", pref);
}