//
// Created by gustavo on 1/16/23.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int val;
    struct lista *prox;
} TLSE;


TLSE *lista_cria(){
    return NULL;
}

TLSE *lista_insere_fim(TLSE *lista, int val) {
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

TLSE *lista_insere_fim_recursivo(TLSE *lista, int val){
    if(!lista){
        TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
        novo->val = val;
        novo->prox = NULL;
        return novo;
    }
    lista->prox = lista_insere_fim_recursivo(lista->prox, val);
    return lista;
}

TLSE *lista_insere_inicio(TLSE *lista, int val){
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
        printf("%d, ", lista->val);
        lista = lista->prox;
    }
    printf("%d]\n", lista->val);
}
/*
int main(void){
    TLSE *lista = lista_cria();
    for(int i=0; i<10; i++){
        lista = lista_insere_fim_recursivo(lista, i);
    }
    lista_print(lista);
    return 0;

}
*/