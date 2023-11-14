#include <stdio.h>

int geraSeq(int qtdDiscos, int de, int para, int aux){
    if(qtdDiscos == 0){
        return 0;
    }

    int res = (2 * geraSeq((qtdDiscos - 1), de, aux, para)) + 1;

    printf("Move o disco em %d para %d\n", de, para);

    geraSeq((qtdDiscos - 1), aux, para, de);
    
    return res;
}

int main(){
    int qtdDiscos;

    scanf("%d", &qtdDiscos);

    printf("Total de movimentos: %d", geraSeq(qtdDiscos, 1, 3, 2));
}