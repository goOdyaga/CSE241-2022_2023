#ifndef TetrisAdapter_H
#define TetrisAdapter_H


#include "AbstractTetris.h"



using namespace std;
namespace GTU
{

    template<class Container>
    class TetrisAdapter: public Abstracttetris
    {
        public:
            TetrisAdapter();
            TetrisAdapter(string input);
       

            virtual void draw() ;
            virtual void readFromFile (fstream &file)  ;
            virtual void writeToFile(fstream &file) ;
            virtual void  operator+=(const Tetrominos &obj1 );
            virtual void animate();
            virtual void fit()const ;
            virtual string lastMove(string tetromino) const;
            virtual int numberOfMoves ()  ;


        private:
            Container game_board;
            int total_move;
            bool first_draw;

    };

}




#endif