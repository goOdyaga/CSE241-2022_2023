all:hw4_2
	./hw4_valgrind

hw4_1: hw4_main.o hw4_lib.o
	g++ hw4_main.o hw4_lib.o -o hw4_not_valgrind	
hw4_2: hw4_main.o hw4_lib.o
	g++ hw4_main.o hw4_lib.o -o hw4_valgrind
	
hw4_main.o: hw4_main.cpp
	g++ -std=c++11 -c hw4_main.cpp
hw4_lib.o: hw4_lib.cpp
	g++ -std=c++11 -c hw4_lib.cpp

