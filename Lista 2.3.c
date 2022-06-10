/******************************************************************************

3. Usando apenas operadores relacionais, escreva um programa que lê um número e verifica se este  ́e:
Par e menor que 100.
Par e maior ou igual a 100.
́Impar e menor que 100
́Impar e maior ou igual a 100.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf ("\nCaso a afirmação for verdadeira, retorna 1, caso falsa, retorna 0\n");
    printf("Par e menor que 100 -> %d \n", n%2==0 && n<100);
    printf("Par e maior ou igual a 100 -> %d\n", n%2==0 && n>=100);
    printf("Ímpar e menor que 100 -> %d\n", n%2!=0 && n<100);
    printf("Ímpar e maior ou igual a 100 -> %d\n", n%2!=0 && n>=100);
    
    return 0;
}

