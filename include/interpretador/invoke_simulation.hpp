//
// Created by gabriel on 23/04/2021.
//


#ifndef __INVOKE_SIMULATION_H__
#define __INVOKE_SIMULATION_H__

#include "heap.hpp"
#include "method_area.hpp"

using namespace std;

class InvokeSimulation{
    private:
    static string getResultStringFromArgs(int n_args, Frame*);
    public:
    static void println(Frame*, int method_ref_index);
    static void stringMethod(string method_name, Frame*, int method_ref_index);
};



#endif
