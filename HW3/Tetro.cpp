#include "Tetro.h"
#include "tetrominos.h"
namespace GTU_hamza
{

    Tetro::Tetro():x(0),y(0),first_draw(false)
    {
        game_board=new char*[4];
        for(int i=0;i<4;i++)
            game_board[i]=new char[10];
        for(int i=0;i<4;i++)
            for(int j=0;j<10;j++)
                game_board[i][j]=' ';
        first_part=new char[2];
        second_part=new char[3];
        first_part[0]='4';
        first_part[1]='\0';
        second_part[0]='1';
        second_part[1]='0';
        second_part[0]='\0';
    }

    Tetro::Tetro( char * input):x(0),y(0),first_draw(false)
    {
        while(1)
        {
            if(input_controller(input))/*taking string for gameboard size*/
            {
                game_board=new char*[stoi(first_part)];
                for(int i=0;i<stoi(first_part);i++)
                    game_board[i]=new char[stoi(second_part)];
                for(int i=0;i<stoi(first_part);i++)
                {
                    for(int j=0;j<stoi(second_part);j++)
                    {
                        game_board[i][j]=' ';
                    }
                }
                break;
            }
            else
            {
                cerr<<"Invalid game board size . Try again please!!"<<endl;
                delete [] input;
                input=nullptr;
                input=get_line(input);
            }
        }
    } 

    bool Tetro::input_controller( const char* input)
    {
        int first_x=find(input,"x");/*control input for play game*/
        if(first_x==-1) 
        {
            cout<<"Invalid input"<<endl;
            exit(0);
        }
        first_part=substr(0,first_x,input);
        second_part=substr(first_x+2,str_len(input)-1,input);
        if(is_number(first_part)&&is_number(second_part))
        {
            return true;
        }
        return false;
    }

