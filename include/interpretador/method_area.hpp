#ifndef __METHOD_AREA_H__
#define __METHOD_AREA_H__
class MethodArea;

#include "../class_file.hpp"
#include "../method_info.hpp"
#include "../attribute_info_classes/code_attribute.hpp"

using namespace std;

class MethodArea{
  private:
    vector<ClassFile*> classes;

    MethodInfo* main_method;
    void searchMainMethod(ClassFile*);

    ~MethodArea();
    MethodArea(){};
    static MethodArea* instance;
  public:
    static MethodArea* getInstance();
    static void realeaseInstance();
    // Verifica se classe ja foi carregada e adiciona-a a lista de classes caso nao
    ClassFile* insertNewClass(string class_name);

    // Procura pelo metodo public static main entre os arquivos carregados
    MethodInfo* getMainMethod();
    MethodInfo* getMethodByName(string class_name, string methodName, string args_descriptor);

    ClassFile* getClassFile (string class_name);
    bool isAlreadyIncluded  (string class_name);

    bool classHasMethod(string class_name, string method_name, string args_descriptor);
};

#endif
