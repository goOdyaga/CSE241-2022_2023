#ifndef TETROMINOS_H
#define TETROMINOS_H
#include<iostream>
#include<vector>
#include<string>
#include "Tetro.h"
using namespace std;

enum class shapes { I,O,T,J,L,S,Z};
typedef char** shape_of_;
class Tetrominos
{
 public:
     Tetrominos(shapes a);
     Tetrominos();

     shape_of_ to_represent_I();
     shape_of_ to_represent_O();
     shape_of_ to_represent_T();/*to represent teterominos*/
     shape_of_ to_represent_J();
     shape_of_ to_represent_S();
     shape_of_ to_represent_Z();
     shape_of_ to_represent_L();

     shape_of_ resize_vector(shape_of_ other );//delete empty column

     inline const shape_of_ get_shape() const{   return shape;};//return tetro shape
     
     static Tetrominos* all_shapes;//contain all tetrominos
     
     void rotate(int direction);/*rotate tetrominos*/
     void set_shape(shape_of_ vect);  /* set shape that variable of tetrominos*/   

     static void set_shape(const Tetrominos &obj);/*add each object to all_shapes array*/
     static inline int get_size_of_tetrominos(){return size_of_tetrominos;};
     inline shapes get_shape_of_obj()const { return shape_of_obj;};/*return enum type of terominos object*/
     
     char** shape;/*pointer for tetrominos*/

     inline int get_x()const{return x;};/*return size of shape's column and row*/
     inline int get_y()const{return y;};
 private:
      shapes shape_of_obj;
      static int size_of_tetrominos; 
      int x,y;
    
};

#endif
