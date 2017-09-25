all: project8
Stack.o: stack3.cpp stackN.h
	g++ -c stack3.cpp stack.h
project8: project8.cpp Stack.o
	g++ project8.cpp stack3.o -o project8
clean: 
	rm -rf  *.o  project8
