#ifndef __ATTR_INNER_CLASSES_H__
#define __ATTR_INNER_CLASSES_H__

#include "../attribute_info.hpp"



namespace Attribute{
  typedef struct{
    uint16_t inner_class_info_index;
    uint16_t outer_class_info_index;
    uint16_t inner_name_index;
    uint16_t inner_class_access_flags;
  }InnerClassAttributes;


  class InnerClasses : public AttributeInfo{
    private:
      uint16_t number_of_classes;
      vector<InnerClassAttributes> classes;

      void pushNewInnerClassStructure();
    public:    
      InnerClasses(AttrInitialValue initial_val);

      void printInfo();
  };
}

#endif
