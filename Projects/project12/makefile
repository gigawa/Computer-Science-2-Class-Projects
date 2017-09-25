all: project12
Rectangle.o: rectangle.cpp inheritance.h
	g++ -c rectangle.cpp inheritance.h
Prism.o: rectangularPrism.cpp inheritance.h
	g++ -c rectangularPrism.cpp inheritance.h
Circle.o: circle.cpp inheritance.h
	g++ -c circle.cpp inheritance.h
Cylinder.o: cylinder.cpp inheritance.h
	g++ -c cylinder.cpp inheritance.h
project12: main.cpp Rectangle.o Prism.o Circle.o Cylinder.o
	g++ main.cpp rectangle.o rectangularPrism.o circle.o cylinder.o -o project12
clean: 
	rm -rf  *.o  project12
