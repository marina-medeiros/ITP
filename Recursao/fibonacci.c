#include <stdio.h>

//n é a posição na sequência de fibonacci
int geraFibonacci(int n, int *tabela){
    if(n < 2){
        return 1;
    }
    if(tabela[n] == 0){
        tabela[n] = geraFibonacci(n-1, tabela) + geraFibonacci(n-2, tabela);
    }
    
    return tabela[n];
}

int valoresNoIntervalo(int inicio, int fim, int *tabela){
    int aux = 0, contador = 0;
    do{
        if(geraFibonacci(aux, tabela) > inicio){
            contador++;
        }
        aux++;
    }while(geraFibonacci(aux, tabela) < fim);

    return contador;
}

int main(){
    int inicio, fim, tabela[50] = {0};

    scanf("%d %d", &inicio, &fim);
    
    printf("Existem %d números de fibonacci entre %d e %d", valoresNoIntervalo(inicio, fim, tabela), inicio, fim);

}