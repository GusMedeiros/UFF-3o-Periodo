#include <stdio.h>

int main(void){
    int a, *p;
    a = 5;
    p = &a;
    *p = 6;
    printf("endereço de p: %x \n", &p);
    printf("endereço de a: %x \n", &a);
    printf("endereço que está em p: %x \n", p);
    printf("conteúdo da variável apontada por p: %x \n", *p);
    printf("conteúdo de a: %x \n", a);
    return 0;
}