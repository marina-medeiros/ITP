#include <stdio.h>

int main(){
    int n1, n2;
    char operador;

    do{
        printf("Digite a conta desejada:\n");
        scanf("%d %c %d", &n1, &operador, &n2);

        switch(operador){
            case '+': printf("%d\n", n1 + n2); break;
            case '-': printf("%d\n", n1 - n2); break;
            case '*': printf("%d\n", n1 * n2); break;
            case '/': 
                if(n2 == 0) printf("Erro! Divisão por zero\n");
                else printf("%d\n", n1 / n2);
                break;
        }
    }while(operador != 'F');
}