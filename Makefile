OBJS = src/*.cpp
CONSTANT_POOL = src/constant_pool_classes/*.cpp
ATTRIBUTES = src/attribute_info_classes/*.cpp
CODE_ATTRS = src/attribute_info_classes/code_attribute_classes/*.cpp
INSTRUCTIONS = src/attribute_info_classes/instruction_classes/*.cpp
CC_FLAGS = -std=c++11 -g -Wall -c
WINDOWS_CC_FLAGS = -std=c++11 -g -Wall -o

all:
	make -j4 objs cp attributes code_attrs instructions
	make executable

objs : $(OBJS)
	g++ $(OBJS)  $(CC_FLAGS)

attributes :  $(ATTRIBUTES)
	g++ $(ATTRIBUTES)  $(CC_FLAGS)

code_attrs: $(CODE_ATTRS)
	g++  $(CODE_ATTRS) $(CC_FLAGS)

instructions: $(INSTRUCTIONS)
	g++   $(INSTRUCTIONS) $(CC_FLAGS)

cp : $(CONSTANT_POOL)
	g++ $(CONSTANT_POOL) $(CC_FLAGS)

executable:
	g++ *.o -g -o ./bin/jvm

windows: $(OBJS) $(ATTRIBUTES) $(CODE_ATTRS) $(INSTRUCTIONS) $(CONSTANT_POOL)
	x86_64-w64-mingw32-g++ $(OBJS) $(ATTRIBUTES) $(CODE_ATTRS) $(INSTRUCTIONS) $(CONSTANT_POOL) $(WINDOWS_CC_FLAGS)  ./bin/jvm

clean:
	rm *.o
