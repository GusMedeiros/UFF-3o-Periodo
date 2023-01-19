#include <stdio.h>
#include <stdlib.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA *inicializa(void) {
    return NULL;
}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *criaNo(char ch) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void imprime_em_ordem(TNoA *raiz){
    if(!raiz) return;
    imprime_em_ordem(raiz->esq);
    printf("%c ", raiz->info);
    imprime_em_ordem(raiz->dir);
}

void imprime_pos_ordem(TNoA *raiz){
    if(!raiz) return;
    imprime_pos_ordem(raiz->esq);
    imprime_pos_ordem(raiz->dir);
    printf("%c ", raiz->info);
}
void imprime_legivel(TNoA *nodo, int altura) {
    if(nodo)
        imprime_legivel(nodo->dir, altura+1);
    for(int i=0; i<altura+1; i++){
        printf("    ");
    }
    if(!nodo){
        printf("N\n");
        return;
    }
    printf("%c\n", nodo->info);
    imprime_legivel(nodo->esq, altura+1);
}

int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    imprime_legivel(raiz, 0);
    printf("===============\n");
    printf("em ordem (simétrico):\n");
    imprime_em_ordem(raiz);
    printf("\n===============\n");
    printf("pós-ordem: \n");
    imprime_pos_ordem(raiz);
};