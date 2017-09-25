all: project11
ListN.o: listnode.cpp listnode.h
	g++ -c listnode.cpp listnode.h
ListA.o: listarray.cpp listarray.h
	g++ -c listarray.cpp listarray.h
project11: main.cpp ListN.o ListA.o
	g++ main.cpp listnode.o listarray.o -o project11
clean: 
	rm -rf  *.o  project11
