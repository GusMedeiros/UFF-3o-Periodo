#include <stdio.h>
#include <stdlib.h>

void Vetor_imprime(double* vetor, int tamanho){
    printf("[");
    for(int i=0; i<tamanho-1; i++){
        printf("%.5lf, ", vetor[i]);
    }
    printf("%.5lf]\n", vetor[tamanho-1]);
}

double* Polinomio_derivar(double* vetor, int* tamanho){
    double* novo_vetor = (double*) malloc(sizeof(double) * (*tamanho-1));
    if(!novo_vetor){
        printf("ERRO ALOCANDO MEMORIA");
        exit(-1);
    }
    int grau = *tamanho-1;

    for(int i=0; i<*tamanho-1; i++){
        novo_vetor[i] = vetor[i] * (grau-i);
    }
    if(*tamanho < 0) *tamanho = 0;
    return novo_vetor;
}

double* Polinomio_integrar(double* vetor, int* tamanho){
    double* novo_vetor = (double*) malloc(sizeof(double) * (*tamanho+1));
    if(!novo_vetor){
        printf("ERRO ALOCANDO MEMORIA");
        exit(-1);
    }
    int grau = *tamanho-1;
    for(int i=0; i<*tamanho; i++){
        novo_vetor[i] = vetor[i]/(grau-i+1);
    }
    return novo_vetor;
}
void main(){
    int grau;
    while(grau >=0){
        printf("Insira o grau do polinomio:\n");
        scanf("%d", &grau);
        fflush(stdin);
        printf("Insira o vetor correspondente ao polinomio:\n"); 
        double* polinomio = (double*) malloc(sizeof(double) * (grau + 1));
        if(!polinomio){
            printf("ERRO ALOCANDO MEMORIA");
            exit(-1);
        }
        int tamanho = grau+1;
        for(int i=0; i<tamanho; i++){
            printf("Insira o termo de grau %d: ", grau-i);
            scanf("%lf", &polinomio[i]);
        }
        double* derivada = Polinomio_derivar(polinomio, &tamanho);
        double* integral = Polinomio_integrar(polinomio, &tamanho);
        Vetor_imprime(derivada, tamanho-1);
        Vetor_imprime(integral, tamanho+1);
        free(polinomio);
        free(derivada);
        free(integral);
    }

}