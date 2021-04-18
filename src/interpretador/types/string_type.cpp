#include "../../../include/interpretador/types/string_type.hpp"

StringType::StringType(string value):ComponentType(JVMString){
    this->value = value;
}

string StringType::toString(){
    return this->value;
}
