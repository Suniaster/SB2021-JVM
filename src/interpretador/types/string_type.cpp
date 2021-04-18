#include "../../../include/interpretador/types/string_type.hpp"

StringType::StringType(JVMType content_type, string value):ComponentType(content_type){
    this->value = value;
}

string StringType::toString(){
    return this->value;
}
