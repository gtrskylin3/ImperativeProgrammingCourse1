#include <stdio.h>

int main(){
    const char* phones[][5] = {
        {"8", "913", "478", "18", "95"},
        {"8", "913", "394", "47", "06"},
        {"+7", "913", "478", "18", "95"},
        {"+7", "913", "394", "47", "06"}
    };

    FILE* fp = fopen("write_phones.txt", "w");

    if (!fp){
        perror("write_phones.txt");
        return 1;
    }
    for (int i = 0; i < sizeof(phones) / sizeof(*phones); ++i){
        fprintf(fp, "%s(%s)%s-%s-%s\n", 
            phones[i][0], 
            phones[i][1], 
            phones[i][2], 
            phones[i][3], 
            phones[i][4]
        );
    }
    fclose(fp);
}