make  && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose  --log-file=valgrind-out.txt -s ./bin/jvm2 ./tests/TestClass.class
