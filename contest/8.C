#include <stdio.h>

int main () {
    int hours, minutes, seconds, k;
    scanf("%d %d %d %d", &hours, &minutes, &seconds, &k);
    seconds += k;
    while (seconds >= 60){
        minutes++;
        seconds -= 60;
    }
    while (minutes >= 60){
        hours++;
        minutes -= 60;
    }
    hours = hours % 24;
    printf("%d %d %d\n", hours, minutes, seconds);
}