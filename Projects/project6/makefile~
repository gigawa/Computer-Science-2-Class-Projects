all: project6
Agency.o: Agency.cpp Agency.h
	g++ -c Agency.cpp Agency.h
project6: project6.cpp Agency.o
	g++ project6.cpp Agency.o -o project6
clean: 
	rm -rf  *.o  project6
