#include <stdio.h>
int main(){
    // not
    // unsigned char var = 153; // 10011001
    // unsigned char not_var = ~var; // 01100110
    // // and
    // unsigned char flags = 1; // 00000001
    // unsigned char mask = 4; // 00000100
    // unsigned char res = flags & mask;
    // if ((flags & mask) == mask)
    //     printf("bit 2 is on\n");
    // else
    //     printf("bit 2 is off\n");
    // // or
    // unsigned char flags = 8; //         00001000
    // unsigned char mask = 5; //          00000101
    // unsigned char res = flags | mask; //00001101   
    // return 0;

    //xor
    // unsigned char flags = 9;          //         00001001
    // unsigned char mask =  1;          //         00000001
    // unsigned char res = flags ^ mask; //         00001000
    // printf("%d\n", res);
    // res ^= mask;                       //         00001001
    // printf("%d\n\n", res);

    // >> && << bit moving

    unsigned char x = 40;  //00101000 40
    printf("x = %d\n", x);

    x = x >> 1;            //00010100 20
    printf("x = %d\n", x);

    x = x >> 2;            // 00000101 5
    printf("x = %d\n", x); 
    
    x = x >> 1;            // 00000010 2
    printf("x = %d\n", x);
    
    x = x >> 1;            // 00000001 1
    printf("x = %d\n", x);
    
    x = x << 1;             // 00000010 2
    printf("x = %d\n", x);
    
    x = x << 2;             // 00001000 8  
    printf("x = %d\n", x);
}