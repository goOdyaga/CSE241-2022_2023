#include "Tetro.h"
using namespace GTU_hamza;
Tetrominos * Tetrominos::all_shapes;
int Tetrominos::size_of_tetrominos=0;

int main()
{
    char *in=new char[2];
    in[1]='\0';
    char *temp=nullptr;
    char *inputs=new char[20];
    
    inputs[0]='i';
    inputs[1]='o';
    inputs[2]='t';
    inputs[3]='l';
    inputs[4]='s';
    inputs[5]='j';
    inputs[6]='s';
    inputs[7]='o';
    inputs[8]='s';
    inputs[9]='t';
    inputs[10]='t';
    inputs[11]='o';
    inputs[12]='s';
    inputs[13]='j';
    inputs[14]='q';
    inputs[15]='l';
    inputs[16]='z';
    inputs[17]='i';
    inputs[18]='j';
    inputs[19]='z';
    cout<<"========================= WELCOME TETRO GAME ====================="<<endl;
    cout<<"========================= DRIVER1 HAS RUNNED. GAME WILL PLAY AUTOMATICALLY.\nJUST WATCH  ====================="<<endl;
    //in=Tetro::get_line(in);
    char *m=new char[6];
    m[0]='1';
    m[1]='5';
    m[2]='x';
    m[3]='1';
    m[4]='5';
    m[5]='\0';
    Tetro a(m);
    //cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
    //a.Play_game();
    //cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;

    shapes *shapes_enum=new shapes [7];
    shapes_enum[0]= shapes::  I;
    shapes_enum[1]= shapes::  J;
    shapes_enum[2]= shapes::  L;
    shapes_enum[3]= shapes::  O;
    shapes_enum[4]= shapes::  S;
    shapes_enum[5]= shapes::  T;
    shapes_enum[6]= shapes::  Z;
    int i=-1;
    cout<<"------------------"<<endl;
    // cout<<"Enter Terminos Name "<<endl;
    Tetrominos *obj=nullptr;
    while(i<20)   // cin>>Tetro::char_cmpr(in,   ) 
    {   
      
        in[0]=inputs[++i];
        if(Tetro::char_cmpr(in,"I")||Tetro::char_cmpr(in,"i"))
        {
            obj= new Tetrominos(shapes::I);
            Tetrominos::set_shape(*obj);
        }
        else if(Tetro::char_cmpr(in,"O")||Tetro::char_cmpr(in,"o"))
        {
            obj= new Tetrominos(shapes::O);
            Tetrominos::set_shape(*obj);
           
        }
        else if(Tetro::char_cmpr(in,"T")||Tetro::char_cmpr(in,"t"))
        {
            obj= new Tetrominos(shapes::T);
            Tetrominos::set_shape(*obj);
           
        }
        else if(Tetro::char_cmpr(in,"J")||Tetro::char_cmpr(in,"j"))
        {
            obj= new Tetrominos(shapes::J);
            Tetrominos::set_shape(*obj);
           
        }
        else if(Tetro::char_cmpr(in,"S")||Tetro::char_cmpr(in,"s"))
        {
            obj= new Tetrominos(shapes::S);
            Tetrominos::set_shape(*obj);
           
        }
        else if(Tetro::char_cmpr(in,"Z")||Tetro::char_cmpr(in,"z"))
        {
            obj= new Tetrominos(shapes::Z);
            Tetrominos::set_shape(*obj);
           
        }
        else if(Tetro::char_cmpr(in,"L")||Tetro::char_cmpr(in,"l"))
        {
            obj= new Tetrominos(shapes::L);
            Tetrominos::set_shape(*obj);
           
        }
        else if(Tetro::char_cmpr(in,"Q")||Tetro::char_cmpr(in,"q"))
        {
            cerr<<"You have been quit game.Game will be terminated "<<endl;
            
        }
        else if(Tetro::char_cmpr(in,"R")||Tetro::char_cmpr(in,"r"))
        {
            obj= new Tetrominos(shapes_enum[rand()%7]);
            Tetrominos::set_shape(*obj);
            // Tetrominos::set_shape(obj);
           break;
        }
        else
            cout<<"Invalid tetrominos trying !!!Try Again!!"<<endl;
        int move_count,move_direct,direct_count,rotate_direct;
        a+= Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1];  
        cout<<"Choose Rotate Direction \n"
        <<"1-LEFT\n"
        <<"2-RIGHT\n"
        <<"3⁻NONE"<<endl;
      
        
        rotate_direct=rand()%2+1;
        delete [] temp;
        temp=nullptr;
        
       
        direct_count=rand()%3+1;;
        delete [] temp;
        temp=nullptr;
        cout<<"Choose Move Direction \n"
        <<"1-LEFT\n"
        <<"2-RIGHT\n"
        <<"3⁻NONE"<<endl;
       
        
        move_direct=rand()%2+1;;
    
        delete [] temp;
        temp=nullptr;
        
       
        move_count=rand()%7+1;
                a.Play_game(move_count,move_direct,direct_count,rotate_direct);     
    }


    //std::this_thread::sleep_for(std::chrono::milliseconds(50));
    //a.Draw();

}