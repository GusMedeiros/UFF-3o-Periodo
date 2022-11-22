#include <stdio.h>
#include <stdlib.h>

void selectionsort_externo(FILE* fp){
    int r = 1;
    while(r == 1){
        int inicial_v;
        int inicial_i = ftell(fp);
        r = fread(&inicial_v, sizeof(int), 1, fp);
        printf("===================\ninicial = %d\n", inicial_v);
        int r2 = 1;
        int menor_v = inicial_v, menor_i = inicial_i;
        while(r2 == 1){
            int comp_v;
            int comp_i = ftell(fp);
            r2 = fread(&comp_v, sizeof(int), 1, fp);
            printf("%d | %d\n", comp_v, menor_v);
            if(comp_v < menor_v){
                menor_v = comp_v;
                menor_i = comp_i;
            }
        }//fim while 2
        printf("menor final: %d\n", menor_v);
        // colocando o inicial no lugar do menor de todos
        if(inicial_v > menor_v){
            fseek(fp, menor_i, SEEK_SET);
            fwrite(&inicial_v, sizeof(int), 1, fp);
            // colocando o menor no lugar do inicial
            fseek(fp, inicial_i, SEEK_SET);
            fwrite(&menor_v, sizeof(int), 1, fp);
        }
        // colocando o ponteiro após o inicial
        fseek(fp, inicial_i + sizeof(int), SEEK_SET);
        
    }
}

void escrever_inteiros(FILE* fp){
    int ints[] = {7, 3, 493, -450, 4};
    fwrite(&ints, sizeof(int), 5, fp);
}

void ler_inteiros(FILE* fp){
    int output;
    while(fread(&output,sizeof(int),1,fp)){
        printf("%d, ", output);
    }
    printf("\n");
}

void main(){
    FILE* fp = fopen("inteiros.bin", "wb");
    escrever_inteiros(fp);
    fclose(fp);

    printf("Antes:\n");
    fp = fopen("inteiros.bin", "rb");
    ler_inteiros(fp);
    fclose(fp);

    fp = fopen("inteiros.bin", "r+b");
    selectionsort_externo(fp);
    fclose(fp);

    fp = fopen("inteiros.bin", "rb");
    printf("Depois:\n");
    ler_inteiros(fp);
    fclose(fp);

}