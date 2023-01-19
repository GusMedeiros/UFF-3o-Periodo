#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

void imprime_legivel(TNoA *nodo, int altura) {
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

TNoA *tNoA_busca(TNoA *raiz, int chave){
    if(!raiz) return NULL;
    if(raiz->chave == chave) return raiz;
    if(chave < raiz->chave) return tNoA_busca(raiz->esq, chave);
    return tNoA_busca(raiz->dir, chave);
}

TNoA *tNoA_insere(TNoA *raiz, int chave){
    if(!raiz){
        raiz = (TNoA *) malloc(sizeof(TNoA));
        raiz->chave = chave;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }
    else if(chave < raiz->chave)
        raiz->esq = tNoA_insere(raiz->esq, chave);
    else if(chave > raiz->chave)
        raiz->dir = tNoA_insere(raiz->dir, chave);
    return raiz;
}
TNoA *TnoA_remove(TNoA *no, int chave){
    if(!tNoA_busca(no, chave)) return no;
    if(chave == no->chave){
        printf("chave encontrada, ");
        if(!no->esq && !no->dir){
            free(no);
            printf("retornando null\n");
            return NULL;
        }
        if(no->esq && !no->dir){
            TNoA *aux = no->esq;
            free(no);
            printf("retornando aux (esq && !dir)\n");
            return aux;
        }
        if(!no->esq && no->dir){
            TNoA *aux = no->dir;
            free(no);
            printf("retornando aux (!esq && dir)\n");
            return aux;
        }
        if(no->esq && no->dir){
            TNoA *maior_imediato = no->dir;
            while(maior_imediato->esq)
                maior_imediato = maior_imediato->esq;
            no->chave = maior_imediato->chave;
            no->dir = TnoA_remove(no->dir, maior_imediato->chave);
            printf("retornando nó (esq && dir)\n");
            return no;
        }
    }
    if(chave > no->chave) {
        printf("acessando maior\n");
        no->dir = TnoA_remove(no->dir, chave);
    }
    if(chave < no->chave) {
        printf("acessando menor\n");
        no->esq = TnoA_remove(no->esq, chave);
    }
    return no;
}


TNoA *vetor_ordenado_para_arvore(TNoA *raiz, int* vetor, int i_inicial, int i_final){
    // inseriremos sempre o inteiro do meio, dessa forma, podemos chamar a recursão para o lado esquerdo e direito
    if(i_inicial <= i_final){
        int meio = (i_inicial + i_final) / 2;
        if(!raiz)// raiz aqui é realmente a raiz, não o nó atual. portanto, se não tiver raiz, precisamos criá-la.
            raiz = tNoA_insere(raiz, vetor[meio]);
        else tNoA_insere(raiz, vetor[meio]); // se tiver raiz, não precisamos atualizar o valor da raiz.
        vetor_ordenado_para_arvore(raiz, vetor, i_inicial, meio - 1); // chamamos a recursão para a metade esquerda do vetor
        vetor_ordenado_para_arvore(raiz, vetor, meio + 1, i_final); // chamamos a recursão para a metade direita do vetor
    }
    return raiz;
}

int main(void){
    /*
    TNoA *raiz = NULL;
    raiz = tNoA_insere(raiz, 25);
    raiz = tNoA_insere(raiz, 22);
    raiz = tNoA_insere(raiz, 20);
    raiz = tNoA_insere(raiz, 21);
    raiz = tNoA_insere(raiz, 27);
    raiz = tNoA_insere(raiz, 40);
    raiz = tNoA_insere(raiz, 30);
    raiz = tNoA_insere(raiz, 45);
    raiz = tNoA_insere(raiz, 48);
    imprime_legivel(raiz, 0);
    */
    TNoA *raiz = NULL;
    int v[7] = {150, 300, 400, 500, 600, 800, 900};
    raiz = vetor_ordenado_para_arvore(raiz,v,0,7-1);
    imprime_legivel(raiz, 0);
    printf("=======================\n");
    raiz = TnoA_remove(raiz, 300);
    imprime_legivel(raiz, 0);
}
