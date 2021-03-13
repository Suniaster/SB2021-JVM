OBJS = src/*.cpp
CONSTANT_POOL = src/constant_pool_classes/*.cpp

all:
	make -j 4 objs cp
	make executable
	make clean

objs : $(OBJS)
	g++ $(OBJS)  -std=c++11 -Wall -c

cp : $(CONSTANT_POOL)
	g++ $(CONSTANT_POOL) -std=c++11 -Wall -c

executable:
	g++ *.o -o ./bin/jvm

clean:
	rm *.o
