OBJS = src/*.cpp
CONSTANT_POOL = src/constant_pool_classes/*.cpp
ATTRIBUTES = src/attribute_info_classes/*cpp
all : $(OBJS)
	g++ $(OBJS) $(CONSTANT_POOL) $(ATTRIBUTES) -std=c++11 -Wall -o bin/jvm 