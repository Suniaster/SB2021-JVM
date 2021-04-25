#include "../../include/interpretador/invoke_simulation.hpp"
#include "../../include/interpretador/types/exception_type.hpp"

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
      PrimitiveType*x = new PrimitiveType(val.first, val.second);
      cout << x->toString();
    }
  }
  cout << endl;
  frame->operand_stack.pop();
}

string InvokeSimulation::getResultStringFromArgs(int n_args, Frame* frame){
  string resultString;
  for(int i=0;i<n_args;i++){
    pair<uint64_t, JVMType> val = frame->operand_stack.pop();
    ComponentType* arg = Heap::getInstance()->getReference(val.first);
    resultString += arg->toString();
  }
  return resultString;
}

void InvokeSimulation::stringMethod(string method_name, Frame* frame, int method_index){
  CP::MethodRefInfo* m_i = (CP::MethodRefInfo*)frame->current_method->class_file->getConstantPoolEntry(method_index);
  string args_descriptor = m_i->getDescriptor();
  int n_args = MethodInfo::getArgsCountOn(args_descriptor);

  if(method_name == "append"){
    string resultString = InvokeSimulation::getResultStringFromArgs(n_args, frame);

    pair<uint64_t, JVMType> val = frame->operand_stack.pop();
    ComponentType* baseString = Heap::getInstance()->getReference(val.first);

    int ref = Heap::getInstance()->storeComponent(new StringType(baseString->toString() + resultString));
    frame->operand_stack.push(ref, Reference);
    return;
  }
  if(method_name == "<init>"){
    string resultString = InvokeSimulation::getResultStringFromArgs(n_args, frame);

    pair<uint64_t, JVMType> val = frame->operand_stack.pop();
    StringType* baseString = (StringType*) Heap::getInstance()->getReference(val.first);

    baseString->value = resultString;
    return;
  }
  if(method_name == "toString"){
    return;
  }

  throw std::runtime_error("MethodError: Metodo "+method_name+"  -  da classe string nao suportado");
}

void InvokeSimulation::exceptionInit(Frame* frame, string exception_name, int method_ref_index) {
  CP::MethodRefInfo* m_i = (CP::MethodRefInfo*)frame->current_method->class_file->getConstantPoolEntry(method_ref_index);
  string args_descriptor = m_i->getDescriptor();
  string args;

  int n_args = MethodInfo::getArgsCountOn(args_descriptor);

  for(int i=0;i<n_args;i++){
    pair<uint64_t, JVMType> arg_pair = frame->operand_stack.pop();
    if(arg_pair.second == Reference){
      ComponentType* arg = Heap::getInstance()->getReference(arg_pair.first);
      args += arg->toString();
    }
    else{
      PrimitiveType* x = new PrimitiveType(arg_pair.first, arg_pair.second);
      args += x->toString();
    }
  }

  pair<uint64_t, JVMType> val = frame->operand_stack.pop();
  ExceptionType* exception = (ExceptionType*) Heap::getInstance()->getReference(val.first);
  exception->setArgs(args);
}