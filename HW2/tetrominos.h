#ifndef TETROMINOS_H
#define TETROMINOS_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;

enum class shapes { I,O,T,J,L,S,Z};
typedef vector<vector<char>> shape_of_;
class Tetrominos
{
 public:
  Tetrominos(shapes a);
  Tetrominos();
  shape_of_ to_represent_I();
  shape_of_ to_represent_O();
  shape_of_ to_represent_T();
  shape_of_ to_represent_J();
  shape_of_ to_represent_S();
  shape_of_ to_represent_Z();
  shape_of_ to_represent_L();
  shape_of_ resize_vector(shape_of_ &other);//delete empty column
  void for_edit_I();//increase size of I tetrominos to 4
  void For_playing();//start play game
  void edit_vector(shape_of_ &other);//after rotating tetro edit vector
  void print() const;//print tetrominos
  void try_print(shape_of_ &other) const;//print result vector
  bool canFit(Tetrominos &other);
  inline shape_of_ get_shape() const{   return shape;};//return tetro shape
  static vector<Tetrominos> all_shapes;//contain all tetrominos
  void rotate(int direction);
  void set_vect(shape_of_ &other){ shape=other;};
  inline shapes get_shape_of_obj(){  return shape_of_obj;};
 private:
      static bool first_pattern_control;
      shapes shape_of_obj;
      vector<vector<char>> shape;
      static vector<vector<char>> result;
      static vector<vector<char>> result_temp;
      vector<shape_of_> all_possibility;
    
};

#endif
