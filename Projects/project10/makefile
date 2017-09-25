all: project10
List.o: listnode.cpp listnode.h
	g++ -c listnode.cpp listnode.h
project10: main.cpp List.o
	g++ main.cpp listnode.o -o project10
clean: 
	rm -rf  *.o  project10
