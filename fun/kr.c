// #include <stdio.h>
// #include <stdlib.h>

// typedef struct
// {
//     int* arr;
//     int size;
// } stack;

// void push_stack(stack* st, int elem)
// {
//     st->arr = realloc(st->arr, sizeof(int)*(st->size + 1));
//     st->arr[st->size++] = elem;
// }

// int pop_stack(stack* st)
// {
//     if (st->size == 0){
//         puts("ОШИБКА Стэк пустой");
//         ;
//     }
//     int val = st->arr[--st->size];
//     return val;
// }

// void enqeque(stack* st_in, int val)
// {
//     push_stack(st_in, val);
// }

// int dequeue(stack* st_in, stack* st_out)
// {
//     if (st_out->size == 0){
//         while (st_in->size > 0){
//             int val = pop_stack(st_in);
//             push_stack(st_out, val);
//         }
//     }

//     if (st_out->size == 0){
//         puts("Очередь пустая");
//     }
    
//     return pop_stack(st_out);
// }


// int main(){
//     stack in;
//     in.size = 0;
//     in.arr = (int*)malloc(in.size * sizeof(int));
//     enqeque(&in, 1);
//     enqeque(&in, 2);
//     enqeque(&in, 3);
//     enqeque(&in, 4);

//     stack out;
//     out.size = 0;
//     out.arr = (int*)malloc(out.size * sizeof(int));

//     printf("%d ", dequeue(&in, &out));   
//     printf("%d ", dequeue(&in, &out));   
//     printf("%d ", dequeue(&in, &out));   
//     printf("%d ", dequeue(&in, &out));   
    
// }

Опишите добавление
элемента в конец очереди и извлечение из начала, объяс
ните сохранение порядка FIFO

один стек хранит порядок обратный очереди
при добавлении в другой стек получается порядок очереди
и забирая первый из второго стека забрали из начала
и добавляя в первый стека добавляем в конец очереди
FIFO сохраняется так как из стека забирается первый 

 Оцените время операции
в худшем случае и суммарное время K операций над из
начально пустой очередью. Сколько памяти нужно для
хранения N элементов?

операция добавить O(1)
а удалить в худшем случае O(N) 
потому что будет перекладывать все из первого стека во второй 

память O(N)
