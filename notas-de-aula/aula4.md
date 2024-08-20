# Aula 4 - Pilhas - Parte 1

### Conceitos Introdutórios
##### O que é?
- Vida real - objetos colocados uns sobre os outros
	- Ex: Pilha de pratos
##### Pra que servem?
Auxiliam em problemas práticos a partir do princípio LIFO.
	Exemplos:
	- Botão "back" ou opção "undo"
	- Controle de chamada de procedimentos
	- Estrutura auxiliar em algoritmos como a busca em profundidade
##### Definição
Estruturas de dados onde as inserções e remoções são realizadas na mesma extremidade, chamada topo.
Last-in/First-out -> O último a entrar é sempre o primeiro a sair.
##### Organização vs. Alocação de Memória
Alocação Estática: reserva de memória em tempo de compilação
Alocação Dinâmica: em tempo de execução

1. Sequencial e estática: Uso de arrays
2. Encadeada e estática: array simulando memória principal
3. Sequencial de dinâmica: Alocação dinâmica de array
4. Encadeada e dinâmica: Uso de ponteiros
##### Operações Principais
empilhar(P, x) -> insere um elemento no topo de P
desempilhar(P) -> remove o elemento do topo de P e retorna esse elemento
##### Operações Auxiliares
criar(P) -> cria uma pilha vazia
apagar(P) -> apaga a pilha da memória
topo(P) -> retorna o elemento do topo de P, sem remover
tamanho(P) -> retorna o número de elementos em P
vazia(P) -> indica se a pilha P está vazia
cheia(P) -> indica se a pilha P está cheia (útil para implementações sequenciais)
### Implementação Sequencial
##### Implementação Simples
Uma variável mantém o controle da posição do topo e pode ser utilizada também para informar o número de elementos na pilha

##### Interface
```c
	#include "item.h"
	#include <stdbool.h>
	#define TAM 100
	typedef struct pilha_ PILHA;
	
	PILHA *pilha_criar(void);
	void pilha_apagar(PILHA **p);
	bool pilha_vazia(PILHA *p);
	bool pilha_cheia(PILHA *p);
	int pilha_tamanho(PILHA *p);
	ITEM *pilha_topo(PILHA *p);
	bool pilha_empilhar(PILHA *p, ITEM *i);
	ITEM *pilha_desempilhar(PILHA *p);

	void pilha_print(PILHA *p);
	void pilha_inverter(PILHA *p);
```

##### Definição
```c
struct pilha_{
	int tamanho;
	ITEM *i[TAM]
}

PILHA *pilha_criar(void){
	PILHA *p;
	p = (PILHA *)malloc(sizeof(PILHA));
	if(p != NULL){
		return(p);
	}
	return(NULL);
}

void pilha_apagar(PILHA **p){
	if(*p != NULL){
		free(*p);
		*p = NULL;
		return;
	};
	exit(1);
}

bool pilha_vazia(PILHA *p){
	if(p != NULL){
		return((pilha->tamanho == 0) ? true : false);
	}
	return(false);
}

bool pilha_cheia(PILHA *p){
	if(p != NULL){
		return((pilha->tamanho == TAM) ? true : false);
	}
	return(false);
}

int pilha_tamanho(PILHA *p){
	if(p != NULL){
		return(pilha->tamanho);
	}
	return -1;
}

bool pilha_empilhar(PILHA *p, ITEM *i){
	if(p != NULL && i != NULL){
		pilha->tamanho++;
		p->i[p->tamanho] = i;
		return(true);
	}
	return(false);
}

ITEM *pilha_desempilhar(PILHA *p){
	if(p != NULL){
		ITEM *aux;
		aux = p->i[p->tamanho];
		p->i[p->tamanho] = NULL;
		p->tamanho--;
		return(aux);
	}
	return(NULL);
}
```