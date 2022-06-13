#include <stdio.h>

int descobrirForma(char forma[]){ //verifica qual forma tem na carta
    if(forma[0] == 'c'){  //caso seja circulo
        return 0;
    }
    if(forma[0] == 't'){ //caso seja triangulo
        return 1;
    }else{
        return 2; //caso seja quadrado
    }
}

int descobrirNum(char str[]){ //verifica qual número de formas tem na carta
    if(str[0] == 'u'){ //caso tenha 1 figura 
        return 0;
    }
    if(str[0] == 'd'){ //caso tenha 2 figuras
        return 1;
    }else{
        return 2; //caso tenha 3 figuras
    }
}

void verificaIguais(int cartas[3][3], int *sets, int i, int j){ //testa os sets de cartas iguais
    if (cartas[i][j]/3 > 0){
        cartas[i][j] %= 3; //subsitui a matriz com os restos da divisão por 3
        (*sets)++;
    }
}

void verificaDiferentes(int cartas[3][3], int *sets, int y, int k, int caso1, int caso2){ //testa os sets de cartas diferentes
   int e, f, g, x, z;
   
    if(caso1){
        e = (k)%3, f = (k+1)%3, g = (k+2)%3;    // e, f e g assumem os valores das colunas
    }else{
        e = k, f = k, g = k;    // e, f e g iguais
    }  
    
    if(caso2){
        x = (y+2)%3, z = (y+1)%3;   // x, y e z assumem os valores das linhas
    }else{
        x = y, z = y;   // x, y e z iguais
    }   

    if (cartas[x][e]*cartas[y][f]*cartas[z][g] > 0){ //se a multiplicação for negativa é porque não tem mais cartas em alguma pos
        cartas[x][e]--;
        cartas[y][f]--;  //tira o set da matriz  
        cartas[z][g]--;
        (*sets)++;
    }
    if (cartas[x][g]*cartas[y][f]*cartas[z][e] > 0){
        cartas[x][g]--;
        cartas[y][f]--;  //tira o set da matriz
        cartas[z][e]--;
        (*sets)++;
    }
}

int verifica(int cartas[3][3], int i, int j){  //verifica se é um set
    int sets = 0;
    verificaIguais(cartas, &sets, i, j);  //de cartas iguais
    verificaDiferentes(cartas, &sets, i, 0, 1, 0);
    for (int k = 0; k < 3; ++k){ //varia a coluna (qtd de formas na carta) para verificação
        verificaDiferentes(cartas, &sets, 1, k, 0, 1); // qtd = e forma =!
        verificaDiferentes(cartas, &sets, 1, k, 1, 0); //qtd != e forma =
        verificaDiferentes(cartas, &sets, 1, k, 1, 1); //qtd e forma =!
    }
    return sets;
}


int resultado(int qtd){
    int cartas[3][3] = {{0,0,0},{0,0,0},{0,0,0}}, sets = 0, j, k; 
    char num[5], forma[10];

    for (int i = 0; i < qtd; ++i){
        scanf("%s %s", num, forma);
        j = descobrirForma(forma); //chama função, linha = forma
        k = descobrirNum(num);    //chama função, coluna = quantidade de formas
        cartas[j][k]++; //matriz de qtd/tipo de cada carta acrescenta +1 de acordo com a inserida

        sets += verifica(cartas, j, k);
    }
    return sets; //retorna a resposta
}


int main(){
    int qtd = -1, testes=-1, vet[1001];
    while(qtd){
        scanf("%d",&qtd); //escaneia a quantidade de cartas
        if (qtd>0){ //condição de parada do programa
            testes++; 
            vet[testes]= resultado(qtd); //cada pos do vetor assume um resultado de um teste
        }  
    }
    for(int i=0; i<=testes; i++){    //um for com a qtd de testes para 
        printf("\n%d", vet[i]);    //printar os resultados em linhas diferentes
    }
    return 0;
} 



