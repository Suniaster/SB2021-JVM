OBJS = src/*.cpp
CONSTANT_POOL = src/constant_pool_classes/*.cpp
ATTRIBUTES = src/attribute_info_classes/*.cpp
CODE_ATTRS = src/attribute_info_classes/code_attribute_classes/*.cpp
INSTRUCTIONS = src/attribute_info_classes/instruction_classes/*.cpp


all:
	make -j 4 objs cp attributes code_attrs instructions
	make executable

objs : $(OBJS)
	g++ $(OBJS)  -std=c++11 -Wall -c -g

attributes :  $(ATTRIBUTES)
	g++ $(ATTRIBUTES)   -std=c++11 -Wall -c -g

code_attrs: $(CODE_ATTRS)
	g++  $(CODE_ATTRS) -std=c++11 -Wall -c -g

instructions: $(INSTRUCTIONS)
	g++   $(INSTRUCTIONS) -std=c++11 -Wall -c -g

cp : $(CONSTANT_POOL)
	g++ $(CONSTANT_POOL) -std=c++11 -Wall -c -g

executable:
	g++ *.o -g -o ./bin/jvm

clean:
	rm *.o
