all:clean driver2 driver1

driver1.o: driver1.cpp
	g++ -std=c++11 -c driver1.cpp

driver2.o: driver2.cpp
	g++ -std=c++11 -c driver2.cpp

tetromis.o: tetromis.cpp
	g++ -std=c++11 -c tetromis.cpp

AbstractTetris.o: AbstractTetris.cpp
	g++ -std=c++11 -c AbstractTetris.cpp
TetrisAdapter.o: TetrisAdapter.cpp
	g++ -std=c++11 -c TetrisAdapter.cpp
TetrisVector.o: TetrisVector.cpp
	g++ -std=c++11 -c TetrisVector.cpp
TetrisArray1D.o: TetrisArray1D.cpp
	g++ -std=c++11 -c TetrisArray1D.cpp
driver1:driver1.o tetromis.o TetrisAdapter.o TetrisVector.o TetrisArray1D.o AbstractTetris.o
	g++ tetromis.o TetrisAdapter.o TetrisVector.o TetrisArray1D.o AbstractTetris.o driver1.o -o driver1
	./driver1
driver2:driver2.o tetromis.o TetrisAdapter.o TetrisVector.o TetrisArray1D.o AbstractTetris.o
	g++ tetromis.o TetrisAdapter.o TetrisVector.o TetrisArray1D.o AbstractTetris.o driver2.o -o driver2
	./driver2

clean:
	rm -f *.o
	rm -f driver1 driver2