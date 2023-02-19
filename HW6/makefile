all:clean main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

main:main.o
	g++ main.o -o driver1
	./driver1

clean:
	rm -f *.o
	rm -f driver1