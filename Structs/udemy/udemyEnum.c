#include <stdio.h>
#include <string.h>

enum semana{
    segunda, terca, quarta, quinta, sexta, sabado, domingo
};

//union sobescreve
//pode ser útil para economizar memória
int main(){
    enum semana d1, d2;

    d1 = quinta;

    d2 = 4;

    if(d1 == d2){
        printf("Os dias são iguais");
    }else{
        printf("Não são iguais");
    }
}