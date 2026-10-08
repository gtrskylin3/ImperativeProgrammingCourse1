#include <stdio.h>
#include <stdlib.h>

int readTime(char *iStr, int *oHours, int *oMinutes, int *oSeconds){
    int s1 = 0;
    int m1 = 0;
    int h1 = 0;
    int count1;

    count1 = sscanf(iStr, "%d:%d:%d", &h1, &m1, &s1);

    if (count1 != 3){
        count1 = sscanf(iStr, "%d:%d", &h1, &m1);
        if (count1 != 2) {
            *oHours = -1;
            if (oMinutes) *oMinutes = -1;
            if (oSeconds) *oSeconds = -1;
            return 0;
        }
    }
    if (h1 > 23 || m1 > 59 || s1 > 59){
        *oHours = -1;
        if (oMinutes) *oMinutes = -1;
        if (oSeconds) *oSeconds = -1;
        return 0;
    }

    *oHours = h1;
    if (oMinutes)
        *oMinutes = m1;
    if (oSeconds)
        *oSeconds = s1;

    return 1;
}

int main(){
    char buffer[16];
    int h, m, s, resCode;
    fgets(buffer, sizeof(buffer), stdin);
    
    resCode = readTime(buffer, &h, &m, &s);
    printf("%d %d %d %d\n", resCode, h, m, s);
    resCode = readTime(buffer, &h, &m, NULL);
    printf("%d %d %d\n", resCode, h, m);
    resCode = readTime(buffer, &h, NULL, NULL);
    printf("%d %d\n", resCode, h);
 
}