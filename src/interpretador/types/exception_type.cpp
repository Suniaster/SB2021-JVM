#include "../../../include/interpretador/types/exception_type.hpp"

ExceptionType::ExceptionType(string name): ComponentType(Reference){
    this->name = name;
}

string ExceptionType::toString(){
  return "Exception in thread 'main': " + this->name + this->args;
}

void ExceptionType::setArgs(string args) {
  this->args += " " + args;
}