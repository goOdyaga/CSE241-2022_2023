#include "Tetro.h"

vector<Tetrominos> Tetrominos::all_shapes;
vector<vector<char>> Tetrominos::result;
vector<vector<char>> Tetrominos::result_temp;
bool Tetrominos::first_pattern_control=true;
int main()
{
    string input;
    cout<<"========================= WELCOME TETRO GAME ====================="<<endl;
    cout<<"========================= DRIVER1 HAS RUNNED. GAME WILL PLAY MANUALLY.\nENTER THE TETROMİNOS NAMES AFTER THE ENTER BOARD SIZE  ====================="<<endl;
    cout<<"Please determine the size of game board(like 3x5(row is 3 and colum is 5) ";
    getline(cin,input);
    Tetro a(input);
    //cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
    //a.Play_game();
    //cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;

    string name_of_tet;
    vector<shapes> shapes_enum={shapes::I,shapes::J,shapes::L,shapes::O,shapes::S,shapes::T,shapes::Z};
    // cout<<"Enter Terminos Name "<<endl;
    
    while(true)   // cin>>name_of_tet;
    {   
        getline(cin,name_of_tet);
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
            
        }
        else if(name_of_tet=="R"||name_of_tet=="r")
        {
            Tetrominos:: all_shapes.push_back(Tetrominos(shapes_enum.at(rand()%(shapes_enum.size()))));
           break;
        }
        else
            cout<<"Invalid tetrominos trying !!!Try Again!!"<<endl;
        a.Play_game();
    
    }


    //std::this_thread::sleep_for(std::chrono::milliseconds(50));
    //a.Draw();

}