#include "../../include/attribute_info_classes/synthetic.hpp"

Attribute::Synthetic::Synthetic(AttrInitialValue initial_value)
    :AttributeInfo(initial_value)
  {
}

void Attribute::Synthetic::printInfo(int n_tabs){
  AttributeInfo::printInfo(n_tabs);
}