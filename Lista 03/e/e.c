#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>

void calculaHexagono(float l,float*area,float*perimetro);

int main(){
    float l, area, perimetro;

    printf("Insira o lado do hexagono: ");
    scanf("%f",&l);

    calculaHexagono(l,&area,&perimetro);

    printf("Area: %.2f\n",area);
    printf("Perimetro: %.2f\n",perimetro);

    system("pause");

    return 0;
}

void calculaHexagono(float l,float*area,float*perimetro){
    *area = (6 * pow(l,2) * sqrt(3)) / 4;
    *perimetro = 6 * l;
}
