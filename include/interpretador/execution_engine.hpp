#ifndef __EXECUTION_ENGINE_H__
#define __EXECUTION_ENGINE_H__

#include "../class_file.hpp"
#include "./method_area.hpp"
#include "./heap.hpp"

class ExecutionEngine{
  private:
    static ExecutionEngine* instance;
    ExecutionEngine(){};
  
    MethodArea method_area;
    vector<Thread*> threads;
    Heap* heap;
  public:

    Thread* main_thread;
    static ExecutionEngine* getInstance();
    void start();
    void loadMethodArea(string intial_class_name);
};
#endif
