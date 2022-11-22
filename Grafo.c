#include <stdio.h>
#include <stdlib.h>

typedef struct vizinho{
    int id_vizinho;
    struct vizinho *prox_vizinho;
} Vizinho;


typedef struct grafo{
    int id_grafo;
    Vizinho *lista_ligada_vizinho;
    struct grafo* prox_grafo;
} TG;

TG* TG_inicializa(){
    return NULL;
}

void vizinho_libera(Vizinho* viz){
    if(!viz) return;
    vizinho_libera(viz->prox_vizinho);
    free(viz);
}


void TG_libera(TG* g){
    if(!g) return;
    TG_libera(g->prox_grafo);
    vizinho_libera(g->lista_ligada_vizinho);
    free(g);
}

TG* busca_no(TG* g, int x){
    if(!g || g->id_grafo == x) return g;
    return busca_no(g->prox_grafo, x);
}

Vizinho* busca_aresta(TG*g, int x, int y){
    // retorna aresta que vai de x até y.
    if(!g) return NULL;
    TG* g1 = busca_no(g, x);
    TG* g2 = busca_no(g, y);
    if(!g1 || !g2) return NULL;

    Vizinho* temp = g1->lista_ligada_vizinho;
    
    while(temp && temp->id_vizinho != y) temp = temp->prox_vizinho;
    return temp;
}

TG* TG_ins_no(TG* g, int x){
    TG* temp = busca_no(g, x);
    if(temp) return g;
    temp = (TG*) malloc(sizeof(TG));
    temp->id_grafo = x;
    temp->lista_ligada_vizinho = NULL;
    temp->prox_grafo = g;
    return temp;
}

TG* TG_cria(int x){
    TG* g = (TG*) malloc(sizeof(TG));
    g->id_grafo = x;
    g->lista_ligada_vizinho = NULL;
    g->prox_grafo = NULL;
    return g;
}