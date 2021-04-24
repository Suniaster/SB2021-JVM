#include "../../include/interpretador/invoke_simulation.hpp"

void InvokeSimulation::println(Frame* frame, int method_ref_index){
  CP::MethodRefInfo* m_i = (CP::MethodRefInfo*)frame->current_method->class_file->getConstantPoolEntry(method_ref_index);
  string args_descriptor = m_i->getDescriptor();

  int n_args = MethodInfo::getArgsCountOn(args_descriptor);

  for(int i=0;i<n_args;i++){
    pair<uint64_t, JVMType> val = frame->operand_stack.pop();
    if(val.second == Reference){
      ComponentType* x = Heap::getInstance()->getReference(val.first);
      cout << x->toString();
    }
    else{
      PrimitiveType x(val.first, val.second);
      cout << x.toString();
    }
  }
  cout << endl;
  frame->operand_stack.pop();
}