    void Tetro::Draw()/*Draw game board. set cursor and colors for play game*/
    {
        shape_of_ colors=new char*[8];
        for(int i=0;i<8;i++)
            colors[i]=new char[6];
        Tetro::str_cpy(colors[0],"\033[30m");
        Tetro::str_cpy(colors[1],"\033[31m");
        Tetro::str_cpy(colors[2],"\033[32m");
        Tetro::str_cpy(colors[3],"\033[33m");/*colorful tetrominos*/
        Tetro::str_cpy(colors[4],"\033[34m");
        Tetro::str_cpy(colors[5],"\033[35m");
        Tetro::str_cpy(colors[6],"\033[36m");
        Tetro::str_cpy(colors[7],"\033[37m");
        if(first_draw)
        {   
            int a=stoi(first_part)+2;
            int b=stoi(second_part)+2;
            cout<<"\33["<<to_string(a)<<"A"<<"\33["<<to_string(b)<<"D";/*at the first draw cursor dont backforward. after first step it can cursor backward delete game board redraw on it*/
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        first_draw=true;
        for(int i=0;i<stoi(first_part)+2;i++ )
        {
            for(int j=0;j<stoi(second_part)+2;j++ )
            {
                if(i==0)
                    cout<<"X";
                else if(j==0)
                    cout<<"X";
                else if(i==stoi(first_part)+1)
                    cout<<"X";
                else if(j==stoi(second_part)+1)
                    cout<<"X";
                else
                    cout<<colors[rand()%8]<<game_board[i-1][j-1]<< "\033[0m";
            }
            cout<<endl;
        }
        cout<<endl;
        
    }



    void Tetro::Play_game(int move_count1,int move_direct1,int direct_count1,int rotate_direct1)/*this function manipulate terominos array for add game board and animate it*/
    {   
        move_count=move_count1;
        move_direct=move_direct1;
        direct_count=direct_count1;
        rotate_direct=rotate_direct1;
        
        if(rotate_direct==1||rotate_direct==2)
        {
            for(int i=0;i<direct_count;i++)
                Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].rotate(rotate_direct);

            if(Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_shape_of_obj()==shapes::I)
            {
                if(direct_count%2==0)
                {
                    shape_of_ vect=new char*[3];
                    for(int i=0;i<3;i++)
                        vect[i]=new char;
                    for(int i=0;i<3;i++)
                        for(int j=0;j<1;j++)
                            vect[i][j]='I'; 
                }   
                else
                {
                    shape_of_ vect=new char*;
                    for(int i=0;i<1;i++)
                        vect[i]=new char[3];
                    for(int i=0;i<1;i++)
                        for(int j=0;j<3;j++)
                            vect[i][j]='I';
                }     
            }
            else
            {
                if(Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_shape_of_obj()!=shapes::O)
                {

                    shape_of_ vect=new char*[3];
                    for(int i=0;i<3;i++)
                        vect[i]=new char[3];
                    for(int i=0;i<3;i++)
                        for(int j=0;j<3;j++)
                            vect[i][j]=Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_shape()[i][j];
                        vect=Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].resize_vector(vect);
                        Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].set_shape(vect);
                }

            }

        }
        else
        {
        if(Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_shape_of_obj()==shapes::I)
            {
                shape_of_ vect=new char*[3];
                for(int i=0;i<3;i++)
                    vect[i]=new char[1];
                for(int i=0;i<3;i++)
                    for(int j=0;j<1;j++)
                        vect[i][j]=Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_shape()[i][j]; 
            }
            else
            {
                shape_of_ vect=new char*[3];
                for(int i=0;i<3;i++)
                    vect[i]=new char[3];
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        vect[i][j]=Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_shape()[i][j];
                vect=Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].resize_vector(vect);
                Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].set_shape(vect);
            } 
        }
        *this+=Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1];
            return Animate(true,Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_shape());
    }

    void Tetro::Animate(bool intertwine,shape_of_ vect)/*animate terominos put it right place*/
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
                    
                    
                    for(int k=0;k<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();k++)
                    {
                        for(int l=0;l<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();l++)
                        {
                            if(game_board[k+z][l+(stoi(second_part)/2)-i]==' ')
                                game_board[k+z][l+(stoi(second_part)/2)-i]=vect[k][l];
                        }
                    }
                    this->Draw();
                    for(int k=0;k<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();k++)
                    {
                        for(int l=0;l<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();l++)
                        {
                            game_board[k+z][l+(stoi(second_part)/2)-i]=' ';
                        }
                    } 
                    i++;
                    exitt=false;
                    for(int m=0;m<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();m++)
                    {
                        char c=game_board[m+z][(stoi(second_part)/2)-i]+vect[m][0]-' ';
                        if(!(c==' '||c==vect[m][0]||c==game_board[m+z][(stoi(second_part)/2)-i]))
                            exitt=true;
                    }
                    if(exitt)
                    {
                            --i;   
                        for(int k=0;k<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();k++)
                        {
                            for(int l=0;l<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();l++)
                            {
                                if(game_board[k+z][l+(stoi(second_part)/2)-i]==' ')
                                    game_board[k+z][l+(stoi(second_part)/2)-i]=vect[k][l];
                            }
                        }
                        break;
                    }
                    else if(i==move_count)
                    {
                    for(int k=0;k<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();k++)
                        {
                            for(int l=0;l<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();l++)
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
                return;
            }
            

        }
        if(move_direct==2)
        {
            if(j+move_count+Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y()-1<(stoi(second_part)))
            {
                while(i<=move_count)
                {
                    for(int k=0;k<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();k++)
                    {
                        for(int l=0;l<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();l++)
                        {
                            if(game_board[k+z][l+(stoi(second_part)/2)+i]==' ')
                                game_board[k+z][l+(stoi(second_part)/2)+i]=vect[k][l];
                        }
                    }
                    this->Draw();
                    for(int k=0;k<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();k++)
                    {
                        for(int l=0;l<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();l++)
                        {
                            game_board[k+z][l+(stoi(second_part)/2)+i]=' ';
                        }
                    } 
                    i++;
                    exitt=false;
                    for(int m=0;m<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();m++)
                    {
                        char c=game_board[m+z][(stoi(second_part)/2)-i]+vect[m][0]-' ';
                        if(!(c==' '||c==vect[m][0]||c==game_board[m+z][(stoi(second_part)/2)+i]))
                            exitt=true;
                    }
                    if(exitt)
                    {
                        --i;   
                        for(int k=0;k<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();k++)
                        {
                            for(int l=0;l<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();l++)
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
                return;
            }
        }
        
        while(z+Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x()<stoi(first_part))
        {
            
            for(int m=0;m<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();m++)
            {
                char c=game_board[(z+Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x()-1)][m+row_total]+vect[Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x()-1][m]-' ';
                if(((c==game_board[(z+Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x()-1)][m+row_total]))&&c!=' ')
                    eqit2=true;
            }
            if(eqit2)
            {
                cout<<"YAGSAAAAAA"<<endl;
                for(int k=0;k<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();k++)
                {
                    for(int l=0;l<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();l++)
                    {
                        if(game_board[k+z][l+row_total]==' ')
                            game_board[k+z][l+row_total]=vect[k][l];
                    }
                }
                this->Draw();
                break;
                // exit(0);

            }
            else
            {
                for(int k=0;k<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();k++)
                {
                    for(int l=0;l<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();l++)
                    {
                        if(game_board[k+z][l+row_total]==' ')
                            game_board[k+z][l+row_total]=vect[k][l];
                    }
                }
            }
            this->Draw();
            
            for(int k=0;k<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();k++)
            {
                for(int l=0;l<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();l++)
                {
                    game_board[k+z][l+row_total]=' ';
                }
            }  
            z++;
            if((z+Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x()-1)==stoi(first_part)-1)
            {
                //--z;
                for(int k=0;k<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();k++)
                {
                    for(int l=0;l<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();l++)
                    {
                        if(game_board[k+z][l+row_total]==' ')
                            game_board[k+z][l+row_total]=vect[k][l];
                    }
                }
                this->Draw();
                break;
                // ++z;
            }
            for(int m=0;m<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();m++)
            {
                char c=game_board[(z+Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x()-1)][m+row_total]+vect[Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x()-1][m]-' ';
                if(!(c==' '||c==vect[Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x()-1][m]||c==game_board[(z+Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x()-1)][m+row_total]))
                    exitt=true;
            }
            if(exitt)
            {
                cout<<"YAGAAAA"<<endl;
               // exit(0);
                --z;
                for(int k=0;k<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();k++)
                {
                    for(int l=0;l<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();l++)
                    {
                        if(game_board[k+z][l+row_total]==' ')
                            game_board[k+z][l+row_total]=vect[k][l];
                    }
                }
                break;
            }
            
        }
    }   

    void  operator+=(Tetro &obj1, Tetrominos&obj2 )/*add game board tp tetromios object*/
    {
        for( int i=0;i<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();i++)
        {
            for( int j=0;j<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();j++)
            {   
                if(obj1.game_board[i][j+(stoi(obj1.second_part)/2)]==' ')
                    obj1.game_board[i][j+(stoi(obj1.second_part)/2)]=Tetrominos:: all_shapes[Tetrominos::get_size_of_tetrominos() -1].get_shape()[i][j];
                else
                {
                    cerr<<"THERE IS NO SPACE FOR NEW TETROMINO.GAME HAS FINISHED"<<endl;
                    exit(1);
                }
            }
        }
        obj1.Draw();
        for( int i=0;i<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_x();i++)
        {
            for( int j=0;j<Tetrominos::all_shapes[Tetrominos::get_size_of_tetrominos()-1].get_y();j++)
            {   
                obj1.game_board[i][j+(stoi(obj1.second_part)/2)]=' ';
            }
        }
    }

    char * Tetro:: get_line(char *input)/*take input*/
    {
        char c;
        int counter=0;
        char *temp;

        while (cin.get(c)&&c!='\n') 
        {
            temp=new char[++counter];
            for(int i=0;i<counter-1;i++)
                temp[i]=input[i];
            temp[counter-1]=c;
            delete input;
            input=temp;
        }
        temp=new char[++counter];
            for(int i=0;i<counter-1;i++)
                temp[i]=input[i];
            temp[counter-1]='\0';
            delete input;
        return temp;
    }

    int Tetro:: str_len(const char *in)
    {
        if(in==nullptr||*in==0)
            return 0;
        return 1+str_len(in+1);
    }

    int Tetro:: find(const char *input,const char *p)const
    {
        if(str_len(input)>0&&str_len(p)==1)
        {
            int i=-1;
            while(input[++i]!=0)
            {
                if(input[i]==p[0])
                    return i-1;
            }

        }
        return -1;
    }

    char *Tetro:: substr(const int a ,const int b,const char *source)const
    {
        if(str_len(source)-1>=b)
        {
            char *temp=new char[b-a+2];
            for(int i=0;i<=b-a;i++)
            {
                temp[i]=source[a+i];
            }
            temp[b-a+1]='\0';
            return temp;
        }
        return nullptr;
    }

    bool Tetro:: char_cmpr(const char *in1,const char *in2) 
    {
        if(str_len(in1)==str_len(in2))
        {
            for(int i=0;i<str_len(in1);i++)
            {
                if(in2[i]!=in1[i])
                    return false;
            }
            return true;
        }
        return false;
    }

    bool Tetro:: is_number(const char * s)
    {
        if(str_len(s)==0)
            return false;
        int i=-1;
        while(s[++i]!=0)
        {
            if(isdigit(s[i]))
                return true;
        }
        return false;    
    }

    void  Tetro:: str_cpy(char * dest,const char * source)
    {
        for(int i=0;i<5;i++)
            dest[i]=source[i];
        dest[5]='\0';
    }

    Tetro::~Tetro()/* distructor for delete tetro object's pointer and Tetrominos objects' pointer. it wil free al memory that program haas been allocated*/
    {
        cout<<"****************\ndisructor of Tetro object has worked\n********************"<<endl;
        for(int i=0;i<stoi(first_part);i++)
            delete [] game_board[i];
        delete [] game_board;
        delete [] first_part;
        delete [] second_part;
        int a=Tetrominos::get_size_of_tetrominos();
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<Tetrominos::all_shapes[i].get_y();j++)
            {
                delete [] Tetrominos::all_shapes[i].get_shape()[j];
            }
            delete [] Tetrominos::all_shapes[i].get_shape();
        }
        delete [] Tetrominos:: all_shapes;

    }

}