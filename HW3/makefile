all:clean driver1 driver2

driver1.o: driver1.cpp
	g++ -std=c++11 -c driver1.cpp

driver2.o: driver2.cpp
	g++ -std=c++11 -c driver2.cpp

tetromis.o: tetromis.cpp
	g++ -std=c++11 -c tetromis.cpp

Tetro.o: Tetro.cpp
	g++ -std=c++11 -c Tetro.cpp

driver1: driver1.o tetromis.o Tetro.o
	g++ Tetro.o tetromis.o driver1.o -o driver1
	./driver1

driver2:driver2.o tetromis.o Tetro.o
	g++ tetromis.o Tetro.o driver2.o -o driver2
	./driver2

clean:
	rm -f *.o
	rm -f driver1 driver2