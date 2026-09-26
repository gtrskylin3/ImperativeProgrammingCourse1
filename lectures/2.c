// #include <stdio.h>

// int main() {
//     // Шапка таблицы (4 колонки)
//     printf("%-10s | %-10s | %-10s | %-10s\n", "Dec Ch", "Dec Ch", "Dec Ch", "Dec Ch");
//     printf("---------------------------------------------------\n");

//     int columns = 4; // Количество колонок

//     for (int i = 32; i < 128; ++i) {
//         // Печатаем число и символ. %3d выравнивает число по ширине в 3 знака
//         printf("%3d: %-5c", i, i);

//         // Если вывели нужные нам 4 колонки — переходим на новую строку
//         if ((i - 32 + 1) % columns == 0) {
//             printf("\n");
//         } else {
//             printf(" | "); // Разделитель между колонками
//         }
//     }
    
//     printf("\n");
//     return 0;
// }

// #include <stdio.h>
// #include <ctype.h>

// int main() {
//     char s[] = "Hello";
//     // printf("%s\n", s);

//     for (int i = 0; s[i] ; i++) {
//         s[i] = toupper(s[i]);
//     }
//     printf("%s\n", s);
//     return 0;
// }


// #include <stdio.h>
// #include <ctype.h>

// int main() {
//     char s[] = "Hello";
//     scanf("%5s", s);
//     printf("%s\n", s); 
//     return 0;
// }


// #include <stdio.h>

// typedef struct point_t {
//     int x, y;
//     struct point_t* p; // pointer внутри
// } point_t;

// void read_point(point_t* point){
//     // scanf("%d %d", &(*point).x, &(*point).y);
//     scanf("%d %d", &point->x, &point->y);

// }

// void print_point(point_t* point){
//     // scanf("%d %d", &(*point).x, &(*point).y);
//     printf("%d %d\n", point->x, point->y);

// }


// int main(){
//     point_t points[3];
//     for (int i = 0 ; i  < 3 ; ++ i){
//         read_point(points + i);
//     }
//     for (int i = 0 ; i  < 3 ; ++ i){
//         print_point(points + i);
//     }


// }

// Решето Эратосфена 
int main(){
    
}