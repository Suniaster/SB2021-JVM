OBJS = src/*.cpp

all : $(OBJS)
	g++ $(OBJS) -std=c++11 -Wall -o bin/jvm