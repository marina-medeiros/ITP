#include <stdio.h>

float calcNota(float n1, float n2, float n3){
    float media, n4;
    media = (n1 + n2 + n3) / 3;
    if(n1 >= 3 && n2 >= 3 && n3 >= 3 && media < 5){
        // 3 + [15 - (soma das notas)]
        n4 = 18 - (n1 + n2 + n3);
        return n4;
    }else{
        return -1;
    }

}

int main(){
    float p1, p2, p3, media;
    scanf("%f\n", &p1);
    scanf("%f\n", &p2);
    scanf("%f\n", &p3);
    media = (p1 + p2 + p3) / 3;
    if(p1 >= 3 && p2 >= 3 && p3 >= 3 && media < 5){
        printf("Final\n");
        printf("%.1f", calcNota(p1, p2, p3));
    }else{
        printf("Nao faz prova final");
    }
}