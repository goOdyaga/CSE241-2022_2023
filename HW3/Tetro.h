#ifndef TETRO_H
#define TETRO_H

#include<cstdlib>
#include<ctime>
#include<iostream>
#include <algorithm>
#include <chrono>
#include <thread>
#include "tetrominos.h"

using namespace std;
typedef char** shape_of_;
class Tetrominos;
namespace GTU_hamza
{

  class Tetro
  {
  public:
    ~Tetro();/* distructor for delete tetro object's pointer and Tetrominos objects' pointer. it wil free al memory that program haas been allocated*/
    Tetro( char * input);
    Tetro();
    void Draw();
    void Animate(bool intertwine,shape_of_ vect);
    friend void  operator+=(Tetro &obj1, Tetrominos &obj2 );

    bool input_controller( const char* input); /*control input*/
    bool is_number(const char * s);/*control for number*/
    void Play_game(int move_count1,int move_direct1,int direct_count1,int rotate_direct1);/*Playing game function*/

    /*string function for ınput controlling and manipulating*/
    static char * get_line(char *input);/*taking input from user*/
    static int str_len(const char *in) ;/*retun length of string*/
    int find(const char *input,const char *p)const ;/*return first index of p*/
    char *substr(const int a ,const int b,const char *source)const ;/*divide sitring*/
    static bool char_cmpr(const char *in1,const char *in2) ;/*dtring compare*/
    static void str_cpy(char * dest,const char * source);/*string vopy*/
  private:
      shape_of_ game_board;
      char * first_part;
      char * second_part;
      bool first_draw;
      int x,y;
      int move_count,move_direct,direct_count,rotate_direct;
      
  };

}
#endif