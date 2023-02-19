#include "Tetro.h"

using namespace GTU_hamza;


Tetrominos * Tetrominos::all_shapes;
int Tetrominos::size_of_tetrominos=0;
int main()
{
    char *in=nullptr;
    char *temp=nullptr;
   
    cout<<"========================= WELCOME TETRO GAME ====================="<<endl;
    cout<<"========================= DRIVER1 HAS RUNNED. GAME WILL PLAY MANUALLY.\nENTER THE TETROMİNOS NAMES AFTER THE ENTER BOARD SIZE  ====================="<<endl;
    cout<<"Please determine the size of game board(like 3x5(row is 3 and colum is 5) ";
    in=Tetro::get_line(in);
    Tetro a(in);
    //cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
    //a.Play_game();
    //cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;

    cout<<"Enter Terminos Name "<<endl;
    Tetrominos *obj=nullptr;
    while(true)   // cin>>Tetro::char_cmpr(in,   ) 
    {   
        in=nullptr;
        cout<<"Enter Tetromino Name Please!!"<<endl;
        in=Tetro::get_line(in);
       
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
            break;
            
        }
        else if(Tetro::char_cmpr(in,"R")||Tetro::char_cmpr(in,"r"))
        {
            obj= new Tetrominos(shapes::O);
            Tetrominos::set_shape(*obj);
            // Tetrominos::set_shape(obj);
           break;
        }
        else
            cout<<"Invalid tetrominos trying !!!Try Again!!"<<endl;
        if(obj!=nullptr)
        {

        int move_count,move_direct,direct_count,rotate_direct;
        a+= Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1];  
        cout<<"Choose Rotate Direction \n"
        <<"1-LEFT\n"
        <<"2-RIGHT\n"
        <<"3⁻NONE"<<endl;
        while(true)
        {
            temp=Tetro::get_line(temp);
            if((temp[0]<'1'||temp[0]>'3')||Tetro::str_len(temp)>1||Tetro::str_len(temp)==0) 
            {
                cout<<"Invalid input.try Again!!"<<endl;
                delete []temp;
                temp=nullptr;
            } 
            else
                break;

        }
        
        rotate_direct=stoi(temp);
        delete [] temp;
        temp=nullptr;
        
        while(true)
        {
            cout<<"Enter count of rotate  direction number\n";
            temp=Tetro::get_line(temp);
            if((temp[0]<'1'||temp[0]>'5')||Tetro::str_len(temp)>1||Tetro::str_len(temp)==0) 
            {
                cout<<"Invalid input.try Again!!"<<endl;
                delete []temp;
                temp=nullptr;
                //return Play_game();
            }
            else 
                break;
        }
       
        direct_count=stoi(temp);
        delete [] temp;
        temp=nullptr;
        cout<<"Choose Move Direction \n"
        <<"1-LEFT\n"
        <<"2-RIGHT\n"
        <<"3⁻NONE"<<endl;
        
        while (true)
        {
            temp=Tetro::get_line(temp);
            if((temp[0]<'1'||temp[0]>'3')||Tetro::str_len(temp)>1||Tetro::str_len(temp)==0) 
            {
                cout<<"Invalid input.try Again!!"<<endl;
                delete []temp;
                temp =nullptr;
            }
            else
                break;
            /* code */
        }
        
        move_direct=stoi(temp);
    
        delete [] temp;
        temp=nullptr;
        
        while (true)
        {
            cout<<"Enter count of move  direction number\n";
            temp=Tetro::get_line(temp);
            if(a.is_number(temp)) 
            {
                move_count=stoi(temp);
                delete [] temp;
                temp=nullptr;
                break;
            }
            else
                cout<<"Invalid input.try Again!!"<<endl;
            /* code */
        }
                a.Play_game(move_count,move_direct,direct_count,rotate_direct);    
        }
        delete [] in;
         
    }


    //std::this_thread::sleep_for(std::chrono::milliseconds(50));
    //a.Draw();

}