//
// Created by gustavo on 1/16/23.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct ponto2d{
    float x;
    float y;
} Ponto2d;

int main(void){
    struct ponto2d p;
    Ponto2d *p2 = (Ponto2d*) malloc(sizeof(Ponto2d));
    printf("Insira o ponto p\n");
    scanf("%f %f", &p.x, &p.y);
    printf("ponto p: (%.2f, %.2f)\n", p.x, p.y);

    printf("Insira o ponto p2\n");
    scanf("%f %f", &p2->x, &p2->y);
    printf("ponto p2: (%.2f, %.2f)\n", p2->x, p2->y);
    printf("ponto p2 acessado por *: (%.2f, %.2f)\n", (*p2).x, (*p2).y);
    return 0;
}