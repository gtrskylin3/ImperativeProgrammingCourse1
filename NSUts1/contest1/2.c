#include <stdio.h>
int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x > 0 && y > 0 && z > 0){
        printf("%d", 2 * (x * y + x * z + y * z));
    } else if (x <= 0){
        printf("%d", -1);
    } else if (y <= 0){
        printf("%d", -2);
    } else if (z <= 0){
        printf("%d", -3);
    }
    return 0;
}