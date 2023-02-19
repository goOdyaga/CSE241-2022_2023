#ifndef TETRISVECTOR_H
#define TETRISVECTOR_H


#include "AbstractTetris.h"


using namespace std;
namespace GTU
{

    class TetrisVector: public Abstracttetris
    {
        public:
            TetrisVector();
            TetrisVector(string input);
            ~TetrisVector();

            virtual void draw() ;
            virtual void readFromFile (fstream &file)  ;
            virtual void writeToFile(fstream &file) ;
            virtual void  operator+=(const Tetrominos &obj1 );
            virtual void animate();
            virtual void fit()const ;
            virtual string lastMove(string tetromino) const;
            virtual int numberOfMoves ()  ;

        private:
            vector<vector<char >>game_board;
            int total_move;
            bool first_draw;

    };

}




#endif