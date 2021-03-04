#include "../../include/attribute_info_classes/code_attribute.hpp"

Attribute::CodeAttribute::CodeAttribute(AttrInitialValue initial_value)
    :AttributeInfo(initial_value)
  {
    this->number_of_instructions=0;
}

void Attribute::CodeAttribute::setInfo(){
  FileReader* file_reader = this->class_file->file_reader;

  // Ponteiros temporarios usados nos loops
  Instructions::BaseInstruction* newInstruction;
  CodeException* newException;
  AttributeInfo* newAttribute;
  uint8_t bytecode_read;
  uint16_t i;
  file_reader->readBytes(2, this->max_stack);
  file_reader->readBytes(2, this->max_locals);

  file_reader->readBytes(4, this->code_length);

  cout << "max stack: " << hex << this->max_stack <<endl;
  cout << "max local: " << hex << this->max_locals <<endl;
  cout << "code length: " << hex << this->code_length <<endl;
  for(i=0;i<this->code_length;){
    file_reader->readBytes(1, bytecode_read);
    i+=1;
    newInstruction = Instructions::BaseInstruction::getInstance(this, bytecode_read);

    i += newInstruction->readOperands();
    this->code.push_back(newInstruction);
    this->number_of_instructions+=1;
  }

  file_reader->readBytes(2, this->exception_table_length);
  for(i=0;i<this->exception_table_length;i+=1){
    newException = new CodeException(this);
    newException->setInfo();
    this->exception_table.push_back(newException);
  }

  file_reader->readBytes(2, this->attributes_count);
  for(i=0;i<this->attributes_count;i+=1){
    // Comentado ate a funcao de pegar instancia estar correta
    // newAttribute = AttributeInfo::getInstance(this->class_file);
    // newAttribute->setInfo();
    // this->attributes.push_back(newAttribute);
  }
}

void Attribute::CodeAttribute::printInfo(){
  Instructions::BaseInstruction* newInstruction;

  AttributeInfo::printInfo();
  for(int i=0; i < this->number_of_instructions;i+=1){
    newInstruction = this->code[i];
    newInstruction->print();
  }
}