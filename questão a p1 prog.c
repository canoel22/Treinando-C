#include <stdio.h>

int main() {
    int i, n, cont=0, num[n]; // num[n] pro vetor ficar do tamanho certo, sem ter espaço a toa
    
    scanf ("%d", &n); 
    for (i=0; i<n; i++){
        scanf ("%d", &num[i]); //para receber vários valores em um vetor
        if (num[i]%2==0){
            while (num[i]%2==0){ //para achar quantas vezes o número x é divisível por 2
                num[i]=num[i]/2;
                cont++;
            }
        }  
    }
    printf ("%d", cont); //quantas vezes os números foram divididos por 2
    return 0;
]

