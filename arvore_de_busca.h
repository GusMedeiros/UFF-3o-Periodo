#include<stdlib.h>
typedef struct ABB {
    int chave;
    struct ABB* esquerda;
    struct ABB* direita;
}ABB;
ABB* ABB_busca(ABB* raiz, int valor){
    if(raiz == NULL) return raiz;
    if(raiz->chave == valor) return raiz;
    if(valor > raiz->chave) return ABB_busca(raiz->direita, valor);
    if(valor < raiz->chave) return ABB_busca(raiz->esquerda, valor);
}
ABB* ABB_cria(int chave, ABB* esquerda, ABB* direita){
    ABB* nova_arvore = (ABB*) malloc(sizeof(ABB));
    nova_arvore->chave = chave;
    nova_arvore->esquerda = esquerda;
    nova_arvore->direita = direita;
    return nova_arvore;
}
ABB* ABB_insere(ABB* raiz, int valor){
    if(raiz == NULL) 
        return ABB_cria(valor, NULL, NULL);
    if(valor < raiz->chave)
        raiz->esquerda = ABB_insere(raiz->esquerda, valor);
    else if(valor > raiz->chave)
        raiz->direita = ABB_insere(raiz->direita, valor);
    return raiz;    
}

ABB* ABB_libera(ABB* raiz){
    if(raiz == NULL) return NULL;
    raiz->esquerda = ABB_libera(raiz->esquerda);
    raiz->direita = ABB_libera(raiz->direita);
    free(raiz);
    return NULL;
};

ABB* ABB_remove(ABB* raiz, int valor){
    if(raiz == NULL) return NULL; // caso mais simples
    if(valor < raiz->chave) raiz->esquerda = ABB_remove(raiz->esquerda, valor); // está à esquerda
    else if(valor > raiz->chave) raiz->direita = ABB_remove(raiz->direita, valor); // está à direita

    if(valor == raiz->chave){ // achou
        if(!raiz->direita && !raiz->esquerda){ // se for folha, pode simplesmente remover o nó sem consequências negativas
            free(raiz);
            return NULL; // como a função é sempre chamada atribuindo ao ponteiro raiz original, equivale a limpar o ponteiro que apontava para o elemento removido. 
        }
        else if(!raiz->direita || !raiz->esquerda){ // se não é folha, mas um deles não é nulo
            ABB* temp = raiz; 
            
            if(raiz->esquerda) raiz = raiz->esquerda; // como só tem uma subárvore, podemos fazer essa subárvore substituir a raiz removida sem consequências negativas
            else if(raiz->direita) raiz = raiz->direita; // igualmente
            free(temp);
            return raiz; // fazemos a raiz original apontar para o mesmo endereço da raiz local.
        }
        else { /* caso mais complexo, com duas subárvores.
            em vez de tentar substituir o nó, acharemos um descendente que, no pior dos casos, tem somente uma subárvore, e cujo valor pode ocupar
            a chave do nó a ser removido sem quebrar a coerência da árvore.
             esse valor pode ser ou o menor dentre os maiores, ou o maior dentre os menores. Há duas razões para isso:
            Escolheremos arbitrariamente o menor dentre os maiores:
            1. Não quebra a coerência da árvore:
            Como o valor está dentre os maiores que a chave, a subárvore esquerda não deixará de ser composta por valores menores que a chave.
            Como o valor é o menor dentre os maiores, por consequência todos os outros valores dentre os maiores continuam sendo maiores que a chave.
            2. Se ele é o menor valor, significa que não tem uma subárvore esquerda, do contrário haveriam valores menores que ele. Portanto, podemos
            removê-lo, já que se enquadrará, garantidamente, no caso 2 ou 1.

            Ou seja, em vez de remover a raiz encontrada, manipulamos a árvore de maneira inteligente:
            primeiro, substituiremos o valor da raiz encontrada pelo menor dos maiores ou maior dos menores, que, como explicado, mantém a árvore
            coerente.
            então, removeremos o nó que contém o maior dos menores/menor dos maiores, que garantidamente tem 1 ou menos subárvores. 
            */
            ABB** menor_dos_maiores = &raiz->direita;
            while((*menor_dos_maiores)->esquerda) menor_dos_maiores = &(*menor_dos_maiores)->esquerda;
            raiz->chave = (*menor_dos_maiores)->chave;
            *menor_dos_maiores = ABB_remove(*menor_dos_maiores, (*menor_dos_maiores)->chave);

        }
    }

    return raiz;
}


ABB* ABB_inicializa(){
    return NULL;
}
