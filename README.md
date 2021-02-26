### Como rodar a JVM

Para rodar a JVM basta executar o seguinte comando

`./tests.sh path_to_class`

Exemplo:
`./test.sh ./tests/Teste.class`


### Arquivo Teste:

| posicao | nome         |   | tam  |   |
|---|---------------|---|---|---|
| 0 | magic         |   | 4 |   |
| 4 | minor_v       |   | 2 |   |
| 6 | major_v       |   | 2 |   |
| 8 | cp_pool_count |   | 2 |   |
| 10 | cp           |   |103|   |
| 0x113 | access_flags|   | 2 |   |
| 0x160 | methods_count|   | 2 |   |
| 0x178 | attr_count|   | 2 |   |

Methodref_info - 5
fieldref_info - 5
string_info - 3
class_info - 3
utf8_info - 4
nameandType_info - 5