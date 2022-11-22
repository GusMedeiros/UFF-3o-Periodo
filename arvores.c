#include <stdlib.h>
#include <stdio.h>
typedef struct arvore_binaria{
    struct arvore_binaria* esquerda, *direita;
    int info;
} TAB;

TAB* TAB_inicializa(void){
    return NULL;
}

TAB* TAB_cria(int info, TAB* esquerda, TAB* direita){
    TAB* novo = (TAB*) malloc(sizeof(TAB)); // aloca arvore binaria
    novo->info = info;
    novo->esquerda = esquerda;
    novo->direita = direita; 
    return novo;
}

TAB *vet2ab(int* vet, int n){ // funcao que pega o meio do vetor, cria uma árvore com aquele valor.
    if(n<=0) return NULL;
    return TAB_cria(vet[n/2], vet2ab(vet, n/2 - 1), vet2ab(&vet[n/2 + 1], n/2));
}

void TAB_print_line(TAB* ab){
    printf("[");
    if(ab == NULL){
        printf("]");
        return;
    }
    printf("%d", ab->info);
    TAB_print_line(ab->esquerda);
    TAB_print_line(ab->direita);
    printf("]");

}

int main(void){
    TAB* tab15 = TAB_cria(15, NULL, NULL);
    TAB* tab25 = TAB_cria(25, NULL, NULL);
    TAB* tab35 = TAB_cria(35, NULL, NULL);
    TAB* tab45 = TAB_cria(45, NULL, NULL);
    TAB* tab20 = TAB_cria(20, tab15, tab25);
    TAB* tab40 = TAB_cria(40, tab35, tab45);
    TAB* tab30 = TAB_cria(30, tab20, tab40);
    TAB_print_line(tab30);
    return 0;
}