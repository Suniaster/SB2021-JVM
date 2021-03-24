### Como rodar a JVM

Para rodar a JVM basta executar o seguinte comando

`./tests.sh <path_to_class>`

Exemplo:
`./test.sh ./tests/Teste.class`

O comando acima vai compilar o programa e executá-lo

Para apenas compilar o programa apenas pode ser utilizado o script make. Após o make, o executável jvm vai ser criado na pasta bin.

Se você estiver no Windows sem um executável de make o seguinte comando pode ser chamado:

`g++ src/*.cpp src/constant_pool_classes/*.cpp src/attribute_info_classes/*.cpp src/attribute_info_classes/code_attribute_classes/*.cpp src/attribute_info_classes/instruction_classes/*.cpp -std=c++11 -Wall -o bin/jvm`
