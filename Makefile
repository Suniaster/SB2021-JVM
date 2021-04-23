SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := $(shell find . -name "*.cpp")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# usado somente pra criacao de folder obj
SUBDIRS := $(shell find $(SRC_DIR) -type d)
OBJSUBDIRS := $(subst src,obj,$(SUBDIRS))

LDFLAGS := -g
CPPFLAGS := -std=c++11 -g -Wall
CXXFLAGS :=-std=c++11 -g -Wall

main2:
	make update
	make -j10 bin/jvm2

bin/jvm2: $(OBJ_FILES)
	g++ $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp ./include/%.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

update:
	mkdir -p $(OBJSUBDIRS)

clean:
	rm -r ./obj/*