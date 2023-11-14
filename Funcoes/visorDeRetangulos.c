#include <stdio.h>

// VALORES DE X:
// a, c
// w, y
// VALORES DE Y:
// b, d
// x, z

//(<0.00,0.00>,<30.00,30.00>) contem (<10.00,10.00>,<20.00,20.00>).

void contem(float a, float b, float c, float d, float w, float x, float y, float z){
    if((w > a && w < c && y > a && y < c) && (x > b && x < d && z > b && z < d)){
        printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", a, b, c, d, w, x, y, z);
    }else if((a > w && a < y && c > w && c < y) && (b > x && b < z && d > x && d < z)){
        printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", w, x, y, z, a, b, c, d);
    }else{
        printf("Nao posso afirmar!\n");
    }
}

int main(){
    float t1, t2, t3, t4, n1, n2, n3, n4, executar;
    executar = 1;

    scanf("%f %f %f %f", &t1, &t2, &t3, &t4);
    
    do{
        scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
        
        if(n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0){
            executar = 0;
        }else{
            contem(t1, t2, t3, t4, n1, n2, n3, n4);
        }
        
    }while(executar != 0);

}