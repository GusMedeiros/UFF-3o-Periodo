#include <stdio.h>
#include <stdlib.h>
void main(){
    FILE* fp = fopen("inteiros.bin", "wb");
    int ints[] = {10,9,8,7,6,5};
    fwrite(&ints, sizeof(int), 6, fp);
    fclose(fp);
}