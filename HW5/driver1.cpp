#include "TetrisVector.h"
#include "AbstractTetris.h"
#include "TetrisArray1D.h"
#include "TetrisAdapter.h"
#include "TetrisAdapter.cpp"

using namespace GTU;



int main()
{
    string temp;
    string board_size;
    Abstracttetris*temp_obj;
    bool control=true;
    while (1)
    {
        cout<<"1:PLAY GAME\n"
            <<"2:EXIT GAME\n"<<endl;
        getline(cin,temp);
        if(temp=="1")
        {
            cout<<"Enter Game board"<<endl;/*determine to board size*/
            getline(cin,board_size);
            cout<<"1:VECTOR Game Board\n"
                <<"2:1-D Array Game Board\n"/*determine to board type*/
                <<"3:Adapter Class Game Board\n"<<endl;
            

                getline(cin,temp);
                if(temp=="1")
                    temp_obj =new TetrisVector(board_size);
                else if(temp=="2")
                    temp_obj = new Tetris1DArray(board_size);
                else if(temp=="3")
                {
                    cout<<"Chose random acces iterator class"<<endl;
                    cout<<"1.vector<char>\n"
                        <<"2.deque<char>\n"
                        <<"3.list<char>\n"<<endl;
                    getline(cin,temp);
                    if(temp=="1")
                        temp_obj = new TetrisAdapter<vector<char>>(board_size);
                    else if(temp=="2")
                        temp_obj = new TetrisAdapter<deque<char>>(board_size);
                    else if(temp=="3")
                        temp_obj = new TetrisAdapter<list<char>>(board_size);
                }

                // Abstracttetris*temp_obj =new TetrisAdapter<list<char>>("15x10");
                int move_count,move_direct,direct_count,rotate_direct;
                
                while (true)
                {
                    control=true;
                    cout<<"1.Enter Tetromino Name\n";
                    cout<<"Q:Save file and quit\n";
                    cout<<"2.enter Read for Read from file:\n";
                    getline(cin,temp);
                    if(temp=="Read")
                    {
                        control=false;
                        cout<<"ENTER FILE NAME...(extension of file have to be txt and file name must contain only letters)"<<endl;
                        getline(cin,temp);
                        if(temp_obj->control_file_name(temp))   
                        {
                            cout<<"TRUE FILE NAMEEEE"<<endl;
                            fstream file(temp,ios::in);
                            if(file)
                            {
                                cout<<"Tetris Game Have loded from "<<temp<<endl;
                                fstream file1(temp,ios::in);
                                temp_obj->readFromFile(file1);
                                file1.close();
                                temp_obj->draw();
                            }
                            else
                                cout<<"There is no file that have this name . Try again please!!"<<endl;
                        }
                        else    
                            cout<<"FALSE FILE NAMEEE"<<endl;
                    }
                    else if(temp=="I"||temp=="i")
                        temp_obj->Play_game(shapes::I);
                    else if(temp=="o"||temp=="O")
                        temp_obj->Play_game(shapes::O);
                    else if(temp=="l"||temp=="L")
                        temp_obj->Play_game(shapes::L);
                    else if(temp=="s"||temp=="S")
                        temp_obj->Play_game(shapes::S);
                    else if(temp=="t"||temp=="T")
                        temp_obj->Play_game(shapes::T);
                    else if(temp=="z"||temp=="Z")
                        temp_obj->Play_game(shapes::Z);
                    else if(temp=="J"||temp=="j")
                        temp_obj->Play_game(shapes::J);
                    else if(temp=="q"||temp=="Q")
                    {
                        cout<<"ENTER FILE NAME...(extension of file have to be txt and file name must contain only letters)"<<endl;
                        getline(cin,temp);
                        
                        if(temp_obj->control_file_name(temp))   
                        {
                            cout<<"TRUE FILE NAMEEEE"<<endl;
                            //  string file_name("output");
                            //     file_name=file_name+to_string(TetrisVector::total_object)+".txt";
                            fstream file(temp,ios::out);
                            temp_obj->writeToFile(file);
                            file.close();
                        }
                        else    
                            cout<<"FALSE FILE NAMEEE"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"Invalid input"<<endl;
                        control=false;

                    }
                    if(control)
                    {

                        string tetromino_last(temp);
                        // temp_obj->Play_game(shapes::);

                        cout<<"Choose Rotate Direction \n"
                        <<"1-LEFT\n"
                        <<"2-RIGHT\n"
                        <<"3⁻NONE"<<endl;
                        while(true)
                        {
                            getline(cin,temp);
                            if((temp[0]<'1'||temp[0]>'3')||temp.length()>1||temp.length()==0) 
                                cout<<"Invalid temp.try Again!!"<<endl;
                            else
                                break;
                        }
                        rotate_direct=stoi(temp);        
                        while(true)
                        {
                            cout<<"Enter count of rotate  direction number\n";
                            getline(cin,temp);
                            if((temp[0]<'1'||temp[0]>'5')||temp.length()>1||temp.length()==0) 
                            {
                                cout<<"Invalid temp.try Again!!"<<endl;
                                //return Play_game();
                            }
                            else 
                                break;
                        }
                    
                        direct_count=stoi(temp);
                        cout<<"Choose Move Direction \n"
                        <<"1-LEFT\n"
                        <<"2-RIGHT\n"
                        <<"3⁻NONE"<<endl;
                        
                        while (true)
                        {
                            getline(cin,temp);
                            if((temp[0]<'1'||temp[0]>'3')||temp.length()>1||temp.length()==0) 
                            {
                                cout<<"Invalid temp.try Again!!"<<endl;
                            }
                            else
                                break;
                        }
                        
                        move_direct=stoi(temp);
                        while (true)
                        {
                            cout<<"Enter count of move  direction number\n";
                            getline(cin,temp);
                            if(temp_obj->is_number(temp)) 
                            {
                                move_count=stoi(temp);

                                break;
                            }
                            else
                                cout<<"Invalid temp.try Again!!"<<endl;
                        }
                        temp_obj->set_variables(move_count,move_direct,direct_count,rotate_direct);
                        temp_obj->Play_game(temp_obj->get_objec_of_tetrominos().get_shape_of_obj());
                        temp_obj->animate();
                        cout<<temp_obj->lastMove(tetromino_last);
                        cout<<"\nTotal move number of Game is "<<temp_obj->numberOfMoves()<<endl;

                    }
                    
                        /* code */
                }
                
               

        }
        else if(temp=="2")
        {
            cout<<"GAME'S HAS FINISHED"<<endl;
                break;
        }
    }
    

}
    