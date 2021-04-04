#ifndef __EXECUTION_ENGINE_H__
#define __EXECUTION_ENGINE_H__

#include "../class_file.hpp"
#include "./method_area.hpp"

class ExecutionEngine{
  private:
    MethodArea method_area;
    vector<Thread*> threads;
  public:

    void start();
    void loadMethodArea(string intial_class_name);
};
#endif
