#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "circulo.h"
#include "ponto.h"

struct circulo_{
    float raio;
    PONTO *ponto;
};

CIRCULO *circulo_criar (PONTO *p, float raio){
    CIRCULO *circulo;
    circulo = (CIRCULO *)malloc(sizeof(CIRCULO));
    if(circulo != NULL){
        circulo->ponto = p;
        circulo->raio = raio;
        return(circulo);
    }
    return(NULL);
}

void circulo_apagar (CIRCULO **circulo){
    if(*circulo != NULL){
        free(*circulo);
        *circulo = NULL;
        return;
    }
    exit(1);
}

bool circulo_set_ponto(CIRCULO *circulo, PONTO *ponto){
    if(circulo != NULL){
        circulo->ponto = ponto;
        return(true);
    }
    return(false);
}

bool circulo_set_raio(CIRCULO *circulo, float raio){
    if(circulo != NULL){
        circulo->raio = raio;
        return(true);
    }
    return(false);
}

PONTO *circulo_get_ponto(CIRCULO *circulo){
    if(circulo != NULL){
        PONTO *ponto;
        ponto = circulo->ponto;
        return (ponto);
    }
    return(NULL);
}

float circulo_get_raio(CIRCULO *circulo){
    if(circulo != NULL){
        float raio;
        raio = circulo->raio;
        return (raio);
    }
    exit(1);
}

void circulo_print(CIRCULO *circulo){
    if(circulo != NULL){
        float x = ponto_get_x(circulo->ponto);
        float y = ponto_get_y(circulo->ponto);
        float raio = circulo_get_raio(circulo);
        printf("Circulo: Centro (%.1f, %.1f), Raio = %.1f",x, y, raio);
    }
}