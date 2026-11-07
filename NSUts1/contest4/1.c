#include <stdio.h>
#include <stdlib.h>

typedef struct DateTime_s {
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;

DateTime min(const DateTime *arr, int cnt){
    DateTime minDate = arr[0];
    for (int i = 1; i < cnt; ++i){
        if (arr[i].year < minDate.year){
            minDate = arr[i];
        } else if (arr[i].year > minDate.year)
            continue;

        if (arr[i].month < minDate.month){
            minDate = arr[i];
        } else if (arr[i].month > minDate.month)
            continue;
        
        if (arr[i].day < minDate.day){
            minDate = arr[i];
        } else if (arr[i].day > minDate.day)
            continue;

        if (arr[i].hours < minDate.hours){
            minDate = arr[i];
        } else if (arr[i].hours > minDate.hours)
            continue;
        
        if (arr[i].minutes < minDate.minutes){
            minDate = arr[i];
        } else if (arr[i].minutes > minDate.minutes)
            continue;
        
        if (arr[i].seconds < minDate.seconds){
            minDate = arr[i];
        } else if (arr[i].seconds > minDate.seconds)
            continue;
    } 
    return minDate;
}

int main(){
    int n, year, month, day, hours, minutes, seconds; 
    scanf("%d", &n);
    DateTime* arr = malloc(sizeof(DateTime)*n);
    if (!arr)
        return 1;

    for (int i = 0 ; i < n; ++i){
        scanf("%d %d %d %d %d %d", &year, &month, &day, &hours, &minutes, &seconds);
        arr[i].year = year;
        arr[i].month = month;
        arr[i].day = day;
        arr[i].hours = hours;
        arr[i].minutes = minutes;
        arr[i].seconds = seconds;
    }
    DateTime minDate = min(arr, n);
    
    printf("%d %d %d %d %d %d\n", minDate.year, minDate.month, minDate.day, minDate.hours, minDate.minutes, minDate.seconds);
    free(arr);
}