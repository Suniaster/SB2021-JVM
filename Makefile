OBJS = src/*.cpp
CONSTANT_POOL = src/constant_pool_classes/*.cpp
ATTRIBUTES = src/attribute_info_classes/*.cpp
CODE_ATTRS = src/attribute_info_classes/code_attribute_classes/*.cpp
INSTRUCTIONS = src/attribute_info_classes/instruction_classes/*.cpp

<<<<<<< HEAD
all:
	make -j 4 objs cp
	make executable
	make clean

objs : $(OBJS)
	g++ $(OBJS) $(ATTRIBUTES) $(CODE_ATTRS) $(INSTRUCTIONS)  -std=c++11 -Wall -c

cp : $(CONSTANT_POOL)
	g++ $(CONSTANT_POOL) -std=c++11 -Wall -c

executable:
	g++ *.o -o ./bin/jvm

clean:
	rm *.o