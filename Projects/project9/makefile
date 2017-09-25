all: project9
Queue.o: queue2.cpp queue.h
	g++ -c queue2.cpp queueN.h
project9: main.cpp Queue.o
	g++ main.cpp queue2.o -o project9
clean: 
	rm -rf  *.o  project9
