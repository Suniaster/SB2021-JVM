#include "../../../include/interpretador/types/jvm_object.hpp"
#include "../../../include/interpretador/heap.hpp"
#include "../../../include/interpretador/method_area.hpp"

JVMObject::JVMObject(string c):JVMClass(c){}

void JVMObject::initializeFields(){
  Heap* heap          = Heap::getInstance();
  ClassFile* cl_file  = this->class_file ;

  for(uint16_t i=0;i< cl_file->fields.size();i+=1){
    FieldInfo* field  = cl_file->fields[i];

    if(!field->isStatic()){
      JVMField* newFieldAlocated = new JVMField(field);
      heap->storeComponent(newFieldAlocated);
      this->addField(newFieldAlocated);
    }
  }
}
