#ifndef ABSTRACTTETRIS_H
#define ABSTRACTTETRIS_H

#include "tetrominos.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <chrono>
#include <thread>
#include<fstream>
#include<iterator>
#include<list>
#include<deque>

using namespace std;

namespace GTU
{
    class Abstracttetris
    {
        public:
            Abstracttetris();
            ~Abstracttetris();
            virtual void draw() =0;/*o draw the Tetris board*/
            virtual void readFromFile (fstream &file)  =0;//Reads the game from the file given as function parameter
            virtual void writeToFile(fstream &file) =0;//Writes the game to the file given as function paramete
            virtual void  operator+=(const Tetrominos &obj1 ) =0;//Adds a Tetromino to the board. The new Tetromino will be added at the top row in the middle.
            virtual void animate()=0;//Animate function to animate the added tetromino dropping to the bottom of the board
            virtual void fit()const =0;
            virtual string lastMove(string tetromino) const=0;//Returns the last move, if there is no last move, throws exception
            virtual int numberOfMoves ()  =0;//Returns the number of steps (moves) this board made

            virtual void Play_game(shapes in)final;/*take tetromino object and add it to tetris board after that animate it*/
            virtual bool control_file_name(const string &file_name) final;/*control file name truth*/
            inline static bool is_number(const string &s) {  return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);};/*control number for number*/
            virtual void set_variables(int move_count1,int move_direct1,int direct_count1,int rotate_direct1)final;/*set variables for movea and rotate*/
            virtual bool input_controller(string input)final;
            inline const Tetrominos &get_objec_of_tetrominos()const{return objec_of_tetrominos;};/*return  tetromino objct type*/
            virtual inline int get_x()const final{return x;};/*return size of shape's column and row*/
            virtual inline int get_y()const final{return y;};

        protected:
            Tetrominos objec_of_tetrominos;/*type of tetromino objects*/
            int x,y;/*row and column of tetromino objects*/
            vector<vector<char>> vect;/*contain of tetromino object*/
            string first_part,second_part;/*first and second part use for create game board. first part is row and second part is column*/
            int move_count,move_direct,direct_count,rotate_direct;/*move and rotate data's*/
            
        private:

    };

}




#endif
