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

char* tira_prefixo(char texto[100], int qntPrefixos, char prefixos[qntPrefixos][11]){
    int i, j, k, tamPrefixo;
    char* saida = malloc(sizeof(char) * 100);

    for(i = 0; i < qntPrefixos; i++){
        tamPrefixo = (int)strlen(prefixos[i]);
        if(tamPrefixo <= (int)strlen(texto)){
            int aux = 0;
            for(j = 0; j < tamPrefixo; j++){
                if(texto[j] == prefixos[i][j]){
                    aux++;
                }else{
                    break;
                }
            }
            if(aux == tamPrefixo){ //o texto tem o prefixo
                for(k = 0; k < ((int)strlen(texto) - (int)strlen(prefixos[i])); k++){
                    saida[k] = texto[k + (int)strlen(prefixos[i])];
                }
                break; //pode encerrar o loop pq um texto só pode ter um prefixo
            }
        }
    }

   return saida;
}

char* tira_sufixo(char texto[100], int qntSufixos, char sufixos[qntSufixos][11]){
    int i, j, k, tamSufixo;
    char* saida = malloc(sizeof(char) * 100);

    for(i = 0; i < qntSufixos; i++){
        tamSufixo = (int)strlen(sufixos[i]);
        if(tamSufixo <= (int)strlen(texto)){
            int aux = 0;
            for(j = 0; j < tamSufixo; j++){
                if(texto[j] == sufixos[i][j]){
                    aux++;
                }else{
                    break;
                }
            }
            if(aux == tamSufixo){ //o texto tem o sufixo
                for(k = 0; k < ((int)strlen(texto) - (int)strlen(sufixos[i])); k++){
                    saida[k] = texto[k];
                }
                break; //pode encerrar o loop pq um texto só pode ter um prefixo
            }
        }
    }

    return saida;
} 

int main(){
    int i, qntPrefixos, qntSufixos;
    char texto[100];

    scanf("%d", &qntPrefixos);
    char vetorDePrefixos[qntPrefixos][11];
    for(i = 0; i < qntPrefixos; i++){
        read_line(vetorDePrefixos[i], 11, stdin);
    }
    
    scanf("%d", &qntSufixos);
    char vetorDeSufixos[qntSufixos][11];
    for(i = 0; i < qntSufixos; i++){
        read_line(vetorDeSufixos[i], 11, stdin);
    }

    while (texto[0] != '-' && texto[1] != '1')
    {
        fgets(texto, 100, stdin);
        char* semPrefixo = tira_prefixo(texto, qntPrefixos, vetorDePrefixos);
        printf("%s", tira_prefixo(texto, qntPrefixos, vetorDeSufixos));
        printf("%s", tira_sufixo(semPrefixo, qntSufixos, vetorDeSufixos));
    }
    
    
}