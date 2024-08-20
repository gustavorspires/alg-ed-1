# Aula 3 - Tipos Abstratos de Dados - Parte 2

### Estruturas de Dados
- Organizar
- Armazenar
- Processar

Estruturas de Dados ajudam a resolver vários problemas, cabendo ao desenvolvedor analisar qual é a estrutura ideal. 
Toda estrutura de dados é baseada em um TAD.

##### Organização de um TAD
	- Dados
		- Struct
			- int, float, char, etc;
	- Funções
		- Inserir
		- Alterar
		- Apagar
		- Imprimir
		- Outras funções

### TAD Item (Genérico/Void)

##### TAD Genérico
	- Dados
		- Item
	- Funções
		- Inserir
		- Alterar
		- Apagar
		- Imprimir
		- Outras funções

### Interface (item.h)

```c
#ifndef ITEM_H
	#define ITEM.H
	#include <stdbool.h>

	typedef struct item_ ITEM;
	
	ITEM *item_criar(int chave, void * comp);
	bool item_apagar(ITEM **item);
	int item_get_chave(ITEM **item);
	bool item_set_chave(ITEM **item, int chave);
	void *item_get_dados(ITEM **item);

#endif
```

### Definição (item.c)

```c
#include <stdio.h>
#include <stdbool.h)
#include "item.h"

struct item_{
	int chave;
	void *dados;
}

ITEM *item_criar (int chave, void *dado){
	ITEM *item;
	item = (ITEM *) malloc(sizeof(ITEM));
	if (item != NULL){
		item->chave = chave;
		item->dados = dado;
		return(item);
	}
	return(NULL);
}

bool item_apagar(ITEM **item){
	if (*item != NULL){
		free(item);
		*item = NULL;
		return(true);
	}
	return(false);
}

int item_get_chave(ITEM **item){
	if(item != NULL)
		return(item->chave);
	exit(1);
}

bool item_set_chave(ITEM **item, int chave){
	if(item != NULL) {
		item->chave = chave;
		return(true);
	}
	return(false);
}

void *item_get_dados(ITEM *item){
	if(item != NULL)
		return(item->dados);
	return(NULL);
}
```

### Makefile
Arquivo com regras e instruções de compilação
Basicamente, ele instrui o compilador a como compilar o código

##### Sintaxe
```
all: item.o cliente.o
	gcc item.o cliente.o -o cli -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

cliente.o:
	gcc -c cliente.c -o cliente.o

clean:
	rm *.o cli
```

