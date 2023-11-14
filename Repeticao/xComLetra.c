#include <stdio.h>
#include <math.h>

int main(){
    int entrada, colunas, linhas, totalCol;
    char letra;

    scanf("%d %c", &entrada, &letra);

    totalCol = entrada - 1;


    for(linhas = 0; linhas < totalCol; linhas++){
        for(colunas= 0; colunas < totalCol; colunas++){
            if((colunas==linhas) || (linhas+colunas) == (totalCol-1)){
                printf("%c", letra);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    

}