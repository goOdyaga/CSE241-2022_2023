#include "Tetro.h"
#include "tetrominos.h"
Tetro::Tetro():x(0),y(0),first_draw(false),first_step(false),cursor(0)
{
    game_board.resize(4,vector<char>(10,' '));/*initialize variable for object*/
}

Tetro::Tetro(string input):x(0),y(0),first_draw(false),first_step(false),cursor(0)
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
} 

bool Tetro::input_controller(string input)
{
    int first_x=input.find('x');/*control input for play game*/
    first_part=input.substr(0,first_x);
    second_part=input.substr(first_x+1,input.size()-first_x);
    if(is_number(first_part)&&is_number(second_part))
        return true;
    return false;
}

void Tetro::Draw()/*Draw game board. set cursor and colors for play game*/
{
    vector<string> colors={"\033[30m","\033[31m","\033[32m","\033[33m","\033[34m","\033[35m","\033[36m","\033[37m"};
    if(first_draw)
    {   
        int a=stoi(first_part)+2;
        int b=stoi(second_part)+2;
        cout<<"\33["<<to_string(a)<<"A"<<"\33["<<to_string(b)<<"D";/*at the first draw cursor dont backforward. after first step it can cursor backward delete game board redraw on it*/
        cursor++;
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

void Tetro::Add(Tetrominos &object)
{
    /*firstly I add vector the board and draw it and after drawing I return the situation of the board first step that dont contain new vector*/
    for( auto i=0;i<object.Tetrominos:: all_shapes.at(Tetrominos:: all_shapes.size()-1).get_shape().size();i++)
    {
        for( auto j=0;j<object.Tetrominos:: all_shapes.at(Tetrominos:: all_shapes.size()-1).get_shape().at(0).size();j++)
        {   
            if(game_board.at(i).at(j+(game_board.at(0).size()/2))==' ')
                game_board.at(i).at(j+(game_board.at(0).size()/2))=object.Tetrominos:: all_shapes.at(Tetrominos:: all_shapes.size()-1).get_shape().at(i).at(j);
            else
            {
                cerr<<"THERE IS NO SPACE FOR NEW TETROMINO.GAME HAS FINISHED"<<endl;
                exit(1);
            }
        }
    }
    this->Draw();
    for( auto i=0;i<object.Tetrominos:: all_shapes.at(Tetrominos:: all_shapes.size()-1).get_shape().size();i++)
    {
        for( auto j=0;j<object.Tetrominos:: all_shapes.at(Tetrominos:: all_shapes.size()-1).get_shape().at(0).size();j++)
        {   
            game_board.at(i).at(j+(game_board.at(0).size()/2))=' ';
        }
    }
}

void Tetro::Play_game()
{   
    /* for each  step I take tetromino and print top of the game board*/
    /* after that I wil fit the board and Draw it*/
        Add(Tetrominos:: all_shapes.at(Tetrominos:: all_shapes.size()-1));
        Fit();
}

void Tetro::Fit()
{
   /*I will find best fit regard to my algoritm . After that I animate the board andn draw last situation of the board*/ 
    bool pattern_control_side=true;
    char control;
    shape_of_ vect=Tetrominos:: all_shapes.at(Tetrominos:: all_shapes.size()-1).get_shape();
    shape_of_ temp_game_board;
    vector<shape_of_> container;
    vector<bool> bool_cont(2,true);
    
    for(int i=0;i<4;i++)
    {
        vect=Tetrominos:: all_shapes.at(Tetrominos:: all_shapes.size()-1).get_shape();
        if(Tetrominos:: all_shapes.at(Tetrominos:: all_shapes.size()-1).get_shape_of_obj()==shapes::I)
        {
            vect=Tetrominos::all_shapes.at(0).resize_vector(vect);
        }
        vect=Tetrominos::all_shapes.at(0).resize_vector(vect);
        if(vect.at(0).size()==1)
        {
            container.push_back(vect);
            break;
        }
        else if(vect.at(0).size()==2)
            container.push_back(vect);
        Tetrominos::all_shapes.at(Tetrominos:: all_shapes.size()-1).rotate(1);
        
    }

  
 
    if(x+container.at(0).at(0).size()>game_board.at(0).size())
    {
        y+=container.at(0).size();
        x=0;
        first_step=false;
    }
 /*game_board.size()-y-container.at(0).size()*/
    int tempo=game_board.size()-y;
    int tempo2=tempo-container.at(0).size();
    if(tempo2<0)
    {
        cerr<<"NO EMPTY SPAVE FOR NEW TETRO . GAME HAS FINISHED :))"<<endl;
        this->Draw();
        exit(0);
    }

    for(int i=0;i<container.size();i++)
    {
        for(int j=0;j<container.at(0).size();j++)
        {
            control=container.at(i).at(container.at(i).size()-1-j).at(0)+game_board.at(game_board.size()-y-1-j).at(x-first_step)-' ';
            if(control!=' '&&control!=container.at(i).at(container.at(i).size()-1-j).at(0)&&control!=game_board.at(game_board.size()-y-1-j).at(x-first_step))
            {
                bool_cont.at(i)=false;
            }
        }
            if(i==1)
                break;
    }
    if(Tetrominos:: all_shapes.at(Tetrominos:: all_shapes.size()-1).get_shape_of_obj()==shapes::I)
    {
        Animate(true,vect);
        for(int i=0;i<3;i++)
            game_board.at(game_board.size()-y-1-i).at(x)='I';
    }
    else if (bool_cont.at(0)==true&&bool_cont.at(1)==true)
    {
        if(Tetrominos::all_shapes.at(Tetrominos::all_shapes.size()-1).get_shape_of_obj()==shapes::L)
            container.at(1)=container.at(0);
        print_best_fit(container.at(1));
        Animate(true,container.at(1));
        for(int i=0;i<container.at(1).size();i++)
        {
            for(int j=0;j<container.at(1).at(0).size();j++)
            {
                if(j==0)
                {
                    if(game_board.at(game_board.size()-y-1-i).at(x+j-first_step)==' ')
                    {
                        game_board.at(game_board.size()-y-1-i).at(x+j-first_step)=container.at(1).at(container.at(1).size()-1-i).at(j);
                    }
                }
                else
                    game_board.at(game_board.size()-y-1-i).at(x+j-first_step)=container.at(1).at(container.at(0).size()-1-i).at(j);
            }
        } 
        if(first_step)
            x--;
    }
    else if(bool_cont.at(0)==true)
    {
        print_best_fit(container.at(0));
        Animate(true,container.at(0));
        for(int i=0;i<container.at(0).size();i++)
        {
            for(int j=0;j<container.at(0).at(0).size();j++)
            {
                if(j==0)
                {
                    if(game_board.at(game_board.size()-y-1-i).at(x+j-first_step)==' ')
                        game_board.at(game_board.size()-y-1-i).at(x+j-first_step)=container.at(0).at(container.at(0).size()-1-i).at(j);
                }
                else
                    game_board.at(game_board.size()-y-1-i).at(x+j-first_step)=container.at(0).at(container.at(0).size()-1-i).at(j);
            }
        } 
        x--;
    }
     
    else if(bool_cont.at(1)==true)
    {
        print_best_fit(container.at(1));
        Animate(true,container.at(1));
        for(int i=0;i<container.at(1).size();i++)
        {
            for(int j=0;j<container.at(1).at(0).size();j++)
            {
                if(j==0)
                {
                    if(game_board.at(game_board.size()-y-1-i).at(x+j-first_step)==' ')
                        game_board.at(game_board.size()-y-1-i).at(x+j-first_step)=container.at(1).at(container.at(1).size()-1-i).at(j);
                }
                else
                    game_board.at(game_board.size()-y-1-i).at(x+j-first_step)=container.at(1).at(container.at(1).size()-1-i).at(j);
            }
        } 
        x--;
    }
    else if (bool_cont.at(1)==false&&bool_cont.at(0)==false)
    {
        if(Tetrominos::all_shapes.at(Tetrominos::all_shapes.size()-1).get_shape_of_obj()==shapes::T||Tetrominos::all_shapes.at(Tetrominos::all_shapes.size()-1).get_shape_of_obj()==shapes::J)
            container.at(0)=container.at(1);
        print_best_fit(container.at(0));
        Animate(false,container.at(0));
        for(int i=0;i<container.at(0).size();i++)
        {
            for(int j=0;j<container.at(0).at(0).size();j++)
            {
                game_board.at(game_board.size()-y-1-i).at(x+j)=container.at(0).at(container.at(0).size()-1-i).at(j);
            }
        } 
    }
    if(x+vect.at(0).size()<=game_board.at(0).size())
    {
        x+=container.at(0).at(0).size();
        first_step=true;
    }
    else if(game_board.size()-y-vect.size()>=0)
    {
        y+=container.at(0).size();
        x=0;
        first_step=false;
    }
    else
    {
        cerr<<"NO EMPTY SPAVE FOR NEW TETRO . GAME HAS FINISHED :))"<<endl;
    }

   this->Draw();

}

void Tetro::print_best_fit(shape_of_ &vect)
{
    /* I print the best f,t of the tetromino top of the game_board*/
    for( auto i=0;i<vect.size();i++)
    {
        for( auto j=0;j<vect.at(0).size();j++)
        {   
            if(game_board.at(i).at(j+(game_board.at(0).size()/2))==' ')
                game_board.at(i).at(j+(game_board.at(0).size()/2))=vect.at(i).at(j);
            else
            {
                cerr<<"THERE IS NO SPACE FOR NEW TETROMINO.GAME HAS FINISHED"<<endl;
                exit(1);
            }
        }
    }
    this->Draw();
   for( auto i=0;i<vect.size();i++)
    {
        for( auto j=0;j<vect.at(0).size();j++)
        {   
                game_board.at(i).at(j+(game_board.at(0).size()/2))=' ';
        }
    }
}

void Tetro::Animate(bool intertwine,shape_of_ &vect)
{
    /*this function animate all tetromino.Fit function call it for every step before draw best fit of the board*/   
    int i=0,j=game_board.at(0).size()/2,z=0;

       if(x>(game_board.at(0).size()/2))
        {
            while(j+i<=x)
            {
                  
                for(int k=0;k<vect.size();k++)
                {
                    for(int l=0;l<vect.at(0).size();l++)
                    {
                        game_board.at(k+z).at(l+(game_board.at(0).size()/2)+i)=vect.at(k).at(l);
                    }
                }
                this->Draw();
                for(int k=0;k<vect.size();k++)
                {
                    for(int l=0;l<vect.at(0).size();l++)
                    {
                        game_board.at(k+z).at(l+(game_board.at(0).size()/2)+i)=' ';
                    }
                } 
                i++;
            }
            --i;
            while(game_board.size()-z-vect.size()>y)
            {
                for(int k=0;k<vect.size();k++)
                {
                    for(int l=0;l<vect.at(0).size();l++)
                    {
                        game_board.at(k+z).at(l+(game_board.at(0).size()/2)+i)=vect.at(k).at(l);
                    }
                }
                this->Draw();
             
                for(int k=0;k<vect.size();k++)
                {
                    for(int l=0;l<vect.at(0).size();l++)
                    {
                        game_board.at(k+z).at(l+(game_board.at(0).size()/2)+i)=' ';
                    }
                }  
                z++;
            }

        }
        else
        {
            while(j-i>=x)
            {
                  
                for(int k=0;k<vect.size();k++)
                {
                    for(int l=0;l<vect.at(0).size();l++)
                    {
                        game_board.at(k+z).at(l+(game_board.at(0).size()/2)-i)=vect.at(k).at(l);
                    }
                }
                this->Draw();
                for(int k=0;k<vect.size();k++)
                {
                    for(int l=0;l<vect.at(0).size();l++)
                    {
                        game_board.at(k+z).at(l+(game_board.at(0).size()/2)-i)=' ';
                    }
                } 
                i++;
            }
            --i;
            while(game_board.size()-z-vect.size()>y)
            {
                for(int k=0;k<vect.size();k++)
                {
                    for(int l=0;l<vect.at(0).size();l++)
                    {
                        game_board.at(k+z).at(l+(game_board.at(0).size()/2)-i)=vect.at(k).at(l);
                    }
                }
                this->Draw();
             
                for(int k=0;k<vect.size();k++)
                {
                    for(int l=0;l<vect.at(0).size();l++)
                    {
                        game_board.at(k+z).at(l+(game_board.at(0).size()/2)-i)=' ';
                    }
                }  
                z++;
            }

        } 
    // }
    
}