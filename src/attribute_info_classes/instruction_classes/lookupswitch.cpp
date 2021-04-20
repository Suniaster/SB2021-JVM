#include "../../../include/attribute_info_classes/instruction_classes/lookupswitch.hpp"
using namespace Instructions;


LookupSwitch::LookupSwitch(Attribute::CodeAttribute* code_attr, uint8_t opcode, uint32_t pc)
    :BaseInstruction(code_attr, opcode){ 
    FileReader *f = this->code_attr->class_file->file_reader;

    int8_t lixo;
    // Faz a posicao de leitura ir para o proximo multiplo de 4;
    while(pc % 4 != 0){f->readBytes(1, lixo);pc++;};
    f->position--;

    
    f->readBytes(4, this->default_bytes);
    f->readBytes(4, this->n_pairs);

    int32_t read_value;
    for(int i=0;i<this->n_pairs;i++){
      f->readBytes(4, read_value);
      this->matchs.push_back(read_value);

      f->readBytes(4, read_value);
      this->offsets.push_back(read_value);
    }
}

void LookupSwitch::print(int n_tabs){
  cout << "lookupswitch " << this->intToString(n_pairs);
  cout << endl;

  for(int i=0; i< this->n_pairs;i++){
    cout << tabs(n_tabs+2);
    cout << this->intToString(this->matchs[i]) << ":  ";
    cout << this->intToString(this->pc + this->offsets[i]);
    cout << " (" << this->intToSignedString(this->offsets[i]) <<  ")";
    cout << endl;
  }

  cout << tabs(n_tabs+2) << "default: " << this->intToString(this->pc + this->default_bytes) 
  <<" (" << this->intToSignedString(this->default_bytes) << ")" << endl;
}

int LookupSwitch::execute(Frame *frame) {
  int32_t key = frame->operand_stack.pop().first;
  uint32_t base_address = frame->local_pc;

  for (int i = 0; i < this->n_pairs; i++) {
    if ((int32_t)key == this->matchs[i]) {
      frame->local_pc = base_address + this->offsets[i];
      return frame->local_pc;
    }
  }

  frame->local_pc = base_address + this->default_bytes;
  return frame->local_pc;
}
