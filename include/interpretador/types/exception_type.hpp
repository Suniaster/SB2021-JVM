#ifndef __EXCEPTION_TYPE_H__
#define __EXCEPTION_TYPE_H__

#include "./component_type.hpp"

#include <vector>
#include <cstdint>

class ExceptionType : public ComponentType
{
  private:
    string name;
    string args;

  public:
    ExceptionType(string value);
    void setArgs(string args);
    string toString();
};

#endif
