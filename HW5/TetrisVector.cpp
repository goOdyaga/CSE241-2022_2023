// #include "AbstractTetris.h"
#include "TetrisVector.h"
#include "tetrominos.h"
namespace GTU
{
    
    TetrisVector::TetrisVector():total_move(0){};

    
    TetrisVector::TetrisVector(string input):first_draw(false),total_move(0)
    {
        while(1)
        {

            if(input_controller(input))/*taking string for gameboard size*/
            {
                game_board.resize(stoi(first_part),vector<char>(stoi(second_part),' '));
                break;
            }
            else
            {
                cerr<<"Invalid game board size . Try again please!!"<<endl;
            }
        }
        this->draw();
    }

   

    
    void TetrisVector::draw()  /*draw game board. set cursor and colors for play game*/
    {
        vector<string> colors={"\033[30m","\033[31m","\033[32m","\033[33m","\033[34m","\033[35m","\033[36m","\033[37m"};
        if(first_draw)
        {   
            int a=stoi(first_part)+2;
            int b=stoi(second_part)+2;
            cout<<"\33["<<to_string(a)<<"A"<<"\33["<<to_string(b)<<"D";/*at the first draw cursor dont backforward. after first step it can cursor backward delete game board redraw on it*/
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
       first_draw=true;
        for(auto i=0;i<game_board.size()+2;i++ )
        {
            for(auto j=0;j<game_board.at(0).size()+2;j++ )
            {
                // cout<<i<<" "<<j<<endl;
                if(i==0)
                    cout<<"X";
                else if(j==0)
                    cout<<"X";
                else if(i==game_board.size()+1)
                    cout<<"X";
                else if(j==game_board.at(0).size()+1)
                    cout<<"X";
                else
                    cout<<colors.at(rand()%colors.size())<<game_board.at(i-1).at(j-1)<< "\033[0m";
            }
            cout<<endl;
        }
    
    }

    
    void TetrisVector::  operator+=(const Tetrominos &obj1 )
    {
        /*firstly I add vector the board and draw it and after drawing I return the situation of the board first step that dont contain new vector*/
        for( auto i=0;i<obj1.get_shape().size();i++)
        {
            for( auto j=0;j<obj1.get_shape().at(0).size();j++)
            {   
                if(game_board.at(i).at(j+(game_board.at(0).size()/2))==' ')
                    game_board.at(i).at(j+(game_board.at(0).size()/2))=obj1.get_shape().at(i).at(j);
                else
                {
                    cerr<<"THERE IS NO SPACE FOR NEW TETROMINO.GAME HAS fileISHED"<<endl;
                    exit(1);
                }
            }
        }
        this->draw();
        for( auto i=0;i<obj1.get_shape().size();i++)
        {
            for( auto j=0;j<obj1.get_shape().at(0).size();j++)
            {   
                game_board.at(i).at(j+(game_board.at(0).size()/2))=' ';
            }
        }
    }

    
    void TetrisVector:: readFromFile (fstream &file)  
    {
        // fstream file;
        // string file_name("output0.txt");
        // file.open(file_name, ios::in);
        string buff,game_type;
        int control=0;
        int flag=0,movem;
        int temp1,temp2;
        vector<char> one;
        vector<vector<char>>two;
        file.seekg(0,ios::beg);
        while(!file.eof())
        {
            getline(file,buff);
            if(control==0&&buff=="TOTAL MOVE NUMBER IS:")
            {
                getline(file,buff);
                total_move=stoi(buff);
            }
            else if(control==0&&buff=="GAME :")
                control++;
            else if(control==1)
            {
                for(int i=0;i<buff.size();i++)
                {
                    if(buff[i]=='-')
                   one.push_back(' ');
                   else
                   one.push_back(buff.at(i));
                }
                two.push_back(one);
                one.clear();
            }
            
        }
        game_board=two;
        first_part=to_string(game_board.size());
        second_part=to_string(game_board[0].size());
        // cout<<"BOARD HAS  BEEN LOAD FROM FILE SUCCESFULL!!"<<endl<<"Game type is : "<<game_type<<endl<<"Board number is : "<<board_number<<endl<<"movement of this borad is : "<<get_movement()<<endl;
    }

    
    void TetrisVector:: writeToFile(fstream &file) 
    {
        file<<"TOTAL MOVE NUMBER IS:"<<endl;
        file<<total_move<<endl;
        file<<"GAME :"<<endl;
        
        for(auto &x:game_board)
        {
            for(auto & y: x )
            {
                if(y==' ')
                    file<<'-';
                else
                    file<<y;
            }
            file<<'\n';
        }
        // file.seekg(0, ios::beg);
    //exit(0);
    }
   

    void TetrisVector:: fit()const 
    {}
   

    
    string TetrisVector ::lastMove(string tetromino) const
    {
        string str;
        try
        {
            if(move_direct==1)
            {   
                return "Last move of "+tetromino+" Tetromino is to left and it move "+to_string(move_count)+" square\n";
            }
            else if(move_direct==2)
            {
                return "Last move of "+tetromino+" Tetromino is to right and it move "+to_string(move_count)+" square\n";
            }
            throw move_direct;
        }
        catch(int move_direct)
        {
            cout<<"Last move operation is Invalid!!";
        }
        
        return "CONTROL";
        
    
    }

    
    int TetrisVector::numberOfMoves ()  
    {
        try
        {
            if(move_direct==1||move_direct==2)
            {
                total_move+=move_count;
                return total_move;
            }
            throw move_direct;
        }
        catch(int move_direct)
        {
            return total_move;
        }
        
        return total_move;
    }
    
    void TetrisVector ::animate()/*animate terominos put it right place*/
    {
        int i=0,j=stoi(second_part)/2,z=0,row_total;
        bool exitt=false,eqit2=false;
        
        if(move_direct==1)
        {
            if((j-move_count)>=0)
            {
                exitt=false;
                while(i<=move_count)
                {
                    
                    
                    for(int k=0;k<get_x();k++)
                    {
                        for(int l=0;l<get_y();l++)
                        {
                            if(game_board[k+z][l+(stoi(second_part)/2)-i]==' ')
                                game_board[k+z][l+(stoi(second_part)/2)-i]=vect[k][l];
                        }
                    }
                    this->draw();
                    for(int k=0;k<get_x();k++)
                    {
                        for(int l=0;l<get_y();l++)
                        {
                            game_board[k+z][l+(stoi(second_part)/2)-i]=' ';
                        }
                    } 
                    i++;
                    exitt=false;
                    for(int m=0;m<get_x();m++)
                    {
                        char c=game_board[m+z][(stoi(second_part)/2)-i]+vect[m][0]-' ';
                        if(!(c==' '||c==vect[m][0]||c==game_board[m+z][(stoi(second_part)/2)-i]))
                            exitt=true;
                    }
                    if(exitt)
                    {
                            --i;   
                        for(int k=0;k<get_x();k++)
                        {
                            for(int l=0;l<get_y();l++)
                            {
                                if(game_board[k+z][l+(stoi(second_part)/2)-i]==' ')
                                    game_board[k+z][l+(stoi(second_part)/2)-i]=vect[k][l];
                            }
                        }
                        break;
                    }
                    else if(i==move_count)
                    {
                    for(int k=0;k<get_x();k++)
                        {
                            for(int l=0;l<get_y();l++)
                            {
                                if(game_board[k+z][l+(stoi(second_part)/2)-i]==' ')
                                    game_board[k+z][l+(stoi(second_part)/2)-i]=vect[k][l];
                            }
                        } 
                        i++;
                    }
                }
                if(i!=0)
                    --i;
                exitt=false;
                row_total=(stoi(second_part)/2)-i;
            }
            else
            {
                cout<<"The specified number of spaces does not exist in the specified direction"<<endl;
                move_direct=0;
                return;
            }
            

        }
        if(move_direct==2)
        {
            if(j+move_count+get_y()-1<(stoi(second_part)))
            {
                while(i<=move_count)
                {
                    for(int k=0;k<get_x();k++)
                    {
                        for(int l=0;l<get_y();l++)
                        {
                            if(game_board[k+z][l+(stoi(second_part)/2)+i]==' ')
                                game_board[k+z][l+(stoi(second_part)/2)+i]=vect[k][l];
                        }
                    }
                    this->draw();
                    for(int k=0;k<get_x();k++)
                    {
                        for(int l=0;l<get_y();l++)
                        {
                            game_board[k+z][l+(stoi(second_part)/2)+i]=' ';
                        }
                    } 
                    i++;
                    exitt=false;
                    for(int m=0;m<get_x();m++)
                    {
                        char c=game_board[m+z][(stoi(second_part)/2)-i]+vect[m][0]-' ';
                        if(!(c==' '||c==vect[m][0]||c==game_board[m+z][(stoi(second_part)/2)+i]))
                            exitt=true;
                    }
                    if(exitt)
                    {
                        --i;   
                        for(int k=0;k<get_x();k++)
                        {
                            for(int l=0;l<get_y();l++)
                            {
                                if(game_board[k+z][l+(stoi(second_part)/2)+i]==' ')
                                    game_board[k+z][l+(stoi(second_part)/2)+i]=vect[k][l];
                            }
                        }
                        break;
                    }
                }
                if(i!=0)
                    --i;
                exitt=false;
                row_total=(stoi(second_part)/2)+i;
            }
            else
            {
                cout<<"The specified number of spaces does not exist in the specified direction"<<endl;
                move_direct=0;
                return;
            }
        }
        
        while(z+get_x()<stoi(first_part))
        {
            
            for(int m=0;m<get_y();m++)
            {
                char c=game_board[(z+get_x()-1)][m+row_total]+vect[get_x()-1][m]-' ';
                if(((c==game_board[(z+get_x()-1)][m+row_total]))&&c!=' ')
                    eqit2=true;
            }
            if(eqit2)
            {
                cout<<"YAGSAAAAAA"<<endl;
                for(int k=0;k<get_x();k++)
                {
                    for(int l=0;l<get_y();l++)
                    {
                        if(game_board[k+z][l+row_total]==' ')
                            game_board[k+z][l+row_total]=vect[k][l];
                    }
                }
                this->draw();
                break;
                // exit(0);

            }
            else
            {
                for(int k=0;k<get_x();k++)
                {
                    for(int l=0;l<get_y();l++)
                    {
                        if(game_board[k+z][l+row_total]==' ')
                            game_board[k+z][l+row_total]=vect[k][l];
                    }
                }
            }
            this->draw();
            
            for(int k=0;k<get_x();k++)
            {
                for(int l=0;l<get_y();l++)
                {
                    game_board[k+z][l+row_total]=' ';
                }
            }  
            z++;
            if((z+get_x()-1)==stoi(first_part)-1)
            {
                //--z;
                for(int k=0;k<get_x();k++)
                {
                    for(int l=0;l<get_y();l++)
                    {
                        if(game_board[k+z][l+row_total]==' ')
                            game_board[k+z][l+row_total]=vect[k][l];
                    }
                }
                this->draw();
                break;
                // ++z;
            }
            for(int m=0;m<get_y();m++)
            {
                char c=game_board[(z+get_x()-1)][m+row_total]+vect[get_x()-1][m]-' ';
                if(!(c==' '||c==vect[get_x()-1][m]||c==game_board[(z+get_x()-1)][m+row_total]))
                    exitt=true;
            }
            if(exitt)
            {
                cout<<"YAGAAAA"<<endl;
               // exit(0);
                --z;
                for(int k=0;k<get_x();k++)
                {
                    for(int l=0;l<get_y();l++)
                    {
                        if(game_board[k+z][l+row_total]==' ')
                            game_board[k+z][l+row_total]=vect[k][l];
                    }
                }
                break;
            }
            
        }
    }   
       
     
    


}