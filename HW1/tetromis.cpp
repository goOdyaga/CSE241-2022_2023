/*HAMZA KONAÇ 210104004202 HW1*/
#include "tetrominos.h"

Tetrominos::Tetrominos():
shape_of_obj(shapes::I)/*constructor*/
{
    shape=to_represent_I();
}

Tetrominos::Tetrominos(shapes a):
shape_of_obj(a)
{/*decleare vector for enum type that user's input*/
    if(a==shapes::I)
        shape=to_represent_I();
    else if(a==shapes::O)
        shape=to_represent_O();
    else if(a==shapes::T)
        shape=to_represent_T();
    else if(a==shapes::J)
        shape=to_represent_J();
    else if(a==shapes::S)
        shape=to_represent_S();
    else if(a==shapes::Z)
        shape=to_represent_Z();
    else if(a==shapes::L)
        shape=to_represent_L();  
    result=to_represent_I();  
}
/*function of vector that are implement vector*/
shape_of_ Tetrominos::to_represent_I()
{
    vector<vector<char>> new_=
    {
        {'I',' ',' '},
        {'I',' ',' '},
        {'I',' ',' '}
    };
    return new_;
}

shape_of_ Tetrominos::to_represent_J()
{
    vector<vector<char>> new_=
    {
        {' ',' ','J'},
        {' ',' ','J'},
        {' ','J','J'}
    };
    return new_;
}

shape_of_ Tetrominos::to_represent_O()
{
    vector<vector<char>> new_=
    {
        {' ',' ',' '},
        {'O','O',' '},
        {'O','O',' '}
    };
    return new_;
}

shape_of_ Tetrominos::to_represent_T()
{
    vector<vector<char>> new_=
    {
        {' ',' ',' '},
        {'T','T','T'},
        {' ','T',' '}
    };
    return new_;
}

shape_of_ Tetrominos::to_represent_L()
{
    vector<vector<char>> new_=
    {
        {'L',' ',' '},
        {'L',' ',' '},
        {'L','L',' '}
    };
    return new_;
}

shape_of_ Tetrominos::to_represent_S()
{
    vector<vector<char>> new_=
    {
        {' ',' ',' '},
        {' ','S','S'},
        {'S','S',' '}
    };
    return new_;
}

shape_of_ Tetrominos::to_represent_Z()
{
    vector<vector<char>> new_=
    {
        {' ',' ',' '},
        {'Z','Z',' '},
        {' ','Z','Z'}
    };
    return new_;
}

void Tetrominos::print() const/*print tetrominos*/
{
    for(vector<char> a:get_shape())
    {
        for(auto x:a)
        {
            cout<<x;
        }
        cout<<endl;
    }
}

void Tetrominos::try_print(shape_of_ &other) const
{
    for(vector<char> a:other)
    {
        for(auto x:a)
        {
                cout<<x;
        }
        cout<<endl;
    }
}

void Tetrominos::rotate(int direction)
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

shape_of_ Tetrominos::resize_vector(shape_of_ &other)
{
    int count=0,i,j,control=-1;//       ---
    shape_of_ _new_vec;         //      OO-
    vector<char> temp;          //      OO-
    bool control_empty=false;   //  I delete right side of vector for canfit function control

    for(j=0;j<other.at(0).size();j++)
    {
        for(i=0;i<3;i++)
        {
            if(other.at(i).at(j)==' ')
                count++;/*counter count right side of vector. if it equal 3 I delete*/
        }
        if(count==3)
            break;
        count=0;
    }
    control=j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<other.at(0).size();j++)
        {
            if(j!=control)
                temp.push_back(other.at(i).at(j));/*recreate a vector*/
        }     
        _new_vec.push_back(temp);
        control_empty=false;
        temp.clear();
    }
    return _new_vec;
}

bool Tetrominos::canFit(Tetrominos & other)
{
    shape_of_ comp1;
    if(first_pattern_control)   //firstly I combine first 2 tetrominos . while I do that I try their 4 different position
        comp1=get_shape();      //and add them a vector.for interwine of tetrominos I use char ascıı value.
    else                        //if first tetro's right side and second tetro's left side's char values sum substract to ' ' 
        comp1=result_temp;      // be equal to letter or whitespace it cen be interwine
      
    shape_of_ comp2=other.get_shape();
    edit_vector(comp1);
    edit_vector(comp2);
    shape_of_ full_vec;
    vector<char> temp;
    

    bool for_break=true;
    int changee=0;
    int count1=0,count2=0;
    char control;
    comp1=resize_vector(comp1);
    comp2=resize_vector(comp2);
    for(auto i=0;i<3;i++)
    {
        control=comp1.at(i).at(comp1.at(0).size()-1)+comp2.at(i).at(0)-' ';/*I control interwine position . if it couldn't interwine for_break be false and it will return value of canFit function*/
        if(control!=comp1.at(i).at(comp1.at(0).size()-1)&&control!=comp2.at(i).at(0)&&control!=' ')
            for_break=false;
    }
    for(auto i=0;i<comp1.at(0).size()+comp2.at(0).size();i++)
        temp.push_back(' ');

    for(auto j=0;j<3;j++)
        full_vec.push_back(temp);
    for(auto j=0;j<3;j++)
    {
        for(auto i=0;i<comp1.at(0).size()+comp2.at(0).size();i++)
        {
            if(i<comp1.at(0).size())
                full_vec.at(j).at(i)=comp1.at(j).at(i);
            else if(for_break)/*if they can be interwine I interwine them eachother*/
            {
                if(comp2.at(j).at(i-comp1.at(0).size())!=' ')
                    full_vec.at(j).at(i-1)=comp2.at(j).at(i-comp1.at(0).size());
            }
            else
                full_vec.at(j).at(i)=comp2.at(j).at(i-comp1.at(0).size());
        }
    }
    result_temp=full_vec;
    result_temp=resize_vector(result_temp);
    if(other.shape_of_obj==shapes::L||other.shape_of_obj==shapes::J)
    {/*this condition for change L and J position for spesific condition*/
        if(result_temp.at(2).at(result.at(0).size()-2)==' '&&result_temp.at(1).at(result.at(0).size()-2)==' ')
        {
            for(int i=0;i<3;i++)
            {
                result_temp.at(i).at(result_temp.at(0).size()-2)=result_temp.at(i).at(result_temp.at(0).size()-1);
                if(i!=2)
                    result_temp.at(i).at(result_temp.at(0).size()-1)=' ';
            }
        }
    }
    return for_break;

    
}

