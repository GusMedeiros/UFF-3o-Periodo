//
// Created by gustavo on 1/16/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "revisao_lista.c"

typedef struct fila {
    TLSE *inicio;
    TLSE *fim;
} TFila;

TFila *fila_inicializa(){
    TFila *fila = (TFila*) malloc(sizeof(TFila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

TFila * fila_insere(TFila *fila, int val){
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

int fila_retira(TFila *fila){
    if(!fila || !fila->inicio) exit(-1);
    TLSE *temp = fila->inicio;
    int val = temp->val;
    fila->inicio = temp->prox;
    free(temp);
    if(!fila->inicio)
        fila->fim = NULL;
    return val;
}

int main(){
    TFila *fila = fila_inicializa();
    for(int i=1; i<11; i++)
      fila_insere(fila, i);
    for(int i=0; i<5; i++)
        fila_retira(fila);
    fila_print(fila);
}