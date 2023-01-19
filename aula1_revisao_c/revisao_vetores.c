//
// Created by gustavo on 1/16/23.
//
#include <stdio.h>
#include <stdlib.h>
void incr_vetor(int n, int *v){
    for(int i=0; i<n; i++)
            v[i]++;
}

void incr_vetor_endereco(int n, int *v){
    for(int i=0; i<n; i++)
        *(v+(sizeof(int)*i)) = *(v+(sizeof(int)*i)) + 1;
}

void print_vetor(int n, int *v){
    printf("[");
    for(int i=0; i < n-1; i++)
        printf("%d,", v[i]);
    printf("%d]\n", v[n-1]);
}

int main(void){
    int v[10];

    int *v2 = malloc(sizeof(int) * 10);

    for(int i=0; i<10; i++) {
        v[i] = i;
        v2[i] = i;
    }
    printf("v1: \n");
    print_vetor(10, v);
    incr_vetor(10, v);
    print_vetor(10, v);
    incr_vetor_endereco(10, v);

    printf("v2: \n");
    print_vetor(10, v2);
    incr_vetor(10, v2);
    print_vetor(10, v2);
    incr_vetor_endereco(10, v2);
    return 0;
}