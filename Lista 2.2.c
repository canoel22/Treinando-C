/******************************************************************************
2. Receber um valor qualquer do teclado e imprimir esse valor comreajuste de10%. 
******************************************************************************/
#include <stdio.h>

int main()
{
    float valor;
    scanf("%f", &valor);
    printf("%.2f", 1.1*valor);
    return 0;
}

