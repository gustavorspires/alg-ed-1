#ifndef CIRCULO_H
    #define CIRCULO_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "ponto.h"

    typedef struct circulo_ CIRCULO;
    
    CIRCULO *circulo_criar (PONTO *p, float raio);
    bool circulo_set_ponto (CIRCULO *c, PONTO *p);
    bool circulo_set_raio (CIRCULO *c, float raio);
    PONTO *circulo_get_ponto (CIRCULO *c);
    float circulo_get_raio (CIRCULO *c);
    void circulo_apagar (CIRCULO **circulo);
    void circulo_print(CIRCULO *circulo);
#endif