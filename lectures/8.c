#include <stdio.h>
// int main(){
//     unsigned long long a = 0xFFAABBCCDDull;
//     printf("%llX\n", a);
//     signed char sc = 0b10100111;
//     unsigned char uc = 0b10100111;
//     printf("%d %d\n", (int)sc, (int)uc);
//     return 0;
// }

// • %d — int (знаковое целое число, обычно 4 байта).
// • %u — unsigned int (беззнаковое целое число).
// • %x — unsigned int в 16-ричной системе счисления (маленькими буквами).
// • %lld — long long int (знаковое целое число, гарантированно не менее 8 байт).
// • %zd — size_t
// • %zu — size_t



// • <stdint.h> (<cstdint>) — Типы данных с фиксированным размером (например, int32_t, uint64_t), которые гарантируют точное количество бит на любой платформе.
// • <limits.h> (<climits>) — Макросы максимальных и минимальных значений (например, INT_MAX, CHAR_MIN) для базовых целочисленных типов текущей системы.


//size_t - размер в памяти 
//ptrdiff_t - результат вычитания 2 указателей 

// 1U - unsigned
//1LL - long long 
//1ULL - unsigned long long
//0xFF - 16 
//0177 - восьмеричное 
//0b1111 - двоичное


// битовые операции

// a << k = a * 2^k
// a >> k = a / 2^k

// x =     10100111
// x>>3 =  00111000

// int mask = 0b00001010; // Маска, где взведены 1-й и 3-й биты
// int n = 3;             // Проверяем 3-й бит

// if (mask & (1 << n)) {
//     // Бит установлен (равен 1)
// }


int binary_search(int target, int arr[], int size){
    int left = 0;
    int right = size - 1;

    while (left <= right){
        int mid = (right + left) / 2;
        if (arr[mid] == target){
            return mid;
        }
        if (arr[mid] > target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(int);
    printf("%d\n", binary_search(4, arr, size));
}

// можно доказать что цикл верный используя мат индукции и инвариант

