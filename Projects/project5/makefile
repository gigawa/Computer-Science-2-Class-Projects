all: project5
String.o: String.cpp String.h
	g++ -c String.cpp String.h
project5: testDriver.cpp String.o
	g++ testDriver.cpp String.o -o project5
clean: 
	rm -rf  *.o  project5
