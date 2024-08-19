#include <stdio.h>
#include <stdbool.h>
#include "circulo.h"
#include "ponto.h"

int main(void){
    PONTO *ponto, *cir_ponto;
    CIRCULO *circulo;

    float px, py, cx,cy;
    float raio;

    scanf(" %f %f %f %f %f", &px, &py, &cx, &cy, &raio);    

    ponto = ponto_criar(px, py);
    cir_ponto = ponto_criar(cx, cy);
    circulo = circulo_criar(cir_ponto, raio);

    ponto_print(ponto);
    circulo_print(circulo);

    ponto_apagar(&ponto);
    ponto_apagar(&cir_ponto);
    circulo_apagar(&circulo);
}
