#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    double quotient = (double)a / b;
    if (a % b == 0){
        printf("%d ", a / b);
        printf("%d ", a / b);
        printf("%d ", a / b);
        printf("%d\n", a % b);
    }
    else if (quotient > 0){
        printf("%d ", (int)(quotient));
        printf("%d ", (int)(quotient + 1));
        printf("%d ", (int)(quotient));
        printf("%d\n", a % b);
    } else {
        printf("%d ", (int)(quotient - 1));
        printf("%d ", (int)(quotient));
        printf("%d ", (int)(quotient));
        printf("%d\n", (a % b) + b);

    }
}