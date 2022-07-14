//código de adivinhar a senha de 4 dígitos (como o jogo termo.o, mas com números e com dicas embaralhadas)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inic_random(){     //função que faz com que o rand gere num aleatórios toda vez que inicializado
    long  ultime;
    time(&ultime);
    srand((unsigned) ultime);
}


int main(){
    int vet[4], num[4], cont=0, certo=0, k;
    char dica[4];
    
    inic_random();
    for (int i=0; i<4; i++){
        num[i] = rand() % 9;    //gera a senha aleatória
        printf("%d", num[i]);
    }
    printf("\n");
    while (cont<10){    //limita a 10 tentativas
        k=0;
        certo=0;
        for(int i=0;i<4;i++){
            dica[i] = '_';     //inicializa como se não tivesse nenhum num igual
        }
        
        for(int i=0; i<4; i++){
            scanf("%d", &vet[i]);   //escaneia a tentativa do usuário
            for(int j=0; j<4; j++){
                if (vet[i]==num[j]){    //verifica se está na senha
                    if (i==j) {         //verifica se tem num certo na posição certa
                        dica[k]='C';
                        k++;
                        certo++;
                        break;
                    } else {          //ou verifica se tem num certo na posição errada
                        dica[k]='E';
                        k++;
                        break;
                    }
                }
             } 
        }
        printf("%s\n", dica);   //printa a dica
        cont++;
       
        if (certo==4){     //caso de vitória
            printf ("\nParabéns, você venceu o jogo!");
            return 0;
        }
    }
    printf ("\nPoxa, você perdeu! A senha era %d%d%d%d!", num[0], num [1], num[2], num[3]); //caso de derrota
    return 0;
    
}

