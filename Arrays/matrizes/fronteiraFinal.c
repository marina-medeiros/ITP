#include <stdio.h>

int main(){
    int N, M, i, j;
    float agua = 0, especieHostil = 0, areaDeserto = 0, areaVegetacao = 0, soloSemRecurso = 0, aux = 0;
    float porcAgua, porcDeserto, porcVeg;

    scanf("%d %d", &N, &M);

    float area = N * M;

    char mapa[N][M];

    for(i = 0; i <= N; i++){
        for(j = 0; j < M; j++){
            scanf("%c", &mapa[i][j]);
            switch (mapa[i][j]){
            case '~': agua++; break;
            case 'X': especieHostil++; break;
            case '^': areaDeserto++; break;
            case '*': areaVegetacao++; break;
            case '.': soloSemRecurso++; break;
            }
        }
    }

    porcAgua = agua / area;
    porcDeserto = areaDeserto / area;
    porcVeg = areaVegetacao / area;
    
    printf("%f %f %f %f %f \n", agua, especieHostil, areaDeserto, areaVegetacao, soloSemRecurso);
    printf("%f %f %f\n", porcAgua, porcDeserto, porcVeg);

    if(especieHostil == 0){
        if(porcAgua >= 0.5 && porcVeg >= 0.2){
            printf("Planeta Classe M");
            aux++;
        }
        if(porcVeg >= 0.65){
            printf("Planeta Selvagem");
            aux++;
        }
        if(porcAgua >= 0.85){
            printf("Planeta Aquático");
            aux++;
        }
        if(porcDeserto >= 0.60){
            printf("Planeta Desértico");
            aux++;
        }
        if(aux == 0){
            printf("Planeta Inóspito");
        }
    }else{
        printf("Planeta Hostil");
            aux++;
    }


}