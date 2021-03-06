OBJS = src/*.cpp
CONSTANT_POOL = src/constant_pool_classes/*.cpp
ATTRIBUTES = src/attribute_info_classes/*.cpp
CODE_ATTRS = src/attribute_info_classes/code_attribute_classes/*.cpp


all : $(OBJS)
	g++ $(OBJS) $(CONSTANT_POOL) $(ATTRIBUTES) $(CODE_ATTRS) -std=c++11 -Wall -o bin/jvm 