#include "../../../include/attribute_info_classes/instruction_classes/tableswitch.hpp"
using namespace Instructions;


TableSwitch::TableSwitch(Attribute::CodeAttribute* code_attr, uint8_t opcode, uint32_t pc)
    :BaseInstruction(code_attr, opcode){ 
    FileReader *f = this->code_attr->class_file->file_reader;

    int8_t lixo;
    // Faz a posicao de leitura ir para o proximo multiplo de 4;
    while(pc % 4 != 0){f->readBytes(1, lixo);pc++;};
    f->position--;

    
    f->readBytes(4, this->default_bytes);
    f->readBytes(4, this->low_bytes);
    f->readBytes(4, this->high_bytes);

    this->table_length = this->high_bytes - this->low_bytes + 1;

    int32_t read_offset;
    for(int i=0;i<this->table_length;i++){
      f->readBytes(4, read_offset);
      this->jump_offsets.push_back(read_offset);
    }
}

void TableSwitch::print(int n_tabs){
  cout << "tableswitch " << this->intToString(low_bytes);
  cout << " to " << this->intToString(high_bytes) << endl;

  for(int i=0; i< this->table_length;i++){
    cout << tabs(n_tabs+2);
    cout << i << ":  ";
    cout <<  this->intToString(this->pc + this->jump_offsets[i]);
    cout << " (" << this->intToSignedString(this->jump_offsets[i]) <<  ")";
    cout << endl;
  }

  cout << tabs(n_tabs+2) << "default: " << this->intToString(this->pc + this->default_bytes) 
  <<" (" << this->intToSignedString(this->default_bytes) << ")" << endl;
}

int TableSwitch::execute(Frame *frame) {
  int32_t index = frame->operand_stack.pop().first;
  uint32_t base_address = frame->local_pc;

  for (int i = this->low_bytes; i <= this->high_bytes; i++) {
    if ((int32_t)index == i) {
      frame->local_pc = base_address + this->jump_offsets[i];
      return frame->local_pc;
    }
  }

  frame->local_pc = base_address + this->default_bytes;
  return frame->local_pc;
}