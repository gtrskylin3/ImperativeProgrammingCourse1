#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fp = fopen("temp.bin", "wb");
    int i = 10;
    double pi = 3.1415921825904590;
    char C = 'c';
    
    fwrite(&i, sizeof(i), 1, fp);
    fwrite(&pi, sizeof(pi), 1, fp);
    fwrite(&C, sizeof(C), 1, fp);
    
    fclose(fp);
    
    FILE* fp2 = fopen("temp.bin", "rb");
    int ix ;
    double pix ;
    char Cx ;
    
    fread(&ix, sizeof(ix), 1, fp2);
    fread(&pix, sizeof(pix), 1, fp2);
    fread(&Cx, sizeof(Cx), 1, fp2);
    printf("%d %lf %c\n", ix, pix, Cx);


    fclose(fp2);

}