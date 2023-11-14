#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

typedef struct {
    int id_cartela;
    int tam_cartela;
    int numeros[100];
    int marcacao[100];
}Cartela;

void inicializaCartela(int indice, Cartela *vetorCartelas, int id, int tam, int globo){
    int qtdSorteados = 0;

    vetorCartelas[indice].id_cartela = id;
    vetorCartelas[indice].tam_cartela = tam;

    srand(id);

    while(qtdSorteados < tam){
        int aux = 1;
        int numCartela = rand()%globo;
        if(numCartela == 0){
            numCartela = globo;
        }
        for(int i = 0; i < tam; i++){
            if(vetorCartelas[indice].numeros[i] == numCartela){
                break;
                aux = 0;
            }
        }

        if(aux){
            vetorCartelas[indice].numeros[qtdSorteados] = numCartela;
        }

        qtdSorteados++;
    }

    
        printf("Cartela %d: ", vetorCartelas[indice].id_cartela);
        for(int i = 0; i < tam; i++){
            printf("%d ", vetorCartelas[indice].numeros[i]);
        }
        printf("\n");
    
}

int marcaNumero(int indice, Cartela *vetorCartelas, int numSorteado){
    int confere = 0;
    for(int i = 0; i < vetorCartelas[indice].tam_cartela; i++){
        if(vetorCartelas[indice].numeros[i] == numSorteado){
            vetorCartelas[indice].marcacao[i] = 1;

            //printf("Marquei %d na cartela %d\n", vetorCartelas[indice].numeros[i], vetorCartelas[indice].id_cartela);

            break;
        }
    }

    for(int i = 0; i < vetorCartelas[indice].tam_cartela; i++){
        if(vetorCartelas[indice].marcacao[i] == 0){
            confere++;
        }
    }

   if(confere == 0){
    return 1;
   }
   
    //printf("Retorna zero pq na cartela %d tem %d numeros nao marcados\n", vetorCartelas[indice].id_cartela, confere);
    return 0;

}

int main(){
    int tamCartela, tamGlobo, sementeS, indice = 0, numSorteado, resultado = 0;
    char entrada[20];
    Cartela vetorCartelas[30];

    scanf("%d %d %d", &tamCartela, &tamGlobo, &sementeS);
    getchar();

    int numerosSorteados[tamGlobo];

    for(int i = 0; i < tamGlobo; i++){
        numerosSorteados[i] = 0;
    }

    do{
        scanf("%s", entrada);

        if(strcmp(entrada, "Comecou") == 0){
            break;
        }

        inicializaCartela(indice, vetorCartelas, atoi(entrada), tamCartela, tamGlobo);

        indice++;

    }while(strcmp(entrada, "Comecou") != 0);

    srand(sementeS);

    int fim = 1;

    while(fim){
        numSorteado = rand()%tamGlobo;

        if(numSorteado == 0){
            numSorteado = tamGlobo;
        }

        if(numerosSorteados[numSorteado-1] == 0){
            printf("%d ", numSorteado);
            numerosSorteados[numSorteado-1] = 1;
            //printf("n repetido: %d\n", numSorteado);

            for(int i = 0; i < (indice); i++){
                resultado = marcaNumero(i, vetorCartelas, numSorteado);
                if(resultado == 1){
                    printf("\n");
                    printf("Bingo! Cartela %d: ", vetorCartelas[i].id_cartela);
                    for(int j = 0; j < tamCartela; j++){
                        printf("%d ", vetorCartelas[i].numeros[j]);
                    }
                    printf("\n");


                    fim = 0;
                    break;

                }
            }
        }

    }

    return 0;
}