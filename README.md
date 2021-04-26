### Como rodar a JVM

Para rodar a JVM basta executar o seguinte comando

`./bin/jvm <path_to_class> <modo de entrada>`

Exemplo:
`./bin/jvm ./tests/Teste.class -i`

O comando acima vai compilar o programa e executá-lo

Para alterar o modo de interpretador para exibidor, troque a flag `-i` para `-e`.

Para apenas compilar o programa apenas pode ser utilizado o script make. Após o make, o executável jvm vai ser criado na pasta bin.

Se você estiver no Windows sem um executável de make o seguinte comando pode ser chamado:

`g++ -std=c++11 ./src/*.cpp ./src/attribute_info_classes/*.cpp ./src/attribute_info_classes/code_attribute_classes/*.cpp ./src/attribute_info_classes/instruction_classes/*.cpp ./src/constant_pool_classes/*.cpp ./src/interpretador/*.cpp ./src/interpretador/types/*.cpp -o bin/jvm`

### O que foi feito:

1.(X) array simples
2.(X) arrays.length
3.(X) arrays multidimensionais
4.(X) arrays de referencia
5.(X) doubles
6.(X) floats
7.(X) longs
8.(X) inteiros  
9.(X) shorts
10.(X) strings
11.(X) desvios com cat 1 
12.(X) operacoes logicas com cat 1  
13.(X) operacoes de deslocamento com cat 1 
14.(X) operacoes aritmeticas de cat 2 
15.(X) operacoes de deslocamento de longs
16.(X) system.out.println (int, float, string e booleano)
17.(X) conversao de e para cat 2
18.(X) iteracao
19.(X) switches
20.(X) fields
21.(X) interfaces
22.(X) recursao
23.(X) metodos estaticos  
24.(X) metodos nao estaticos
25.(X) objetos 
26.(X) operacoes de retorno
27.(X) operacoes de manipulacao de pilha
28.(X) consistencia
29.(X) exceptions
30.(X) invokes
31.(X) polimorfismo
32.(X) reescrita
33.(X) heranca


--  opcionais 
Todas as demais instrucoes.

( ) threads
( ) debug
( ) checagem dinamica de tipos
(X) coletor de lixo.
