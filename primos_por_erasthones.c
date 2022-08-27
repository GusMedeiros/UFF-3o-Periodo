#include <stdio.h>
#include <stdlib.h>

int* Vetor_new(int* vetor, int tamanho);
int Vetor_pop(int* vetor, int indice_alvo, int* tamanho);
int Vetor_remove(int* vetor, int valor, int* tamanho);
void Vetor_imprime(int* vetor, int tamanho);

int* preencher_erasthones(int* vetor, int tamanho);
int* erasthones(int* vetor, int* tamanho);

int* Vetor_new(int* vetor, int tamanho){
    vetor = (int*) malloc(sizeof(int) * tamanho);
    return vetor;
}
int Vetor_pop(int* vetor, int indice_alvo,int* tamanho){    
    int valor_removido = vetor[indice_alvo];
    for(int i=indice_alvo;i<*tamanho;i++){
        vetor[i] = vetor[i+1];
    }
    (*tamanho)--;
    return valor_removido;
}
int Vetor_remove(int* vetor, int valor, int* tamanho){
    for(int i=0; i<*tamanho; i++){
        if(vetor[i]==valor){
            Vetor_pop(vetor, i, tamanho);
            return i;
        }
    }
}
void Vetor_imprime(int* vetor, int tamanho){
    printf("[");
    for(int i=0; i<tamanho-1; i++){
        printf("%d, ", vetor[i]);
    }
    printf("%d]\n", vetor[tamanho-1]);
}

int* preencher_erasthones(int* vetor, int tamanho){
    for(int i=0;i<tamanho;i++){
        vetor[i] = i+2;
        if(i == tamanho-1){
        }
    }
    return vetor;
}

int* erasthones(int* vetor, int* tamanho){
    int maior_numero = *tamanho + 1;
    for(int i=0; i<*tamanho; i++){
        int num_atual = vetor[i];
        int multiplo_atual = num_atual * 2;
        while(multiplo_atual <= maior_numero){
            printf("%d\n", i);
            Vetor_imprime(vetor, *tamanho);
            Vetor_remove(vetor, multiplo_atual,tamanho);
            multiplo_atual += num_atual;
        }
    }
    return vetor;
}
void main(){
    int numero;
    printf("Insira um numero inteiro, e lhe direi quais os primos que vem antes dele.\n");
    scanf("%d", &numero);
    fflush(stdin);
    
    int *primos = NULL, tamanho_primos = numero - 1;
    primos = Vetor_new(primos, tamanho_primos);
    primos = preencher_erasthones(primos, tamanho_primos);
    primos = erasthones(primos, &tamanho_primos);
    printf("total de primos = %d\n", tamanho_primos);
    Vetor_imprime(primos, tamanho_primos);
}