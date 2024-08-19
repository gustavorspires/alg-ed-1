#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ponto.h"

struct ponto_{
    float x;
    float y;
};

PONTO *ponto_criar(float x, float y){
    PONTO *ponto;
    ponto = (PONTO *) malloc(sizeof(PONTO));
    if (ponto != NULL){
        ponto->x = x;
        ponto->y = y;
        return (ponto);
    }
    return(NULL);
}

void ponto_apagar(PONTO **ponto){
    if(*ponto != NULL){
        free(*ponto);
        *ponto = NULL;
        return;
    }
    exit(1);
}

bool ponto_set(PONTO *ponto, float x, float y){
    if(ponto != NULL){
        ponto->x = x;
        ponto->y = y;
        return(ponto);
    }
}


float ponto_get_x(PONTO *ponto){
    if(ponto != NULL){
        float x = ponto->x;
        return(x);
    }
    exit(1);
}

float ponto_get_y(PONTO *ponto){
    if(ponto != NULL){
        float y = ponto->y;
        return(y);
    }
    exit(1);
}

void ponto_print(PONTO *ponto){
    if(ponto != NULL){
        printf("Ponto: (%.1f, %.1f)\n", ponto->x, ponto->y);
    }
}
