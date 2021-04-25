#ifndef __STRING_TYPE_H__
#define __STRING_TYPE_H__

#include "./component_type.hpp"

#include <vector>
#include <cstdint>

class StringType : public ComponentType{
    private:
    public:
        string value;

        StringType( string value);
        string toString();

};





#endif
