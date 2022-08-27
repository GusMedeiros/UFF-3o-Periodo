#include <stdio.h>
#include <stdlib.h>
typedef struct teste{
    int* numero;
} Teste;

void main(){
    Teste teste;
    teste.numero = (int*) malloc(sizeof(int));
    *teste.numero = 4;
    printf("%d\n", *teste.numero);

    Teste* testedin = (Teste*) malloc(sizeof(Teste));
    testedin->numero = teste.numero;

    printf("%d\n", *testedin->numero);
}