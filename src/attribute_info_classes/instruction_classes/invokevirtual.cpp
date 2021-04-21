#include "../../../include/attribute_info_classes/instruction_classes/invokevirtual.hpp"
using namespace Instructions;


InvokeVirtual::InvokeVirtual(Attribute::CodeAttribute* code_attr, uint8_t opcode)
    :BaseInstruction(code_attr, opcode){
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);    
}

string InvokeVirtual::toString(){
  return this->createStringWithCPRef("invokevirtual", this->index);
}

int InvokeVirtual::execute(Frame* frame){
  string symbolic_ref = frame->current_method->class_file->getConstantPoolEntry(this->index)->toString();

  frame->operand_stack.print();
  if(symbolic_ref == "java/io/PrintStream.println"){
    pair<uint64_t, JVMType> val = frame->operand_stack.pop();
    frame->operand_stack.pop();
    PrimitiveType x(val.first, val.second);
    cout << x.toString() << endl;
  }

  frame->local_pc += 3;
  return frame->local_pc;
}