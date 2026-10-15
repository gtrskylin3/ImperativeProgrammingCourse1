#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Label_s
{
    char name[16];
    int age;
} Label;

typedef struct NameStats_s
{
    int cntTotal;
    int cntLong;
} NameStats;

typedef struct AgeStats_s
{
    int cntTotal;
    int cntAdults;
    int cntKids;
} AgeStats;

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges){
    oNames->cntTotal++;
    oAges->cntTotal++;
    int length = strlen(arr[cnt].name);
    if (length > 10){
        oNames->cntLong++;
    }
    if (arr[cnt].age >= 18){
        oAges->cntAdults++;
    } else if (arr[cnt].age < 14){
        oAges->cntKids++;
    }
    
}

int main(){
    int n, age;
    scanf("%d", &n);
    NameStats names;
    names.cntLong = 0;
    names.cntTotal = 0;
    AgeStats ages;
    ages.cntAdults = 0;
    ages.cntKids = 0; 
    ages.cntTotal = 0;
    Label* arr = malloc(sizeof(Label) * n);
    char name[16];
    for (int i = 0; i < n; ++i){
        scanf("%s %d %*s", arr[i].name, &arr[i].age);
        calcStats(arr, i, &names, &ages);
    }
    printf("names: total = %d\n", names.cntTotal);
    printf("names: long = %d\n", names.cntLong);
    printf("ages: total = %d\n", ages.cntTotal);
    printf("ages: adult = %d\n", ages.cntAdults);
    printf("ages: kid = %d\n", ages.cntKids);

    free(arr);
}
