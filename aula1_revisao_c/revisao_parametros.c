#include <stdio.h>

void troca_por_valor(int px, int py){
   int temp;
   temp = px;
   px = py;
   py = temp;
}

void troca_por_referencia(int *px, int *py){
    int temp = *px;
    *px = *py;
    *py = temp;
}

int main(void){
    int a = 5, b = 7;
    troca_por_valor(a, b);
    printf("a = %d, b = %d\n", a, b); // não troca pois mandou copia do valor
    troca_por_referencia(&a, &b);
    printf("a = %d, b = %d\n", a, b); // troca pois mandou a referencia da variavel
    return 0;
}