#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node* prox;
}Node;

Node* Pilha_cria(void);
Node* Pilha_push(Node* p, int x);
Node* Pilha_pop(Node* p, int *ret);
int Pilha_Vazia(Node* p);
void Pilha_libera(Node* p);

Node* Pilha_cria(void){
    Node* p = (Node*) malloc(sizeof(Node));
    p = NULL;
    return p;
}

Node* Pilha_push(Node* p, int x){
    Node* novo_p = (Node*) malloc(sizeof(Node));
    novo_p->valor = x;
    novo_p->prox = p;
    return novo_p;
    // não precisa considerar caso em que p é vazio, pois, nesse caso, p == null, ou seja, novo_p vai apontar para null e ser o topo.
}

Node* Pilha_pop(Node* p, int *ret){
    if (!p){
        printf("Erro: pilha vazia");
        exit(-1);
    }
    *ret = p->valor;
    Node* aux = p;
    p = p->prox;
    free(aux);
}

int Pilha_Vazia(Node* p){
    return(!p);
}

void Pilha_libera(Node* p){
    while(p){
        Node* aux = p;
        p = p->prox;
        free(aux);
    }
}

void Pilha_imprime(Node* p){
    while(p){
        printf("%d\n", p->valor);
        p = p->prox;
    }
}

void main() {
    Node* pilha = Pilha_cria();
    pilha = Pilha_push(pilha, 0);
    pilha = Pilha_push(pilha, 1);
    pilha = Pilha_push(pilha, 2);
    pilha = Pilha_push(pilha, 3);
    pilha = Pilha_push(pilha, 4);
    pilha = Pilha_push(pilha, 5);
    Pilha_imprime(pilha);

}