all: project8
Stack.o: stack.h
	g++ -c stack.h
project8: main.cpp Stack.o
	g++ main.cpp stack.o -o project8
clean: 
	rm -rf  *.o  project8
