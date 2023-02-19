/*HAMZA KONAÇ 210104004202 HW1*/
#include "tetrominos.h"

Tetrominos:: Tetrominos()/*DEFAULT constructor*/
{}

Tetrominos:: Tetrominos(shapes in)/*constructor THAT TAKE TETROMINOS ENUM TYPE*/
{
    if(in==shapes::I)
    {
        shape=to_represent_I();
        shape_of_obj=shapes::I;

    }
    else if(in==shapes::J)
    {
        shape=to_represent_J();
        shape_of_obj=shapes::J;
    }
    else if(in==shapes::L)
    {
        shape=to_represent_L();
        shape_of_obj=shapes::L;
    }
    else if(in==shapes::O)
    {
        shape=to_represent_O();
        shape_of_obj=shapes::O;
    }
    else if(in==shapes::S)
    {
        shape=to_represent_S();
        shape_of_obj=shapes::S;
    }
    else if(in==shapes::T)
    {
        shape=to_represent_T();
        shape_of_obj=shapes::T;
    }
    else if(in==shapes::Z)
    {
        shape=to_represent_Z();
        shape_of_obj=shapes::Z;
    }
    
}

/*function of vector that are implement vector*/
shape_of_ Tetrominos:: to_represent_I()
{ 
    shape_of_obj=shapes::I;
    vector<vector<char>> new_=
    {
        {'I',' ',' '},
        {'I',' ',' '},
        {'I',' ',' '}
    };
    return new_;
}

shape_of_ Tetrominos:: to_represent_J()
{
    shape_of_obj=shapes::J;
    vector<vector<char>> new_=
    {
        {' ',' ','J'},
        {' ',' ','J'},
        {' ','J','J'}
    };
    return new_;
}

shape_of_ Tetrominos:: to_represent_O()
{
    shape_of_obj=shapes::O;
    vector<vector<char>> new_=
    {
        {' ',' ',' '},
        {'O','O',' '},
        {'O','O',' '}
    };
    return new_;
}

shape_of_ Tetrominos:: to_represent_T()
{
    shape_of_obj=shapes::T;
    vector<vector<char>> new_=
    {
        {' ',' ',' '},
        {'T','T','T'},
        {' ','T',' '}
    };
    return new_;
}

shape_of_ Tetrominos:: to_represent_L()
{
    shape_of_obj=shapes::L;
    vector<vector<char>> new_=
    {
        {'L',' ',' '},
        {'L',' ',' '},
        {'L','L',' '}
    };
    return new_;
}

shape_of_ Tetrominos:: to_represent_S()
{
    shape_of_obj=shapes::S;
    vector<vector<char>> new_=
    {
        {' ',' ',' '},
        {' ','S','S'},
        {'S','S',' '}
    };
    return new_;
}

shape_of_ Tetrominos:: to_represent_Z()
{
    shape_of_obj=shapes::Z;
    vector<vector<char>> new_=
    {
        {' ',' ',' '},
        {'Z','Z',' '},
        {' ','Z','Z'}
    };
    return new_;
}

void Tetrominos:: rotate(int direction)
{
    shape_of_ temp=get_shape();
    if(shape_of_obj==shapes::O||shape_of_obj==shapes::I)
        return;
    if(1==direction)
    {
        shape.at(0).at(0)=temp.at(2).at(0);//   - - -
        shape.at(0).at(1)=temp.at(1).at(0);//   - - - 
        shape.at(0).at(2)=temp.at(0).at(0);//   - - -
        shape.at(1).at(0)=temp.at(2).at(1);//I think all shapes are cube 
        shape.at(1).at(1)=temp.at(1).at(1);// so that I return cube 
        shape.at(1).at(2)=temp.at(0).at(1);//
        shape.at(2).at(0)=temp.at(2).at(2);//
        shape.at(2).at(1)=temp.at(1).at(2);//
        shape.at(2).at(2)=temp.at(0).at(2);//
    }    

    else if(2==direction)
    {
        shape.at(0).at(0)=temp.at(0).at(2);
        shape.at(0).at(1)=temp.at(1).at(2);
        shape.at(0).at(2)=temp.at(2).at(2);
        shape.at(1).at(0)=temp.at(0).at(1);
        shape.at(1).at(1)=temp.at(1).at(1);
        shape.at(1).at(2)=temp.at(2).at(1);
        shape.at(2).at(0)=temp.at(0).at(0);
        shape.at(2).at(1)=temp.at(1).at(0);
        shape.at(2).at(2)=temp.at(2).at(0);
    }
}

shape_of_ Tetrominos:: resize_vector(shape_of_ &other)
{
    int counter1=0,counter2=0;
    
    int x=other.size(),y=other[0].size();
    for(int i=0;i<other.size();i++)
    {
        counter1+=other[i][0];
        counter2+=other[i][other.at(0).size()-1];
    }
    if(counter1/32==other.size())
    {
        for(int i=0;i<x;i++)
            other[i].erase(other[i].begin());

    }
    else if(counter2/32==other.size())
    {
    
        for(int i=0;i<x;i++)
            other[i].pop_back();

    }

    else
    {
        counter2=0;
        for(int i=0;i<y;i++)
        {
           
            counter2+=other[other.at(0).size()-1][i];
        }
        if(counter2/32==other[0].size())
            other.erase(other.end()-1);
    }
    return other;
}

Tetrominos Tetrominos::operator=(const Tetrominos &rside)
{
    shape=rside.get_shape();
    // shape.resize(rside.get_shape().size(),vector<char>(rside.get_shape().at(0).size()));
    // for(int i=0;i<rside.get_shape().size();i++)
    // {
    //     for(int j=0;j<rside.get_shape().at(0).size();j++)
    //         shape.at(i).at(j)=rside.get_shape().at(i).at(j);
    // }
    shape_of_obj=rside.shape_of_obj;
    return *this;    
}   
