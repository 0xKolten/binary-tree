all: main

main: bst.o main.o
	g++ -std=c++11 bst.o main.o -o main

bst.o: bst.cpp bst.h 
	g++ -std=c++11 -c bst.cpp

main.o: main.cpp bst.h
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o main