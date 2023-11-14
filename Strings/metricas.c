#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_line(char linha[], int tam, FILE* f){
    fgets(linha, tam, f);

    while(linha[0] == '\n'){
        fgets(linha, tam, f);
    }

    if(linha[strlen(linha)-1] == '\n'){
        linha[strlen(linha)-1] = '\0';
    }
}

float media_tamanhos(int numLinhas, char strings[numLinhas][201]){
    int i;
    float media, soma = 0, numLinhasFloat = numLinhas;

    for(i = 0; i < numLinhas; i++){
        soma += (int)strlen(strings[i]);
    }

    media = soma / numLinhasFloat;

    return media;
}

int tamanho_minimo_ou_maximo(int numLinhas, char strings[numLinhas][201], int op){
    int tam = (int)strlen(strings[0]), i;

    for(i = 1; i < numLinhas; i++){
        if(op == 0){
            if((int)strlen(strings[i]) < tam){
                tam = (int)strlen(strings[i]);
            }
        }
        else{
            if((int)strlen(strings[i]) > tam){
                tam = (int)strlen(strings[i]);
            }
        }
    }

    return tam;
}

int tamanho_mais_prox(int numLinhas, char strings[numLinhas][201]){
    float media = media_tamanhos(numLinhas, strings);
    float dif = abs(media - (int)strlen(strings[0])); // abs() pega o módulo do número
    int tam_mais_prox = (int)strlen(strings[0]), i;

    for(i = 1; i < numLinhas; i++){
        if(abs(media - (int)strlen(strings[i])) < dif){
            dif = abs(media - (int)strlen(strings[i]));
            tam_mais_prox = (int)strlen(strings[i]);
        }
    }

    return tam_mais_prox;
}

char* texto_mais_prox(int numLinhas, char strings[numLinhas][201]){
    float media = media_tamanhos(numLinhas, strings);
    float dif = abs(media - (int)strlen(strings[0])); // abs() pega o módulo do número
    int posicao = 0, i;
    char* texto_mais_proximo;

    for(i = 1; i < numLinhas; i++){
        if(abs(media - (int)strlen(strings[i])) < dif){
            dif = abs(media - (int)strlen(strings[i]));
            posicao = i;
        }
    }

    texto_mais_proximo = strings[posicao];

    return texto_mais_proximo;
}

int main(){
    int N, i;

    scanf("%d", &N);

    char vetorDeString[N][201];

    //cria o vetor de strings
    for(i = 0; i < N; i++){
        read_line(vetorDeString[i], 201, stdin);
    }
    
    printf("Tamanho maximo: %d\n", tamanho_minimo_ou_maximo(N, vetorDeString, 1));
    printf("Tamanho minimo: %d\n", tamanho_minimo_ou_maximo(N, vetorDeString, 0));
    printf("Tamanho medio: %.2f\n", media_tamanhos(N, vetorDeString));
    printf("Tamanho mais proximo da média %d\n", tamanho_mais_prox(N, vetorDeString));
    printf("Textos\n");
    printf("%s", texto_mais_prox(N, vetorDeString));

}