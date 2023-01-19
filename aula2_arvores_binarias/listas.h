//
// Created by gustavo on 1/17/23.
//

#ifndef UFF_3_ESTRUTURAS_DE_DADOS_E_SEUS_ALGORITMOS_LISTAS_H
#define UFF_3_ESTRUTURAS_DE_DADOS_E_SEUS_ALGORITMOS_LISTAS_H

#endif //UFF_3_ESTRUTURAS_DE_DADOS_E_SEUS_ALGORITMOS_LISTAS_H
//
// Created by gustavo on 1/16/23.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct listaNoA {
    TNoA *no;
    struct listaNoA *prox;
} TLSE;


TLSE *lista_cria(){
    return NULL;
}

TLSE *lista_insere_fim(TLSE *lista, TNoA val) {
    if (!lista) {
        lista = (TLSE *) malloc(sizeof(TLSE));
        lista->no = val;
        lista->prox = NULL;
        return lista;
    }
    TLSE *temp = lista;
    while (temp->prox != NULL)
        temp = temp->prox;
    temp->prox = (TLSE *) malloc(sizeof(TLSE));
    temp->prox->no = val;
    temp->prox->prox = NULL;
    return lista;
}

TLSE *lista_insere_fim_recursivo(TLSE *lista, TNoA val){
    if(!lista){
        TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
        novo->no = val;
        novo->prox = NULL;
        return novo;
    }
    lista->prox = lista_insere_fim_recursivo(lista->prox, val);
    return lista;
}

TLSE *lista_insere_inicio(TLSE *lista, int val){
    TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
    novo->no = val;
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
        printf("%d, ", lista->no);
        lista = lista->prox;
    }
    printf("%d]\n", lista->no->info);
}