#include <stdio.h>
#include <stdlib.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;
typedef struct lista_noA{
    TNoA *val;
    struct lista_noA *prox;
} TLSE;

typedef struct fila_noA{
    TLSE *inicio;
    TLSE *fim;
} TFila;

TLSE *lista_cria(){
    return NULL;
}

TLSE *lista_insere_fim(TLSE *lista, TNoA *val) {
    if (!lista) {
        lista = (TLSE *) malloc(sizeof(TLSE));
        lista->val = val;
        lista->prox = NULL;
        return lista;
    }
    TLSE *temp = lista;
    while (temp->prox != NULL)
        temp = temp->prox;
    temp->prox = (TLSE *) malloc(sizeof(TLSE));
    temp->prox->val = val;
    temp->prox->prox = NULL;
    return lista;
}

TLSE *lista_insere_fim_recursivo(TLSE *lista, TNoA *val){
    if(!lista){
        TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
        novo->val = val;
        novo->prox = NULL;
        return novo;
    }
    lista->prox = lista_insere_fim_recursivo(lista->prox, val);
    return lista;
}

TLSE *lista_insere_inicio(TLSE *lista, TNoA *val){
    TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
    novo->val = val;
    novo->prox = lista; // se lista for null, tudo certo, vai apontar pra null.
    return novo;


}

void lista_print(TLSE *lista){
    printf("[");
    if(!lista) {
        printf("]\n");
        return;
    }

    while(lista->prox){
        printf("%c, ", lista->val->info);
        lista = lista->prox;
    }
    printf("%c]\n", lista->val->info);
}

TFila *fila_inicializa(){
    TFila *fila = (TFila*) malloc(sizeof(TFila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

TFila * fila_insere(TFila *fila, TNoA *val){
    if(!fila) exit(-1);
    if(!fila->inicio){
        fila->inicio = (TLSE*) malloc(sizeof(TLSE));
        fila->inicio->val = val;
        fila->fim = fila->inicio;
        return fila;
    }
    fila->fim->prox = (TLSE *) malloc(sizeof(TLSE));
    fila->fim = fila->fim->prox;
    fila->fim->val = val;
    fila->fim->prox = NULL;
    return fila;
}

void fila_print(TFila *fila){
    if(!fila) exit(-1);
    lista_print(fila->inicio);
}

TNoA *fila_retira(TFila *fila){
    if(!fila || !fila->inicio) exit(-1);
    TLSE *temp = fila->inicio;
    TNoA *val = temp->val;
    fila->inicio = temp->prox;
    free(temp);
    if(!fila->inicio)
        fila->fim = NULL;
    return val;
}

int fila_vazia(TFila *fila){
    return (fila->inicio == NULL);
}

TNoA *inicializa(void) {
    return NULL;
}

void imprime(TNoA *nodo, int altura) {
    if(nodo)
        imprime(nodo->dir, altura+1);
    for(int i=0; i<altura+1; i++){
        printf("    ");
    }
    if(!nodo){
        printf("N\n");
        return;
    }
    printf("%c\n", nodo->info);
    imprime(nodo->esq, altura+1);
}

void imprime_largura(TNoA *nodo){
    TFila *fila = fila_inicializa();
    fila = fila_insere(fila, nodo);
    while(!fila_vazia(fila)){
        fila_print(fila);
        printf("inserindo %c\n", fila->inicio->val->esq->info);
        fila = fila_insere(fila, fila->inicio->val->esq);
        printf("inserindo %c\n", fila->inicio->val->dir->info);
        fila = fila_insere(fila, fila->inicio->val->dir);
        printf("Removendo %c\n", fila_retira(fila)->info);
        //printf("%c, ", fila_retira(fila)->info);
    }
    fila_print(fila);
    printf("\n");
}


TNoA *criaNo(char ch) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('D');
    raiz->dir->esq = criaNo('F');
    raiz->dir->dir = criaNo('G');
    raiz->esq->esq = criaNo('E');
    imprime(raiz, 0);
    printf("======================\n");
    printf("largura:\n");
    imprime_largura(raiz);
}