void Tetrominos::edit_vector(shape_of_ &other)
{
    int i,j,count=0;//TTT           ---   Mission of this function is convert left side vector to right side
    shape_of_ temp;// -T- ===>      TTT
    for(i=0;i<3;i++)//---           -T-
    {//
        if(other.at(2).at(i)==' ')
            count++;
    }
    if(count==3)
    {
        temp.push_back(other.at(2));
        temp.push_back(other.at(0));
        temp.push_back(other.at(1));
        other.clear();
        other=temp;
    }
}

void Tetrominos::For_playing()
{
    int i,j,horiz=6;
    shape_of_ temp_for_res;
    Tetrominos::result=all_shapes.at(0).get_shape();
    Tetrominos::result_temp=all_shapes.at(0).get_shape();
    for(i=0;i<all_shapes.size()-1;i++)
    {
        shape_of_ result_for_remind=result;;
        for(j=0;j<4;j++)
        {
            if(i==0)
            {/*  at first step code will try 4 different rotate for each rotate of first object and save best fit of this result in result vector*/
                for(int k=0;k<4;k++)
                {
                   bool a= all_shapes.at(i).canFit(all_shapes.at(i+1));
                    if(k==0&&j==0)
                        result=result_temp;                
                   // result=resize_vector(result);
                    if(result.at(0).size()>=result_temp.at(0).size())/*if new rotate of object result's horizontal size is smaller than old result we change result vector*/
                        result=result_temp; 
                    all_shapes.at(i+1).rotate(1);
                }
                    all_shapes.at(i).rotate(1);
            }
            else
            {/*after 2 object we cover old pattern and just rotate new object and fit best fit for this tetromnos*/
                bool a=all_shapes.at(i).canFit(all_shapes.at(i+1));
                all_shapes.at(i+1).rotate(1);
                shape_of_ temp_for_loop=result_temp;
                if(j==0)
                    result=result_temp;
                result_temp=result_for_remind;
                if(result.at(0).size()>=temp_for_loop.at(0).size() )
                {
                    result=temp_for_loop;
                   // result=resize_vector(result);
                }   

            }
        }
       result_temp=result;
        Tetrominos::first_pattern_control=false;
    }
    cout<<"kontroll"<<endl;
    if(all_shapes.size()==1)
    {
        int horizontal=result.size();
        shape_of_ temp;
        for(int i=0;i<4;i++)
        {
            temp=Tetrominos:: all_shapes.at(0). get_shape();
            temp=Tetrominos:: all_shapes.at(0).resize_vector(temp);
            if(result.at(0).size()>=temp.size())
            {
                cout<<result.at(0).size()<<endl;
                result=temp;
            }
            Tetrominos:: all_shapes.at(0).rotate(1);
        }
        if(horizontal==result.at(0).size())
        {
            all_shapes.at(0).rotate(1);
            result=all_shapes.at(0).get_shape();
        }
        cout<<"HAMZA"<<endl;
    }
    Tetrominos:: all_shapes.at(0).for_edit_I();
    cout<<endl<<"FIT PATTERN OF TETROMINOS!!"<<endl<<endl;
    Tetrominos:: all_shapes.at(0).try_print(result);
}

void Tetrominos::for_edit_I()
{
    bool control=false;/*firstly we controlling result vector for it containing or not cont contain I tetrominos*/
    for(int i=0;i<result.at(0).size();i++)
        if(result.at(1).at(i)=='I')
            control=true;
    if(control)
    {/*we craeate 2D vector that row size is 4 and we add I cahr for I terominos Coulumn*/
        shape_of_ temp_of_res;
        vector<char> temp(result.at(0).size(),' ');
        temp_of_res.push_back(temp);
        for(int i=0;i<result.size();i++)
            temp_of_res.push_back(result.at(i));
        for(int i=0;i<result.at(0).size();i++)
            if(result.at(0).at(i)=='I')
                temp_of_res.at(0).at(i)='I';
        try_print(temp_of_res);
        result=temp_of_res;
    }
}

