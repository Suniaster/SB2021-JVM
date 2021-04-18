#ifndef __METHOD_HANDLE_TYPE_H__
#define __METHOD_HANDLE_TYPE_H__

#include "./component_type.hpp"
#include "../../constant_pool_classes/method_handle_info.hpp"
#include <vector>
#include <cstdint>



class MethodHandleType : public ComponentType{
    private:
        CP::MethodHandleInfo*  cp_entry;
        string method_descriptor_raw;
        string method_interpretation_raw;
        string resolved_method_descriptor;
        string resolved_method_interpretation;
        string class_or_interface;
        string f_name;
        string return_type;
        vector<string> parameters;
    public:
        MethodHandleType(JVMType content_type, CP::MethodHandleInfo* cp_entry);
        void setMethodDescriptorRaw();
        void setMethodInterpretationRaw();

};





#endif
