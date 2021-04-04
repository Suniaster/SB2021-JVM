### Como rodar a JVM

Para rodar a JVM basta executar o seguinte comando

`./tests.sh <path_to_class>`

Exemplo:
`./test.sh ./tests/Teste.class`

O comando acima vai compilar o programa e executá-lo

Para apenas compilar o programa apenas pode ser utilizado o script make. Após o make, o executável jvm vai ser criado na pasta bin.

Se você estiver no Windows sem um executável de make o seguinte comando pode ser chamado:

`g++ src/*.cpp src/constant_pool_classes/*.cpp src/attribute_info_classes/*.cpp src/attribute_info_classes/code_attribute_classes/*.cpp src/attribute_info_classes/instruction_classes/*.cpp -std=c++11 -Wall -o bin/jvm`



----- Objetivos
- Dar load  nas classes e super_classes do programa 
- Criar rotina que acha metodo main
- Criar rotinas de adicao de frame, passando um metodo como argumento
- Criar rotina de execucao de metodo (no frame), tendo um metodo como argumento
- Criar rotina geral de execucao de instrucao

-- Detalhes
- Entender se classe JVMStack realmente eh util
- Achar um jeito de um metodo ter referencia para constant pool da sua classe (acho que ja tem)
- Ver como vai ser feito invocacao de methodo a partir do nome da classe + nome do metodo
- Como achar instrucao certa em um methodo dado um determinado pc? (mudar estrutura vector para hashmap?)
- Como lidar com invocacao e finalizacao de methodo? (invoke`s, e return`s)


-- TODO:
- MethodArea: Verifficar se classe ja foi loadada antes de adiconar ela;