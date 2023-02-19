#include "AbstractTetris.h"
#include "tetrominos.h"

namespace GTU
{   
    Abstracttetris::Abstracttetris()
    {/*gwr*/}

    Abstracttetris::~Abstracttetris()
    {/*gwr*/}

    bool Abstracttetris::control_file_name(const string &file_name)
    {
        int m=file_name.find(' ');
        if(!(m<file_name.size()&&m>=0))
        {
            string reverse_string=file_name;
            reverse(reverse_string.begin(),reverse_string.end());
            string txt=reverse_string.substr(0,4);
            if(txt=="txt.")
                return true;
            return false;

        }
        return false;
    }

    void Abstracttetris ::set_variables(int move_count1,int move_direct1,int direct_count1,int rotate_direct1)
    {
        move_count=move_count1;
        move_direct=move_direct1;
        direct_count=direct_count1;
        rotate_direct=rotate_direct1;

    }

    bool Abstracttetris ::input_controller(string input)
    {
        int first_x=input.find('x');/*control input for play game*/
        first_part=input.substr(0,first_x);
        second_part=input.substr(first_x+1,input.size()-first_x);
        if(is_number(first_part)&&is_number(second_part))
            return true;
        return false;
    }

    void Abstracttetris:: Play_game(shapes in)
    {
        
        Tetrominos temp(in);
        objec_of_tetrominos=temp;
        for(int i=0;i<direct_count;i++)
            temp.rotate(rotate_direct);
        vect=temp.get_shape();
        if(temp.get_shape_of_obj()==shapes::I)
            if(direct_count%2==0)
                    vect={{'I'},{'I'},{'I'}};
            else
                    vect={{'I','I','I'}};
        else if(temp.get_shape_of_obj()==shapes::O)
                    vect={{'O','O'},{'O','O'}};
        else
            vect=temp.resize_vector(vect);
        temp.set_shape(vect);
        x=vect.size();
        y=vect[0].size();
        *this+=temp;
    }
}