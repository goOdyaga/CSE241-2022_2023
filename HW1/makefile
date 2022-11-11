all:hw1
	./hw1

hw1: main.o tetromis.o
	g++ tetromis.o main.o -o hw1	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
tetromis.o: tetromis.cpp
	g++ -std=c++11 -c tetromis.cpp
