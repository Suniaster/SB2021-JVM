#include "../../include/attribute_info_classes/code_attribute.hpp"

Attribute::CodeAttribute::CodeAttribute(AttrInitialValue initial_value)
    :AttributeInfo(initial_value)
  {
    FileReader* file_reader = this->class_file->file_reader;
    this->number_of_instructions=0;

    file_reader->readBytes(2, this->max_stack);
    file_reader->readBytes(2, this->max_locals);
    file_reader->readBytes(4, this->code_length);
    this->loadInstructions();
    file_reader->readBytes(2, this->exception_table_length);
    this->loadExceptioTable();
    file_reader->readBytes(2, this->attributes_count);
    AttributeInfo::loadAttributes(this->attributes, this->attributes_count, this->class_file);

}

void Attribute::CodeAttribute::loadInstructions(){
  FileReader* file_reader = this->class_file->file_reader;
  int initial_pos, final_pos;

  for(uint16_t i=0;i<this->code_length;){
    uint8_t bytecode_read;
    initial_pos = file_reader->position;

    file_reader->readBytes(1, bytecode_read);
    Instructions::BaseInstruction* newInstruction = Instructions::BaseInstruction::getInstance(this, bytecode_read);
    
    final_pos = file_reader->position;
    i += final_pos - initial_pos;

    this->code.push_back(newInstruction);
    this->number_of_instructions+=1;
  }
}

void Attribute::CodeAttribute::loadExceptioTable(){
  for(uint16_t i=0;i<this->exception_table_length;i+=1){
    CodeException* newException = new CodeException(this);
    this->exception_table.push_back(newException);
  }
}

void Attribute::CodeAttribute::printInfo(){
  Instructions::BaseInstruction* newInstruction;

  AttributeInfo::printInfo();
  cout << "\tByteCode: " << endl; 
  for(int i=0; i < this->number_of_instructions;i+=1){
    newInstruction = this->code[i];
    newInstruction->print();
  }
}