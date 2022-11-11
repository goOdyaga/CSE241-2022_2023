#include "tetrominos.h"

// using namespace std;

vector<Tetrominos> Tetrominos::all_shapes;
vector<vector<char>> Tetrominos::result;
vector<vector<char>> Tetrominos::result_temp;
bool Tetrominos::first_pattern_control=true;
int main()
{
    string number_of_tet;
    int i;
    string name_of_tet;
    //vector<Tetrominos> all_shapes;
    cout<<"Welcome tetrominos Game:)))"<<endl;
    cout<<"How many Terminos you will create"<<endl;
    while(1)
    {

        getline(cin,number_of_tet);
        if(number_of_tet.at(0)>='1'&&number_of_tet.at(0)<='9')
            break;
        else
            cerr<<"Invalid Input !! Be careful!!"<<endl;
    }
    // cin>>number_of_tet;
    cout<<"Enter Terminos Name "<<endl;
    int m=(int)number_of_tet.at(0)-48;
    for(i=0;i<m;i++)
    {
        cin>>name_of_tet;
        if(name_of_tet=="I"||name_of_tet=="i")
            Tetrominos::all_shapes.push_back(Tetrominos(shapes::I));
        else if(name_of_tet=="O"||name_of_tet=="o")
            Tetrominos::all_shapes.push_back(Tetrominos(shapes::O));
        else if(name_of_tet=="T"||name_of_tet=="t")
            Tetrominos::all_shapes.push_back(Tetrominos(shapes::T));
        else if(name_of_tet=="J"||name_of_tet=="j")
            Tetrominos::all_shapes.push_back(Tetrominos(shapes::J));
        else if(name_of_tet=="S"||name_of_tet=="s")
            Tetrominos::all_shapes.push_back(Tetrominos(shapes::S));
        else if(name_of_tet=="Z"||name_of_tet=="z")
            Tetrominos::all_shapes.push_back(Tetrominos(shapes::Z));
        else if(name_of_tet=="L"||name_of_tet=="l")
            Tetrominos::all_shapes.push_back(Tetrominos(shapes::L));
        else
        {
            cout<<"Invalid tetrominos trying !!!Try Again!!"<<endl;
            i--;
        }
    }
    for(int i=0;i<Tetrominos::all_shapes.size();i++)
        Tetrominos::all_shapes.at(i).print();
    Tetrominos::For_playing();
 return 0;
}