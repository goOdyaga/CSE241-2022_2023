#ifndef TETRO_H
#define TETRO_H

#include<cstdlib>
#include<ctime>
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <chrono>
#include <thread>
#include "tetrominos.h"

using namespace std;

class Tetro
{
 public:
    Tetro(string input);
    Tetro();
    void Add(Tetrominos &object);
    void Fit();
    void Draw();
    void Animate(bool intertwine,shape_of_ &vect);
    bool input_controller(string input); 
    bool create_Terominos();
    inline static bool is_number(const string &s) {  return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);};
    void Play_game();
    void print_best_fit(shape_of_ &vect);


 private:
    shape_of_ game_board;
    string first_part;
    string second_part;
    int cursor;
    bool first_step;
    int x,y;
    bool first_draw;
    
};

#endif