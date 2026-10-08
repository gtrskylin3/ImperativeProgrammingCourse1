// #include <stdio.h>

// void reverse(char arr[], int size){
//     int r, l;
//     l = 0;
//     r = size - 1;
//     while (r > l){
//         char tmp = arr[l];
//         arr[l] = arr[r];
//         arr[r] = tmp;
//         r--;
//         l++;
//     }
//     printf("%s\n", arr);
// }

// int main(){
//     int n;
//     scanf("%d", &n);
//     getchar();
//     for (int i = 0; i < n; ++i){
//         char cur_str[101];
//         int size = 0;
//         int cur_char;
//         while (size < 100){
//             cur_char = getchar();
//             if (cur_char == '\n' || cur_char == EOF){
//                 break;
//             }
//             cur_str[size] = (char)cur_char;
//             size++;
//         }
//         cur_str[size] = '\0';
        
//         reverse(cur_str, size);
//     }
// }
// #include <stdio.h>

// void reverse(char arr[], int size){
//     int r, l;
//     l = 0;
//     r = size - 1;
//     while (r > l){
//         char tmp = arr[l];
//         arr[l] = arr[r];
//         arr[r] = tmp;
//         r--;
//         l++;
//     }
//     printf("%s\n", arr);
// }

// int main(){
//     int n;
//     scanf("%d", &n);
//     getchar();
//     for (int i = 0; i < n; ++i){
//         char cur_str[101];
//         int size = 0;
//         int cur_char;
//         while (size < 100){
//             cur_char = getchar();
//             if (cur_char == '\n' || cur_char == EOF){
//                 break;
//             }
//             cur_str[size] = (char)cur_char;
//             size++;
//         }
//         cur_str[size] = '\0';
        
//         reverse(cur_str, size);
//     }
// }
#include <stdio.h>
#include <string.h>

void reverse(char arr[], int size){
    int r, l;
    l = 0;
    r = size - 1;
    while (r > l){
        char tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        r--;
        l++;
    }
    printf("%s\n", arr);
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i){
        char cur_str[101];
        scanf("%s", cur_str);
        int size = strlen(cur_str);
        reverse(cur_str, size);
    }
}