#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int simula_sims(int* fome, int*  sede, int*  banheiro, int*  sono, int*  tedio){
    char acao[20];

    scanf(" %[^\n]", acao);
    //getchar();

    if(strcmp(acao, "comer") == 0){
        *fome += 30;
        *sede -= 5;
        *banheiro -= 15;
        *sono -= 5;
        *tedio -= 5;
    }
    if(strcmp(acao, "beber") == 0){
        *fome -= 5;
        *sede += 30;
        *banheiro -= 20;
        *sono -= 5;
        *tedio -= 5;
    }
    if(strcmp(acao, "dormir") == 0){
        *fome -= 30;
        *sede -= 30;
        *banheiro -= 30;
        *sono += 80;
        *tedio += 30;
    }
    if(strcmp(acao, "se aliviar") == 0){
        *fome -= 5;
        *sede -= 5;
        *banheiro = 100;
        *sono -= 5;
        *tedio -= 5;
    }
    if(strcmp(acao, "jogar videogame") == 0){
        *fome -= 20;
        *sede -= 20;
        *banheiro -= 20;
        *sono -= 20;
        *tedio += 80;
    }

    *fome = (*fome > 100) ? 100 : *fome;
    *sede = (*sede > 100) ? 100 : *sede;
    *banheiro = (*banheiro > 100) ? 100 : *banheiro;
    *sono = (*sono > 100) ? 100 : *sono;
    *tedio = (*tedio > 100) ? 100 : *tedio;

    if(*fome <= 15){
        if(*fome <= 0){
            printf("Game Over! Morreu de fome\n");
            *fome = 0;
            return 0;
        }
        printf("Alerta: fome está com valor baixo\n");
    }
    if(*sede <= 15){
        if(*sede <= 0){
            printf("Game Over! Morreu de sede\n");
            *sede = 0;
            return 0;
        }
        printf("Alerta: sede está com valor baixo\n");
    }
    if(*banheiro <= 15){
        if(*banheiro <= 0){
            printf("Game Over! Morreu apertado...\n");
            *banheiro = 0;
            return 0;
        }
        printf("Alerta: banheiro está com valor baixo\n");
    }
    if(*sono <= 15){
        if(*sono <= 0){
            printf("Game Over! Morreu dormindo...\n");
            *sono = 0;
            return 0;
        }
        printf("Alerta: sono está com valor baixo\n");
    }
    if(*tedio <= 15){
        if(*tedio <= 0){
            printf("Game Over! Morreu deprimido...\n");
            *tedio = 0;
            return 0;
        }
        printf("Alerta: tédio está com valor baixo\n");
    }

    return 1;
}

void imprime_relatorio(int fome, int sede, int banheiro, int sono, int tedio){
    printf("Status final:\n");
    printf("Fome: %d\n", fome);
    printf("Sede: %d\n", sede);
    printf("Banheiro: %d\n", banheiro);
    printf("Sono: %d\n", sono);
    printf("Tédio: %d\n", tedio);
}


int main(){
    int fome, sede, banheiro, sono, tedio;
    int acoes;

    scanf("%d %d %d %d %d", &fome, &sede, &banheiro, &sono, &tedio);
    scanf("%d", &acoes);

    for(int i = 0; i<acoes; i++){
        int ret = simula_sims(&fome, &sede, &banheiro, &sono, &tedio);
        if(ret == 0) break;
    }

    imprime_relatorio(fome, sede, banheiro, sono, tedio);
}