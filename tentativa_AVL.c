#include <stdio.h>
#include <stdlib.h>

typedef struct AVL {
    int chave;
    struct AVL* esquerda;
    struct AVL* direita;
    int altura;
} AVL;

AVL* AVL_inicializa(){
    return NULL;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int AVL_altura(AVL* raiz){
    if(raiz == NULL) return 0;
    return 1 + max(AVL_altura(raiz->esquerda), AVL_altura(raiz->direita));
}

int AVL_fator_balanceamento(AVL* raiz){
    if(raiz == NULL) return 0;
    return AVL_altura(raiz->esquerda) - AVL_altura(raiz->direita);
}

AVL* AVL_rotacao_direita(AVL* raiz){
    // 1. fazer a rotação em si
    AVL* temp = raiz;
    raiz = raiz->esquerda;
    temp->esquerda = raiz->direita; // transplante de membro
    raiz->direita = temp; // transplante de membro

    // 2. atualizar as alturas.    

    // que árvores precisam ser atualizadas?
    // as árvores que foram somente movidas continuam tendo a mesma altura, porém as árvores que sofreram transplantes mudaram de altura.
    // as árvores que tiveram membros mudados foram temp e raiz. todas as outras subárvores apenas foram movidas.
    raiz->altura = AVL_altura(raiz);
    temp->altura = AVL_altura(temp); 
    return raiz;

}

AVL* AVL_rotacao_esquerda(AVL* raiz){
    // 1. fazer a rotação em si
    AVL* temp = raiz;
    raiz = raiz->direita;
    temp->direita = raiz->esquerda; // temp teve um membro transplantado
    raiz->esquerda = temp; // raiz teve um membro transplantado

    // 2. atualizar as alturas.    

    // que árvores precisam ser atualizadas?
    // as árvores que foram somente movidas continuam tendo a mesma altura, porém as árvores que sofreram transplantes mudaram de altura.
    // as árvores que tiveram membros mudados foram temp e raiz. todas as outras subárvores apenas foram movidas.
    raiz->altura = AVL_altura(raiz);
    temp->altura = AVL_altura(temp); 
    return raiz;
}

AVL* AVL_cria(AVL* raiz, int valor){
    raiz = (AVL*) malloc(sizeof(AVL));
    raiz->esquerda = NULL;
    raiz->direita = NULL;
    raiz->chave = valor;
    raiz->altura = 0;
    return raiz;
}

AVL* AVL_remove(AVL* raiz, int valor){
    // 1. Fazer remoção BST normal
    if(raiz == NULL) return NULL;
    if(valor > raiz->chave){
        raiz->direita = AVL_remove(raiz->direita, valor);
    }
    else if(valor < raiz->chave){
        raiz->esquerda = AVL_remove(raiz->esquerda, valor);
    }
    else{ // nó igual encontrado, é o nó a ser removido
        if(!raiz->direita || !raiz->esquerda){
            if(raiz->direita){
                AVL* temp = raiz->direita;
                free(raiz);
                raiz = temp;
            }
            else if(raiz->esquerda){
                AVL* temp = raiz->esquerda;
                free(raiz);
                raiz = temp;
            }
            else{
                free(raiz);
                raiz = NULL;
            }
        }
        else{ // 2 filhos
            AVL* temp = raiz->direita; // temp se torna maior que a raiz
            while(temp->esquerda) temp = temp->esquerda; // temp é o menor dos maiores
            raiz->chave = temp->chave;
            raiz->direita = AVL_remove(raiz->direita, temp->chave);
        }
    }

    // 2. Atualizar alturas
    raiz->altura = AVL_altura(raiz);

    int balanceamento = AVL_fator_balanceamento(raiz);
    int balanceamento_direita = AVL_fator_balanceamento(raiz->direita);
    int balanceamento_esquerda = AVL_fator_balanceamento(raiz->esquerda);

    // LL
    if(balanceamento == 2 && balanceamento_esquerda == 1){
        raiz = AVL_rotacao_direita(raiz);
    }
    // LR
    else if(balanceamento == 2 && balanceamento_esquerda == -1){
        raiz = AVL_rotacao_esquerda(raiz);
        raiz = AVL_rotacao_direita(raiz);
    }
    else if(balanceamento == -2 && balanceamento_direita == -1)

    return raiz;

}

AVL* AVL_insere(AVL* raiz, int valor){
    // 1. Fazer a inserção BST normal
    if(raiz == NULL){
        raiz = AVL_cria(raiz, valor);
    }
    else if(valor > raiz->chave){
        raiz->direita = AVL_insere(raiz->direita, valor);
    
    }
    else if(valor < raiz->chave){ 
        raiz->esquerda = AVL_insere(raiz->esquerda, valor);
    }
    else{
        return raiz;
    }// valores iguais não são permitidos

    // 2. Atualizar altura do nó
    raiz->altura = AVL_altura(raiz);
    
    // 3. checar balanceamento e balancear de acordo
    int balanceamento = AVL_fator_balanceamento(raiz);
    // existem 4 casos, baseados no caminho até o nó inserido:
    // LL : duas esquerdas, nesse caso o fator da raiz será >= 2 e o do filho será >=1
    if(balanceamento == 2 && AVL_fator_balanceamento(raiz->esquerda) == 1){
        raiz = AVL_rotacao_direita(raiz);
    }
    // RR : duas direitas
    else if(balanceamento == -2 && AVL_fator_balanceamento(raiz->direita) == -1){
        raiz = AVL_rotacao_direita(raiz);
    }
    // LR : esquerda direita
    else if(balanceamento == 2 && AVL_fator_balanceamento(raiz->esquerda) == -1){
        raiz->esquerda = AVL_rotacao_esquerda(raiz->esquerda);
        raiz = AVL_rotacao_direita(raiz);
    }
    // RL : direita esquerda
    else if(balanceamento == -2 && AVL_fator_balanceamento(raiz->direita) == 1){
        raiz->direita = AVL_rotacao_direita(raiz->direita);
        raiz = AVL_rotacao_esquerda(raiz->esquerda);
    }
    return raiz;

}
void AVL_print_line(AVL* ab){
    printf("[");
    if(ab==NULL){
        printf("]");
        return;
    }
    printf("%d", ab->chave);
    AVL_print_line(ab->esquerda);
    AVL_print_line(ab->direita);
    printf("]");
}

void main(){
    AVL* arvore = AVL_inicializa();
    arvore = AVL_insere(arvore, 40);
    arvore = AVL_insere(arvore, 30);
    arvore = AVL_insere(arvore, 35);
    AVL_print_line(arvore);
    printf("\n");
    arvore = AVL_insere(arvore, 5);
    arvore = AVL_insere(arvore, 4);
    arvore = AVL_insere(arvore, 3);
    arvore = AVL_insere(arvore, 2);
    arvore = AVL_insere(arvore, 1);

    AVL_print_line(arvore);
    printf("\n");

}