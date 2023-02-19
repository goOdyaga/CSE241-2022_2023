#ifndef TETROMINOS_H
#define TETROMINOS_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;

enum class shapes { I,O,T,J,L,S,Z,H};
typedef vector<vector<char>> shape_of_;
class Tetrominos
{
 public:
  Tetrominos();
  Tetrominos(shapes in);
  shape_of_ to_represent_I();
  shape_of_ to_represent_O();
  shape_of_ to_represent_T();
  shape_of_ to_represent_J();
  shape_of_ to_represent_S();
  shape_of_ to_represent_Z();
  shape_of_ to_represent_L();
//   shape_of_ resize_vector(shape_of_ &other);//delete empty column
  Tetrominos operator=(const Tetrominos &rside);
  void for_edit_I();//increase size of I tetrominos to 4
  void rotate(int direction);
  inline void set_shape(shape_of_ temp) {shape=temp;};
  inline const shape_of_ get_shape() const{return shape;};
  inline shapes get_shape_of_obj()const{ return shape_of_obj;};
  shape_of_  resize_vector(shape_of_ &other);
 private:
      shape_of_ shape;
      shapes shape_of_obj;
    
};

#endif
