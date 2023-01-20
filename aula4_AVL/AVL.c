//
// Created by gustavo on 1/19/23.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct avl {
    int chave;
    int fb;
    struct avl *esq;
    struct avl *dir;
} TNoAVL;

TNoAVL *rotacao_direita(TNoAVL *raiz){
    printf("rd\n");
    if(!raiz) return NULL;
    TNoAVL *aux = raiz;
    TNoAVL *aux2 = raiz->esq->dir;
    raiz = raiz->esq;
    raiz->dir = aux;
    aux->esq = aux2;
    return raiz;
}

TNoAVL *rotacao_esquerda(TNoAVL *raiz){
    printf("re\n");
    if(!raiz) return NULL;
    TNoAVL *aux = raiz;
    TNoAVL *aux2 = raiz->dir->esq;
    raiz = raiz->dir;
    raiz->esq = aux;
    raiz->esq->dir = aux2;
    return raiz;
}

int max(int a, int b){
    if(a >= b) return a;
    return b;
}

int altura_aux(TNoAVL *raiz, int h){
    printf("calculando altura\n");
    if(!raiz) {
        printf("null. retornando %d\n", h);
        return h; }
    int altura = max(altura_aux(raiz->esq, h+1), altura_aux(raiz->dir, h));
    printf("o nível de %d é %d\n", raiz->chave, altura);
    return altura;
}

int altura(TNoAVL *raiz){
    return altura_aux(raiz, 0);
}

void atualizar_fb(TNoAVL *raiz){
    if(!raiz) return;
    raiz->fb = altura(raiz->esq) - altura(raiz->dir);
    atualizar_fb(raiz->esq);
    atualizar_fb(raiz->dir);
    printf("a");
}


TNoAVL *inserir(TNoAVL *raiz, int chave){
    printf("a\n");
    if(!raiz){
        raiz = (TNoAVL *) malloc(sizeof(TNoAVL));
        raiz->esq = NULL;
        raiz->dir = NULL;
        raiz->chave = chave;
        raiz->fb = 0;
    }
    if(chave < raiz->chave) {
        printf("acessando esquerda\n");
        raiz->esq = inserir(raiz->esq, chave);
    }
    else if(chave > raiz->chave) {
        printf("acessando direita\n");
        raiz->dir = inserir(raiz->dir, chave);
    }
    else
        return raiz;
    printf("atualizando fb de %d\n", raiz->chave);
    atualizar_fb(raiz);

    if(raiz->fb == -2){ // L
        if(raiz->esq->fb == -1) { // LL
            printf("caso LL\n");
            raiz = rotacao_direita(raiz);
        }
        if(raiz->esq->fb == 1){ // LR
            printf("caso LR\n");
            raiz->esq = rotacao_esquerda(raiz->esq);
            raiz = rotacao_direita(raiz);
        }
    }
    else if(raiz->fb == 2){ // R
        if(raiz->esq->fb == -1){// RL
            printf("caso RL\n");
            raiz->dir = rotacao_direita(raiz->dir);
            raiz = rotacao_esquerda(raiz);
        }
        if(raiz->dir->fb == 1){ // RR
            printf("caso RR\n");
            raiz = rotacao_esquerda(raiz);
        }
    }
    return raiz;
}

void imprime_legivel(TNoAVL *nodo, int altura) {
    if(nodo)
        imprime_legivel(nodo->dir, altura+1);
    for(int i=0; i<altura+1; i++){
        printf("     ");
    }
    if(!nodo){
        printf("N\n");
        return;
    }
    printf("%d\n", nodo->chave);
    imprime_legivel(nodo->esq, altura+1);
}

int main(void){
    TNoAVL *raiz = NULL;
    raiz = inserir(raiz, 50);
    imprime_legivel(raiz, 0);
    raiz = inserir(raiz, 40);
    imprime_legivel(raiz, 0);
    raiz = inserir(raiz, 30);
    imprime_legivel(raiz, 0);
    raiz = inserir(raiz, 45);
    imprime_legivel(raiz, 0);
    raiz = inserir(raiz, 47);
    imprime_legivel(raiz, 0);
    raiz = inserir(raiz, 55);
    imprime_legivel(raiz, 0);
    raiz = inserir(raiz, 56);
    imprime_legivel(raiz, 0);

}
