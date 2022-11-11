#include "Tetro.h"

vector<Tetrominos> Tetrominos::all_shapes;
vector<vector<char>> Tetrominos::result;
vector<vector<char>> Tetrominos::result_temp;
bool Tetrominos::first_pattern_control=true;
int main()
{/*this board w,ll execute by automat,cally.therefore I choose all value. for different output you can change input that contain board size an change
 inputs tetro that contain all tetro's*/
    string input("15x15");
    cout<<"========================= WELCOME TETRO GAME ====================="<<endl;
    cout<<"========================= DRIVER2 HAS RUNNED. GAME WILL PLAY AUTOMATICALLY .====================="<<endl;
    cout<<"Please determine the size of game board(like 3x5(row is 3 and colum is 5) ";
    //getline(cin,input);
    Tetro a(input);
  //  a.Play_game();

    string name_of_tet;
    vector<shapes> shapes_enum={shapes::I,shapes::J,shapes::L,shapes::O,shapes::S,shapes::T,shapes::Z};
    vector<string> inputs_tetro={"i","l","s","z","r","o","t","z","r","o","i","l","j","o","r","t","s","l","z","t","j","r","o","s","q"};
    // cout<<"Enter Terminos Name "<<endl;
    
    for(int i=0;i<inputs_tetro.size();i++)
    { 
        // getline(cin,name_of_tet);
        name_of_tet=inputs_tetro.at(i);
        if(name_of_tet=="I"||name_of_tet=="i")
        {
            Tetrominos:: all_shapes.push_back(Tetrominos(shapes::I));
           
        }
        else if(name_of_tet=="O"||name_of_tet=="o")
        {
            Tetrominos:: all_shapes.push_back(Tetrominos(shapes::O));
           
        }
        else if(name_of_tet=="T"||name_of_tet=="t")
        {
            Tetrominos:: all_shapes.push_back(Tetrominos(shapes::T));
           
        }
        else if(name_of_tet=="J"||name_of_tet=="j")
        {
            Tetrominos:: all_shapes.push_back(Tetrominos(shapes::J));
           
        }
        else if(name_of_tet=="S"||name_of_tet=="s")
        {
            Tetrominos:: all_shapes.push_back(Tetrominos(shapes::S));
           
        }
        else if(name_of_tet=="Z"||name_of_tet=="z")
        {
            Tetrominos:: all_shapes.push_back(Tetrominos(shapes::Z));
           
        }
        else if(name_of_tet=="L"||name_of_tet=="l")
        {
            Tetrominos:: all_shapes.push_back(Tetrominos(shapes::L));
           
        }
        else if(name_of_tet=="Q"||name_of_tet=="q")
        {
            cerr<<"You have been quit game.Game will be terminated "<<endl;
           break;
        }
        else if(name_of_tet=="R"||name_of_tet=="r")
        {
            Tetrominos:: all_shapes.push_back(Tetrominos(shapes_enum.at(rand()%(shapes_enum.size()))));
        }
        else
            cout<<"Invalid tetrominos trying !!!Try Again!!"<<endl;
        a.Play_game();/*call this function for each tetromino an it will play game*/
    
    }


    //std::this_thread::sleep_for(std::chrono::milliseconds(50));
    //a.Draw();

}