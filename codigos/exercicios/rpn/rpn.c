#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

float rpn(char *s){
    PILHA *p = pilha_criar();
    float *rAux = malloc(sizeof(float)*100);
    int i = 0;

    while(*s != '\0'){
        char c = *s;

        if(c >= '0' && c <= '9'){
            float n = c - '0';
            rAux[i] = (float)n;
            pilha_empilhar(p, item_criar(0, &rAux[i]));
        } else if (c == '+' || c == '-' || c == '*' || c == '/'){
            float B = *(float *)item_get_dados(pilha_desempilhar(p));
            float A = *(float *)item_get_dados(pilha_desempilhar(p));

            switch (c) {
                case '+': 
                    rAux[i] = (A) + (B);
                    break;
                case '-': 
                    rAux[i] = (A) - (B);
                    break;
                case '*': 
                    rAux[i] = (A) * (B);
                    break;
                case '/': 
                    rAux[i] = (A) / (B);
                    break;
            }

            pilha_empilhar(p, item_criar(0, &rAux[i]));
        }
        i++;
        s++;
    }
    float* rf = (float *)item_get_dados(pilha_desempilhar(p));
    float r = *rf;

    pilha_apagar(&p);
    free(rAux);

    return r;
}