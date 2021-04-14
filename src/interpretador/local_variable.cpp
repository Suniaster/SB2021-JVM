#include "../../include/interpretador/local_variable.hpp"

void LocalVariable::initialize(uint32_t max_length)
{
  JVMType_t<uint8_t> *value = new JVMType_t<uint8_t>();
  value->data = 0;

  this->local_variables.push_back(value);
}

void LocalVariable::print()
{
  for (int i = 0; i < this->local_variables.size(); i++)
  {
    cout << this->get<uint64_t>(i) << endl;
  }
}
