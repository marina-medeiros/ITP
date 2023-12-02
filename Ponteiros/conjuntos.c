#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int qntValores;
    int *valores;
}Conjunto;

Conjunto uniao(Conjunto *a, Conjunto *b){
    Conjunto uniao;
    int tamUniao = 0;

    uniao.valores = malloc(sizeof(int) * (b->qntValores + a->qntValores));

    for(int i = 0; i < a->qntValores; i++){
        int aux = 1;
        for(int j = i+1; j < a->qntValores; j++){
            if(a->valores[i] == a->valores[j]){
                aux = 0;
                break;
            }
        }
        if(aux){
            uniao.valores[tamUniao] = a->valores[i];
            tamUniao++;
        }
    }

    for(int i = 0; i < b->qntValores; i++){
        int aux = 1;
        for(int j = 0; j < a->qntValores; j++){
            if(b->valores[i] == a->valores[j]){
                aux = 0;
                break;
            }
        }
        if(aux){
            uniao.valores[tamUniao] = b->valores[i];
            tamUniao++;
        }
    }

    uniao.qntValores = tamUniao;

    uniao.valores = realloc((uniao.valores),sizeof(int) * (b->qntValores + a->qntValores));

    return uniao;
}

Conjunto intersecao(Conjunto *a, Conjunto *b){
    Conjunto intersecao;
    int tamintersecao = 0;
    
    intersecao.valores = malloc(sizeof(int) * (b->qntValores + a->qntValores));

    for(int i = 0; i < b->qntValores; i++){
        for(int j = 0; j < a->qntValores; j++){
            if(b->valores[i] == a->valores[j]){
                intersecao.valores[tamintersecao] = b->valores[i];
                tamintersecao++;
                break;
            }
        }
    }

    intersecao.qntValores = tamintersecao;

    
    intersecao.valores = realloc((intersecao.valores),sizeof(int) * (b->qntValores + a->qntValores));

    return intersecao;
}

int main(){
    Conjunto A;
    Conjunto B;

    scanf("%d", &A.qntValores);

    A.valores = malloc(sizeof(int) * A.qntValores);

    for(int i = 0; i < A.qntValores; i++){
        scanf("%d", &A.valores[i]);
    }

    scanf(" %d", &B.qntValores);
    
    B.valores = malloc(sizeof(int) * B.qntValores);

    for(int i = 0; i < B.qntValores; i++){
        scanf("%d", &B.valores[i]);
    }

    printf("A união B == {");

    if(uniao(&A, &B).qntValores != 0){ 
        for(int i = 0; i < uniao(&A, &B).qntValores-1; i++){
            printf("%d ", uniao(&A, &B).valores[i]);
        }
        printf("%d}\n", uniao(&A, &B).valores[uniao(&A, &B).qntValores-1]);
    }else{
        printf("vazio}\n");
    }

    printf("A interseção B == {");

    if(intersecao(&A, &B).qntValores != 0){ 
        for(int i = 0; i < intersecao(&A, &B).qntValores-1; i++){
            printf("%d ", intersecao(&A, &B).valores[i]);
        }
        printf("%d}", intersecao(&A, &B).valores[intersecao(&A, &B).qntValores-1]);
    }else{
        printf("vazio}");
    }

}