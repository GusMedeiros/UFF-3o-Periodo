//
// Created by gustavo on 1/16/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "revisao_lista.c"

typedef struct pilha{
    TLSE *topo;
} TPilha;

TPilha* pilha_inicializa(){
    TPilha *pilha = (TPilha*) malloc(sizeof(TPilha));
    pilha->topo = NULL;
    return pilha;
}

TPilha* pilha_push(TPilha *pilha, int elem){
    if(pilha == NULL)
        pilha = pilha_inicializa();
    TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
    novo->val = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    return pilha;
}

int pilha_pop(TPilha *pilha) {
    if (!pilha->topo) exit(-1);
    TLSE *temp = pilha->topo;
    int val = temp->val;
    pilha->topo = pilha->topo->prox;
    free(temp);
    return val;
}

void pilha_print(TPilha* pilha) {
    TLSE *temp = pilha->topo;
    printf("[");
    if (!pilha->topo) {
        printf("]\n");
        return;
    }
    while (temp->prox){
        printf("%d, ", temp->val);
        temp = temp->prox;
    }
    printf("%d]\n", temp->val);
}

int pilha_peek(TPilha *pilha){
    if(!pilha->topo) exit(-1);
    return pilha->topo->val;
}

int main(void){
    TPilha *pil = pilha_inicializa();
    pilha_push(pil, 5);
    printf("Topo: %d\n", pilha_peek(pil));
    pilha_push(pil, 4);
    printf("Topo: %d\n", pilha_peek(pil));
    pilha_push(pil, 3);
    printf("Topo: %d\n", pilha_peek(pil));
    int info = pilha_pop(pil);
    printf("Removido: %d\n", info);
    pilha_print(pil);
}