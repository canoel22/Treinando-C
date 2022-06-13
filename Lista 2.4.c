/******************************************************************************

4. Ler n números e imprimir o maior e menor dentre eles;

*******************************************************************************/
#include <stdio.h>

int main()
{
    int n, maior=0, menor=0;
    scanf("%d", &n);
    int num;
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if (i==0){
            menor=num;
            maior=num;
        }
        if(num>maior){
            maior=num;
        }  
        if(num<menor){
            menor=num;
        }
    }
    printf("Maior: %d\n", maior);
    printf("Menor: %d", menor);
    return 0;
}
