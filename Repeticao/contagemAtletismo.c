#include <stdio.h>
#include <math.h>

int main(){
    int equipes, salto, corrida, lancamento, total, i;
    char letra;

    corrida = salto = lancamento = 0;
    
    scanf("%d", &equipes);

    for(i = 0; i < equipes; i++){
        do{
            scanf(" %c", &letra);
            switch (letra)
            {
            case 'C': corrida++; break;
            case 'S': salto++; break;
            case 'L': lancamento++; break;
            }
        }while (letra != 'F');
    }
    total = corrida + salto + lancamento;

    printf("%d %d %d %d", corrida, salto, lancamento, total);

}