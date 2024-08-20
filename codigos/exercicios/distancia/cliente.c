#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "ponto.h"
#include "circulo.h"

int main(void){
    float cx, cy, raio, dist;
    int n;
    CIRCULO *c;
    PONTO *p;

    scanf(" %f %f %f", &cx, &cy, &raio);
    scanf(" %d", &n);

    p = ponto_criar(cx, cy);
    c = circulo_criar(p, raio);

    for(int i = 0; i < n; i++){
        float px, py;
        scanf(" %f %f", &px, &py);
        PONTO *p2 = ponto_criar(px, py);
        dist = distancia(circulo_get_ponto(c), p2);
        if (dist > raio){
            printf("fora\n");
        } else if (dist == raio){
            printf("no raio\n");
        } else {
            printf("dentro\n");
        }
    }
    ponto_apagar(p);
    circulo_apagar(p);
}
