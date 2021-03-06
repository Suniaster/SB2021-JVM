#include "../../../include/attribute_info_classes/instruction_classes/invokespecial.hpp"
#include "../../../include/interpretador/invoke_simulation.hpp"
#include "../../../include/interpretador/reference_resolver.hpp"
#include "../../../include/constant_pool_classes/method_ref_info.hpp"
#include "../../../include/interpretador/invoke_simulation.hpp"

using namespace Instructions;

InvokeSpecial::InvokeSpecial(Attribute::CodeAttribute *code_attr, uint8_t opcode)
    : BaseInstruction(code_attr, opcode)
{
  FileReader *f_reader = this->code_attr->class_file->file_reader;
  f_reader->readBytes(2, this->index);
}

string InvokeSpecial::toString()
{
  return this->createStringWithCPRef("invokespecial", this->index);
}

int InvokeSpecial::execute(Frame *frame)
{
  CP::MethodRefInfo *ref_info = (CP::MethodRefInfo *)frame->current_method->class_file->getConstantPoolEntry(this->index);
  string symbolic_ref = ref_info->toString();
  string descriptor = ref_info->getDescriptor();
  pair<string, string> names = ReferenceResolver::separateSymbol(symbolic_ref, ".");

  if (ReferenceResolver::isValidClassName(names.first))
    frame->thread->invokeInstanceMethod(names.first, names.second, descriptor);
  else if (names.first.find("Exception") != std::string::npos || names.first.find("Error") != std::string::npos) {
    InvokeSimulation::exceptionInit(frame, names.first, this->index);
  }
  else if(names.first == "java/lang/StringBuilder" || names.first == "java/lang/String"){
    InvokeSimulation::stringMethod(names.second, frame, this->index);
  }

  return frame->local_pc+=3;
}