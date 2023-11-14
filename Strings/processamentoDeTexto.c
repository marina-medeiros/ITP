#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void gera_lista(int qtd, char base[][11]){
    int tamanho;
     for(int i = 0; i < qtd; i++){
        fgets(base[i], 11, stdin);

        tamanho = strlen(base[i]);
        base[i][tamanho-1] = '\0';
    }
}

void gera_matriz(int qtd, char base[][11]){
    int letras;
    int matriz[qtd][qtd];

    for(int i = 0; i < qtd; i++){
        for(int j = 0; j < qtd; j++){
            letras = 0;
            for(int k = 0; k < (int)strlen(base[i]); k++){
                if(base[i][k] == base[j][k]){
                    letras++;
                }
            }
            matriz[i][j] = letras;
        }
    }

    for(int i = 0; i < 10; i++){
        printf(" ");
    }
    for(int i = 0; i < qtd; i++){
        int qtdEspacos = 10 - (int)strlen(base[i]);
        for(int k = 0; k < qtdEspacos; k++){
            printf(" ");
        }
        printf("%s", base[i]);
        
    }
    printf("\n");

    for(int i = 0; i < qtd; i++){
        int qtdEspacos = 9 - (int)strlen(base[i]);
        printf("%s ", base[i]);
        for(int k = 0; k < qtdEspacos; k++){
            printf(" ");
        }
        for(int j = 0; j < qtd; j++){
            if((int)strlen(base[i]) >= (int)strlen(base[j])){
                printf("       %d/%d", matriz[i][j], (int)strlen(base[i]));
            }
            if((int)strlen(base[i]) < (int)strlen(base[j])){
                printf("       %d/%d", matriz[i][j], (int)strlen(base[j]));
            }
        }
        printf("\n");
    }
}

int main(){
    int qtd;

    scanf("%d", &qtd);
    getchar();

    char listaDePalavras[qtd][11];

    gera_lista(qtd, listaDePalavras);

    gera_matriz(qtd, listaDePalavras);
}