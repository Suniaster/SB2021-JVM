#ifndef __STRING_TYPE_H__
#define __STRING_TYPE_H__

#include "./component_type.hpp"

#include <vector>
#include <cstdint>

class StringType : public ComponentType{
    private:
        string value;
    public:
        StringType(JVMType content_type, string value);
        string toString();

};





#endif
