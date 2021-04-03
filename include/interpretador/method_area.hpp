#ifndef __METHOD_AREA_H__
#define __METHOD_AREA_H__

#include "../class_file.hpp"
#include "../attribute_info_classes/code_attribute.hpp"

using namespace std;

class MethodArea{
  private:
    vector<ClassFile*> classes;

  public:
    // Verifica se classe ja foi carregada e adiciona-a a lista de classes caso nao
    ClassFile* insertNewClass(string class_name);

    // Procura pelo metodo public static main entre os arquivos carregados
    Attribute::CodeAttribute getMainMethod();
};

#endif
