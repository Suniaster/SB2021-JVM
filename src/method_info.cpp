#include "../include/method_info.hpp"
#include "../include/attribute_info_classes/code_attribute.hpp"
#include "../include/attribute_info_classes/code_attribute_classes/instruction.hpp"

MethodInfo::MethodInfo(ClassFile *class_file) {
    this->class_file = class_file;
    this->class_file->file_reader->readBytes(2, this->access_flags);
    this->class_file->file_reader->readBytes(2, this->name_index);
    this->class_file->file_reader->readBytes(2, this->descriptor_index);
    this->class_file->file_reader->readBytes(2, this->attributes_count);
    AttributeInfo::loadAttributes(this->attributes, this->attributes_count, this->class_file);
}

MethodInfo::~MethodInfo() {
  this->class_file->deleteVector(this->attributes);
}

string MethodInfo::getName(){
  return this->class_file->getConstantPoolEntry(this->name_index)->toString();
}

Attribute::CodeAttribute* MethodInfo::getCode(){
  for(uint32_t i=0;i<this->attributes.size();i+=1){
    if(this->attributes[i]->getAttributeName() == "Code")
      return (Attribute::CodeAttribute*) this->attributes[i];
  }
  throw runtime_error("Metodo sem atributo Code!");
}

Instructions::BaseInstruction* MethodInfo::getInstruction(int pc){
  return this->getCode()->getInstructionByPc(pc);
}

void MethodInfo::printInfo() {
  cout << dec;
  cout << "\tName:              cpinfo #" << this->name_index << " <" << this->class_file->getConstantPoolEntry(this->name_index)->toString() << ">" << endl;
  cout << "\tDescriptor:        cpinfo #" << this->descriptor_index << " <" << this->class_file->getConstantPoolEntry(this->descriptor_index)->toString() << ">" << endl;
  cout << "\tAccess flags:      0x" << hex << this->access_flags << " " << this->class_file->beautifiedAccessFlags(this->access_flags, false, true) << endl;
  AttributeInfo::printAttributes(this->attributes, 2);
}

string MethodInfo::getDescriptorString() {
  return this->class_file->getConstantPoolEntry(this->descriptor_index)->toString();
}

int MethodInfo::getArgsCountOn(string descriptor){
   // TODO: codar isso direito
  string types = "BCDFIJSZ";
  int n_args = 0;
  size_t i, j;

  for(i=0;i<descriptor.size();i+=1){
    if(descriptor[i] == ')') break;

    if(types.find(descriptor[i]) != string::npos){
      n_args++;
      continue;
    }

    if( descriptor[i] == 'L'){
      for(j=i;j<descriptor.size();j+=1){
        if(descriptor[j] == ';') break;
      }
      i = j; 
    }
  }
  return n_args;
}

int MethodInfo::getArgsCount(){
  string descriptor = this->getDescriptorString();
  return MethodInfo::getArgsCountOn(descriptor);
}
