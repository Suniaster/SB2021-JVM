#include "../../../include/interpretador/types/method_handle_type.hpp"


MethodHandleType::MethodHandleType(JVMType content_type, CP::MethodHandleInfo* cp_entry):ComponentType(content_type){
    this->cp_entry = cp_entry;
}

void MethodHandleType::setMethodDescriptorRaw() {

    CP::MethodHandleInfo * method_handle_cp_entry = (CP::MethodHandleInfo*)this->cp_entry;
    // TO DO implement
}
void MethodHandleType::setMethodInterpretationRaw(){
    // TO DO implement
}
