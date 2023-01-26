//
// Created by gustavo on 1/25/23.
//
#include <stdio.h>
#define M 5
#include <stdlib.h>
#include <limits.h>
#include <string.h>"

typedef struct registro{
    int val;
    int cong;
} TREG;

FILE *gera_arquivo(){
    FILE *f = fopen("numeros.txt", "w+");
    for(int i=30; i>0; i--){
        fprintf(f, "%d\n", i);
    }
}

int tamanho(){
    return sizeof(int);
}

FILE *gera_part(int i){
    char nome[15];
    sprintf(nome, "part%d.txt", i);
    return fopen(nome, "w+");
}

int achar_menor(TREG* v, int tam){
    if(!tam) return -1;
    int i;
    int menor = v[0].val;
    int menor_i = 0;
    for(i; i<tam; i++){
        if(v[i].val < menor) {
            menor = v[i].val;
            menor_i = i;
        }
    }
    return i;
}

int vetor_vazio(TREG* v, int tam){
    int vazio = 1;
    for(int i=0; i<tam && vazio; i++){
        if(v[i].val != INT_MAX) vazio = 0;
    }
    return vazio;
}

void selecao_natural(FILE *f){
    rewind(f);
    TREG *v = malloc(sizeof(TREG) * M);
    int i = 0;
    while(i < M && fscanf(f, "%d\n", &(v[i].val)) > 0){
        v[i].cong = 0;
        i++;
    }
    FILE *reserv = fopen("reservatorio.txt", "w+");
    i = 1;
    FILE *part = NULL;
    while(vetor_vazio(v, M)){
        if(!part) {
            part = gera_part(i);
            i++;
        }
        int i_menor = achar_menor(v, M);
        fprintf(part, "%d", v[i_menor].val);
        if(fscanf(f, "%d\n", &(v[i_menor].val)) == 0)
            v[i_menor].val = INT_MAX;
    }
}