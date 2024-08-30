# Aula 5 - Filas e Deques - Parte 1

### Fila (Queue)
#### O que é
Estrutura para armazenar um conjunto de elementos
	- Novos elementos sempre entram no fim da fila
	- O único elemento que se pode retirar da fila em um dado momento é seu primeiro elemento

#### Para que serve
- Situações onde é preciso armazenar conjuntos ordenados de elementos, onde o primeiro a entrar também é o primeiro a sair
	- FIFO - First-in, First-out

#### Aplicações
- Filas de espera e algoritmos de simulação
- Controle por parte do SO de recursos compartilhados
- Buffers de entrada/saída
- ED auxiliar em alguns algoritmos (busca em largura)

#### Operações principais
- fila_criar()
- fila_inserir()
- fila_remover()

#### Implementação
##### Alocação Sequencial
- Os elementos da fila ficam em sequência na memória
- Todo o espaço reservado permanece reservado durante todo o tempo de execução do programa.
	Início: aponta pro primeiro elemento da fila (onde o elemento sai)
	Fim: aponta para o último elemento da fila (onde um novo elemento entra)
###### Sequencial Circular
- O início não é fixo na primeira posição
- O fim pode retornar para a posição 00 do vetor, pensando o array como um anel.
