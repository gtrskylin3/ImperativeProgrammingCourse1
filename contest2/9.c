#include <stdio.h>
#define NUM 100000

int numArr[NUM] = {0};
char answArr[NUM];

int my_pow (int num, int power){
    int result = 1;
    for (int i =0 ; i < power; i++){
        result*=num;
    }
    return result;
}

int toDec(int fromBase, int arr[], int size){
    int power = 0;
    int decNum = 0;
    while (size > 0){
        decNum += arr[size-1] * my_pow(fromBase, power);
        size--;
        power++;
    }
    return decNum;
}

int convert(int toBase, int decNum, char arr[]){
    int ost;
    int size = 0;
    while (decNum > 0){
        ost = decNum % toBase;
        if (ost >= 10 && ost <= 36){
            ost = (char)(ost+87);
        } else if (ost >= 36){
            ost = (char)(ost+29);
        } else {
            ost = (char)(ost + 48);
        }
        decNum /= toBase;
        // printf("%c dec: %d sise: %d\n", ost, decNum, size);
        arr[size] = ost; 
        size++;
    }
    return size;
}


int main(){
    int fromBase, toBase;
    scanf("%d %d ", &fromBase, &toBase);
    char cur;

    scanf("%c", &cur);
    int idx = 0;
    while (cur != EOF && cur != '\n'){
        int ascii_num = (int)cur;
        if (ascii_num < 65){
            cur = ascii_num - 48;
        } else if (ascii_num < 97){
            cur = ascii_num - 29;
        } else {
            cur = ascii_num - 87;
        }
        numArr[idx] = cur;
        idx += 1;
        scanf("%c", &cur);
    }

    int decNum = toDec(fromBase, numArr, idx);
    int size = convert(toBase, decNum, answArr);
    for (int i = size-1; i >= 0; i--){
        printf("%c", answArr[i]);
    }
}