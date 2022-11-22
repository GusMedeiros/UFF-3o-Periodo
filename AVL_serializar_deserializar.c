#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void AVL_serializa(FILE*f, AVL* raiz){
    if(!raiz) return;
    fwrite(raiz, sizeof(AVL), 1, f);
    AVL_serializa(f, raiz->esquerda);
    AVL_serializa(f, raiz->direita);

}

AVL* AVL_deserializa(FILE* f, AVL* raiz){
    if(!raiz) raiz = AVL_aloca();

    fread(raiz, sizeof(AVL), 1, f);
    if(raiz->esquerda) {
        raiz->esquerda = AVL_aloca();
        raiz->esquerda = AVL_deserializa(f, raiz->esquerda);
    }
    if(raiz->direita) {
        raiz->direita = AVL_aloca();
        raiz->direita = AVL_deserializa(f, raiz->direita);
    }
    return raiz;
}

void main(){
    AVL* arvore = AVL_inicializa();
    arvore = AVL_insere(arvore, 5);
    arvore = AVL_insere(arvore, 7);
    arvore = AVL_insere(arvore, 6);
    arvore = AVL_insere(arvore, 4);
    arvore = AVL_insere(arvore, 3);
    arvore = AVL_insere(arvore, 2);
    arvore = AVL_insere(arvore, 1);


    FILE* f = fopen("AVLs_serializadas.bin", "wb");
    AVL_serializa(f, arvore);
    fclose(f);
    printf("Serializado.\n");
    AVL_print_line(arvore);
    printf("\n");
    f = fopen("AVLs_serializadas.bin", "rb");
    AVL* arvoreCopia = AVL_inicializa();
    arvoreCopia = AVL_deserializa(f, arvoreCopia);
    printf("Deserializado.\n");
    AVL_print_line(arvoreCopia);
    
}