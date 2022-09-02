#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valor;
    struct node *prox;
} Node;

Node *inserir_inicio(Node *lista, int x)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->valor = x;
    novo->prox = lista;
    return novo;
}

Node *inserir_fim(Node *lista, int x)
{
    Node *ultimo = lista;
    while (lista->prox)
    {
        ultimo = ultimo->prox;
    }
    ultimo->prox = inserir_inicio(NULL, x);
    return lista;
}

Node *inserir_fim_recursivo(Node *lista, int x)
{
    if (!lista)
        return inserir_inicio(lista, x);

    lista->prox = inserir_fim_recursivo(lista->prox, x);
    return lista;
}

Node *inserir_ordenadamente(Node *lista, int x)
{
    if (!lista)
        return inserir_inicio(lista, x);
    Node *node_atual = lista;
    Node *node_anterior = NULL;
    while(x > node_atual->valor){
        node_anterior = node_atual;
        node_atual = node_atual->prox;
    }
    if(!node_anterior){
        lista = inserir_inicio(node_atual, x);
        return lista;
    }

    node_anterior->prox = inserir_inicio(node_atual, x);
    return lista;
}

void imprimir_lista(Node *lista)
{
    Node *aux = lista;
    while (aux)
    {
        printf("%d->", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}
void main()
{
    Node *lista = NULL;
    lista = inserir_ordenadamente(lista, 5);
    lista = inserir_ordenadamente(lista, 3);
    lista = inserir_ordenadamente(lista, 4);
    lista = inserir_ordenadamente(lista, 2);
    lista = inserir_ordenadamente(lista, 1);
    lista = inserir_ordenadamente(lista, 3);

    imprimir_lista(lista);
}
