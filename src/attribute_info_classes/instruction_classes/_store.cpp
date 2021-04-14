#include "../../../include/attribute_info_classes/instruction_classes/_store.hpp"
using namespace Instructions;

AbstractStore::AbstractStore(Attribute::CodeAttribute *code_attr, uint8_t opcode, uint8_t _store_opcode, uint8_t _storen_base_opcode)
    : BaseInstruction(code_attr, opcode)
{

  this->is_n_class = !(opcode == _store_opcode);

  if (!this->is_n_class)
    this->code_attr->class_file->file_reader->readBytes(1, this->param);
  else
    this->param = this->opcode - _storen_base_opcode;
}

string AbstractStore::toString()
{
  if (this->is_n_class)
    return this->getName() + "_" + this->hexToString(this->param);
  else
    return this->getName() + " " + this->hexToString(this->param);
}

Istore::Istore(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : AbstractStore(code_attr, opcode, 0x36, 0x3b) {}

string Istore::getName() { return "istore"; }

Lstore::Lstore(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : AbstractStore(code_attr, opcode, 0x37, 0x3f) {}

string Lstore::getName() { return "lstore"; }

Fstore::Fstore(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : AbstractStore(code_attr, opcode, 0x38, 0x43) {}

string Fstore::getName() { return "fstore"; }

Dstore::Dstore(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : AbstractStore(code_attr, opcode, 0x39, 0x47) {}

int Dstore::execute(Frame *frame)
{
  uint64_t value = frame->operand_stack.pop();
  frame->local_variables.insert(this->param, value);

  if (this->is_n_class)
    frame->local_pc += 1;
  else
    frame->local_pc += 2;

  return frame->local_pc;
}

string Dstore::getName() { return "dstore"; }

Astore::Astore(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : AbstractStore(code_attr, opcode, 0x3a, 0x4b) {}
string Astore::getName() { return "astore"; }