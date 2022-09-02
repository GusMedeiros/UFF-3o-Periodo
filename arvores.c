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

char* TAB2str(TAB* ab){
    if(!ab) return "";
    return "[%d[%s][%s]]", ab->info, TAB2str(ab->esquerda), TAB2str(ab->direita);
}

int main(void){
    TAB *a3 = TAB_cria(3, NULL, NULL),
    *a4 = TAB_cria(4, NULL, NULL),
    *a5 = TAB_cria(5, NULL, NULL),    *a2 = TAB_cria(2, a4, a5),
    *raiz = TAB_cria(1, a2, a3);
    printf("%s", TAB2str(raiz));
    return 0;
}