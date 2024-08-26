#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pilha.h"
#include "item.h"

bool balanceada(char *sequencia)
{
    PILHA *p = pilha_criar();
    for (int i = 0; sequencia[i] != '\0'; i++)
    {
        if (sequencia[i] == '(' || sequencia[i] == '{' || sequencia[i] == '[')
        {
            pilha_empilhar(p, item_criar(i, &sequencia[i]));
        }
        else if (!pilha_vazia(p))
        {
            if ((sequencia[i] == ')' && *(char *)item_get_dados(pilha_desempilhar(p)) != '(') || (sequencia[i] == '}' && *(char *)item_get_dados(pilha_desempilhar(p)) != '{') || (sequencia[i] == ']' && *(char *)item_get_dados(pilha_desempilhar(p)) != '['))
            {
                pilha_apagar(&p);
                return (false);
            }
        }
        else
        {
            pilha_apagar(&p);
            return (false);
        }
    }
    if (!pilha_vazia(p))
    {
        pilha_apagar(&p);
        return (false);
    }
    pilha_apagar(&p);
    return (true);
}