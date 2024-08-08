# Aula 2 - Tipos Abstratos de Dados
#### Aula ministrada no dia 08/08/2024

## Tipo de Dado
- Método para interpretar o conteúdo da memória do computador. Define a quantidade de bytes a serem utilizados para representar um valor (dado) e como interpretar a sequência de bits correspondente a esse valor.
- Caracteriza o conjunto de valores a que uma constante pertence, ou que podem ser assumidos por uma variável ou expressão, ou que podem ser gerados por uma função
### Algoritmo
- Sequência de ações executadas para solucionar um problema
### Estrutura de Dados
Organização de dados e operações que podem ser aplicadas como forma de solução de problemas complexos
### Programa
Formulações concretas de algoritmos abstratos (Wirth, 1976). Algoritmos que podem ser executado em computadores

## Definição de Tipo Abstrato de Dado
- É um conjunto de valores, com uma sequência de operações sobre esses valores
- Modelo para definir e representar um tipo de dado estruturado
- É usado para encapsular tipos de dados (Pensar nas operações suportadas e não em como são implementadas)
- Matematicamente falando, pode ser visto como uma tupla _(v,o)_, onde v é o conjunto de valores e o é o conjunto de operações aplicadas a esses valores.
- Funciona de forma parecida com um Objeto (em POO), porém os conceitos de herança e polimorfismo não se aplicam.

## Ocultamento de Informação
- Dados armazenados podem ser manipulados apenas pelas operações definidas na interface
- Só se tem acesso às operações de manipulação de dados e não aos dados em si.

## TAD e Estruturas de Dados
- Uma estrutura de dados pode ser vista como a implementação de um TAD (construída a partir dos tipos básicos (int, float, double, char) e tipos estruturados (arrays, structs) de uma linguagem)
- Um mesmo TAD pode ter diversas implementações (Por exemplo, um mesmo TAD pode ser implementado em um array e em uma lista encadeada)

### Vantagens do uso de TAD
- Reuso
- Manutenção
- Correção
- Independência de representação

## Como implementar um TAD
- Requer que operações sejam definidas sobre os valores sem estarem atreladas a uma implementação específica
    - O programador não precisa saber como os tipos são representados internamente na memória do computador, assim como pilhas (stacks) e listas (queues)
- O conceito é suportado por linguagens de programação procedimentais (Ex: Java, Python, C, C++)
- Para definir um TAD, é necessário descrevê-lo em dois módulos:
    - Módulo de definição: declaração da estrutura de dados e implementação de cada operação (Arquivos .c)
    - Módulo de interface: Define as possíveis operações (Como por exemplo os protótipos das funções) (Arquivos .h)
    - Dessa forma, os usuários podem usar o TAD apenas pela interface, sem acessar o módulo de definição.