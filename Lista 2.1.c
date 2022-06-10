/******************************************************************************
Exercícios
1. Ler um ńumero inteiro e imprimir seu sucessor e seu antecessor usando operador uńario de incremento e decremento;

*******************************************************************************/
#include <stdio.h>

int main()
{
    int n, a , s;
    scanf("%d", &n);
    printf("Sucessor: %d\n",(++n));
    n--;
    printf("Antecessor:%d",(--n));
    return 0;
}

