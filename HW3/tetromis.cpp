/*HAMZA KONAÇ 210104004202 HW1*/
#include "tetrominos.h"
#include "Tetro.h"

Tetrominos::Tetrominos():shape_of_obj(shapes::I),x(3),y(3)
{
    shape=to_represent_I();
}

Tetrominos::Tetrominos(shapes a):shape_of_obj(a),x(3),y(3)
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
    {
        shape=to_represent_L();  
        //cout<<"CRASSSSSHHH"<<endl;
    }
}
/*represent tetrominos*/
shape_of_ Tetrominos::to_represent_I()
{

    char ** new_=new char*[3];
    for(int i=0;i<3;i++)
        new_[i]=new char[3];
    new_[0][0]='I';
    new_[0][1]=' ';
    new_[0][2]=' ';
    new_[1][0]='I';
    new_[1][1]=' ';
    new_[1][2]=' ';
    new_[2][0]='I';
    new_[2][1]=' ';
    new_[2][2]=' ';
    return new_;
}

shape_of_ Tetrominos::to_represent_J()
{

    char ** new_=new char*[3];
    for(int i=0;i<3;i++)
        new_[i]=new char[3];
    new_[0][0]=' ';
    new_[0][1]=' ';
    new_[0][2]='J';
    new_[1][0]=' ';
    new_[1][1]=' ';
    new_[1][2]='J';
    new_[2][0]=' ';
    new_[2][1]='J';
    new_[2][2]='J';
    return new_;
}

shape_of_ Tetrominos::to_represent_O()
{

    char ** new_=new char*[3];
    for(int i=0;i<3;i++)
        new_[i]=new char[3];
    new_[0][0]=' ';
    new_[0][1]=' ';
    new_[0][2]=' ';
    new_[1][0]='O';
    new_[1][1]='O';
    new_[1][2]=' ';
    new_[2][0]='O';
    new_[2][1]='O';
    new_[2][2]=' ';
    return new_;
}

shape_of_ Tetrominos::to_represent_T()
{

    char ** new_=new char*[3];
    for(int i=0;i<3;i++)
        new_[i]=new char[3];
    new_[0][0]=' ';
    new_[0][1]=' ';
    new_[0][2]=' ';
    new_[1][0]='T';
    new_[1][1]='T';
    new_[1][2]='T';
    new_[2][0]=' ';
    new_[2][1]='T';
    new_[2][2]=' ';
    return new_;
}

shape_of_ Tetrominos::to_represent_L()
{

    char ** new_=new char*[3];
    for(int i=0;i<3;i++)
        new_[i]=new char[3];
    new_[0][0]='L';
    new_[0][1]=' ';
    new_[0][2]=' ';
    new_[1][0]='L';
    new_[1][1]=' ';
    new_[1][2]=' ';
    new_[2][0]='L';
    new_[2][1]='L';
    new_[2][2]=' ';
    return new_;
}

shape_of_ Tetrominos::to_represent_S()
{

    char ** new_=new char*[3];
    for(int i=0;i<3;i++)
        new_[i]=new char[3];
    new_[0][0]=' ';
    new_[0][1]=' ';
    new_[0][2]=' ';
    new_[1][0]=' ';
    new_[1][1]='S';
    new_[1][2]='S';
    new_[2][0]='S';
    new_[2][1]='S';
    new_[2][2]=' ';
    return new_;
}

shape_of_ Tetrominos::to_represent_Z()
{

    char ** new_=new char*[3];
    for(int i=0;i<3;i++)
        new_[i]=new char[3];
    new_[0][0]=' ';
    new_[0][1]=' ';
    new_[0][2]=' ';
    new_[1][0]='Z';
    new_[1][1]='Z';
    new_[1][2]=' ';
    new_[2][0]=' ';
    new_[2][1]='Z';
    new_[2][2]='Z';
   
    return new_;
}


/*rotate the tetrominos*/
void Tetrominos::rotate(int direction)
{
    if(shape_of_obj==shapes::O/*||shape_of_obj==shapes::I*/)
    {/*O has 1 rotate*/
        shape_of_ temp=new char*[2];
        for(int i=0;i<2;i++)
            temp[i]=new char[2];
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                temp[i][j]='O';
        for(int i=0;i<3;i++)
            delete [] shape[i];
        delete []shape;
        shape=temp;
        x=2;
        y=2;
        return;
    }
    shape_of_ temp=new char*[3];
    for(int i=0;i<3;i++)
        temp[i]=new char[3];
    //shape_of_ temp=get_shape();
    if(1==direction)
    {
        temp[0][0]=shape[2][0];//   - - -
        temp[0][1]=shape[1][0];//   - - - 
        temp[0][2]=shape[0][0];//   - - -
        temp[1][0]=shape[2][1];//I think all shapes are cube 
        temp[1][1]=shape[1][1];// so that I return cube 
        temp[1][2]=shape[0][1];//
        temp[2][0]=shape[2][2];//
        temp[2][1]=shape[1][2];//
        temp[2][2]=shape[0][2];//
    }    

    else if(2==direction)
    {
        temp[0][0]=shape[0][2];
        temp[0][1]=shape[1][2];
        temp[0][2]=shape[2][2];
        temp[1][0]=shape[0][1];
        temp[1][1]=shape[1][1];
        temp[1][2]=shape[2][1];
        temp[2][0]=shape[0][0];
        temp[2][1]=shape[1][0];
        temp[2][2]=shape[2][0];
    }
    delete [] shape;
    shape=temp;
}

void Tetrominos::set_shape(const Tetrominos &obj)
{
        Tetrominos *temp=new Tetrominos[size_of_tetrominos+1];
        for(int i=0;i<size_of_tetrominos;i++)
            temp[i]=all_shapes[i];
        temp[size_of_tetrominos]=obj;
        delete[] all_shapes;
        all_shapes =temp;
        ++size_of_tetrominos; 
    
}

shape_of_ Tetrominos::resize_vector(shape_of_ other)/*delete more space and resize array for animate*/
{
    cout<<endl<<"---"<<endl;
    // Tetro::print(other);
    int count=0,counter1=0,i,j,control=-1;//       ---
    shape_of_ _new_vec;         //      OO-
                                //      OO-
    bool control_empty=false,row=false;   //  I delete right side of vector for canfit function control
    for(int i=0;i<3;i++)
    {
        if((other[2][i]==' '))
            count++;
        if((other[0][i]==' '))
            counter1++;
    }
    if(count==3)
    {
        _new_vec=new char*[2];
        row=true;
    }
    else
        _new_vec=new char*[3];
    count=0;
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            if(other[i][j]==' ')
                count++;/*counter count right side of vector. if it equal 3 I delete*/
        }
        if(count==3)
        {
            control_empty=true;
            break;
        }
        count=0;
    }
    control=j;
    for(int i=0;i<3-row;i++)
        _new_vec[i]=new char[3-control_empty];
    int counter=-1;
    if(control_empty)
    {
        --y;
        for(i=0;i<3-row;i++)
        {
            counter=-1;
            for(j=0;j<3;j++)
            {
                if(j!=control)
                    _new_vec[i][++counter]=other[i][j];/*recreate a vector*/
            }     
        }
        delete [] other;
        return _new_vec;
    }
    else
    {
        if(3!=counter1)
            --x;
        for(i=0;i<3-row;i++)
        {
            for(j=0;j<3;j++)
            {
                _new_vec[i][j]=other[i][j];/*recreate a vector*/
            }     
        }
       delete [] other;
    }
    return _new_vec;
}

void Tetrominos:: set_shape(shape_of_ vect)
{
    delete [] shape;
    shape=vect;
}     







