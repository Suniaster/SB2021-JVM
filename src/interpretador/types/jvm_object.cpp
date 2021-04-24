#include "../../../include/interpretador/types/jvm_object.hpp"
#include "../../../include/interpretador/heap.hpp"
#include "../../../include/interpretador/method_area.hpp"

JVMObject::JVMObject(string c):JVMClass(c){}

void JVMObject::initializeFields(){
  vector<JVMField*> allFields = JVMClass::getFieldsFor(this->class_name);
  for(size_t i=0;i<allFields.size();i+=1){
    JVMField* field = allFields[i];
    if(!field->field_info_ref->isStatic()){
      this->addField(field);
    }
  }
}
