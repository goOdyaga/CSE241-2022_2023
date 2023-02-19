#ifndef TETRIS1DARRAY_H
#define TETRIS1DARRAY_H


#include "AbstractTetris.h"


using namespace std;
namespace GTU
{

    class Tetris1DArray: public Abstracttetris
    {
        public:
            Tetris1DArray();
            Tetris1DArray(string input);
            ~Tetris1DArray();

            virtual void draw() ;
            virtual void readFromFile (fstream &file)  ;
            virtual void writeToFile(fstream &file) ;
            virtual void  operator+=(const Tetrominos &obj1 );
            virtual void animate();
            virtual void fit()const ;
            virtual string lastMove(string tetromino) const;
            virtual int numberOfMoves ()  ;

        private:
            char *game_board;
            int total_move;
            bool first_draw;

    };

}




#endif