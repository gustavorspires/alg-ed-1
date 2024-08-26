# Aula 5 - Pilhas - Parte 2
### Nós (Nodes)
#### Definição
- Espaço da memória heap que contém informação
	- Dados que forem armazenados dentro do nó (por exemplo, um item)
	- Um ponteiro apontando para o próximo nó
	- O último item da lista aponta para null, finalizando a lista

Vantagem: não precisa saber a quantidade de dados a priori
Desvantagem: Implementação mais complexa
##### Exemplo
```c
typedef struct node_ NODE;

struct node_ {
ITEM *i;
NODE *prev;
};
```

#### Implementação
```c
// Cria a pilha, apontando o topo para NULL e o tamanho para 0
STACK* stack_create(void){
	STACK* aux;
	aux = (STACK*) malloc(sizeof(STACK));
	
	if(aux != NULL){
		aux->top = NULL;
		aux->size = 0;
	}
	return(aux);
}

// Libera os itens da pilha, apontando o ponteiro para null
void stack_free(STACK** s){
	NODE* aux;
	if(((*s) != NULL) && (!stack_empty(*s))){
		aux = (*s)->top;
		(*s)->top = (*s)->top->prev;
		free_item(&aux->item);
		aux->prev = NULL;
		free(aux);
		aux = NULL;
	}
	free(*s);
	*s = NULL;
}

//Comando insert/empilhar, criando um novo nó que recebe i, o ponteiro para anterior aponta para o top e o top aponta para o novo nó, aumentando o tamanho;
bool stack_push(STACK *s, ITEM *i){
	NODE *n = (NODE*) malloc(sizeof(NODE));
	if(n != NULL){
		n->i = i;
		n->prev = s->top;
		s->top = n;
		s->size++;
		return true;
	}
	return false;
}

//Comando pop/desempilhar, onde um nó n recebe o topo da pilha, o item recebe i, o ponteiro top aponta para o anterior e o nó n é liberado.
ITEM* stack_pop(STACK *s){
	if(s != null && !stack_empty){
		NODE *n = s->top;
		ITEM *i = s->top->item;
		s->top = s->top->prev;
		n->prev = NULL;
		free(n);
		n = NULL;
		s->size--;
		return(i);
	}
	return(NULL);
}

// Verifica se a pilha está vazia
bool stack_empty(STACK *s) {
	if(stack != NULL){
		return((stack->size == 0) ? true ; false);
	}
	return(false);
}

// Verifica se a pilha está cheia
bool stack_full(STACK *s){
	if(s != NULL){
		NODE *n = (NODE*) malloc(sizeof(NODE));
		if (n != NULL) {
			free(n);
			return false;
		}
		return true;
	}
}

// Verifica o tamanho da pilha
int stack_size(STACK *s){
	return((s != NULL) ? s->size : -1);
}

// Retorna o item no topo da pilha
ITEM* stack_top(STACK *s){
	if((s != NULL) && (!stack_empty(s))){
		return(s->top->item);
	}
	return NULL;
}
```