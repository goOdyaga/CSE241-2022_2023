#include    "TetrisVector.h"
#include    "AbstractTetris.h"
#include    "TetrisArray1D.h"
#include    "TetrisAdapter.h"
#include    "TetrisAdapter.cpp"

using namespace GTU;
int main()
{
    string temp;
    Abstracttetris*temp_obj;
    bool control=true;
    vector< Abstracttetris*> vector_abs_obj;
    vector_abs_obj.push_back(new TetrisVector("20x20"));
    vector_abs_obj.push_back(new Tetris1DArray("20x20"));/*append all class type to a vector*/
    vector_abs_obj.push_back(new TetrisAdapter<vector<char>>("20x20"));
    vector_abs_obj.push_back(new TetrisAdapter<deque<char>>("20x20"));
    vector_abs_obj.push_back(new TetrisAdapter<list<char>>("20x20"));
    fstream file("output1.txt",ios::out);
    fstream file1("read.txt",ios::in);
    int i=0;
    while (i<5)
    {
       temp_obj=vector_abs_obj.at(i);/*assign temp_object pointer to differnet type class objects*/
        if(i==0)
            file<<"vector class been tested"<<endl;
        else if(i==1)
            file<<"1-D array class been tested"<<endl;
        else if(i==3)
            file<<"adapter class(vector) class been tested"<<endl;
        else if(i==2)/*in this conditions game board created by file that contain game board*/
        {
            file<<"adapter class(deque) class been tested"<<endl;
            cout<<"\n\n"<<"\033[32m"<<"PLEASE WAIT!!!\n\n "<<"\033[0m"<<endl;
             std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            file<<"\n\nthis game board created by file that contain game board\n\n "<<endl;
            cout<<"\n\n"<<"\033[32m"<<"this game board created by read.txt that contain game board\n\n "<<"\033[0m"<<endl;
             std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            temp_obj->readFromFile(file1);
            temp_obj->draw();
            cout<<"After control game board and read.txt press enter"<<endl;
            getline(cin,temp);

        }
        else if(i==4)
            file<<"adapter class(list) class been tested"<<endl;
         for(int j=0;j<15;j++)
         {

                        string tetromino_last(temp);
                        vector<shapes> shapes_enum={shapes::I,shapes::J,shapes::L,shapes::O,shapes::S,shapes::T,shapes::Z};/* shapes vector contain shapes enum and take random shapes for create tetrominos*/
                        shapes a=shapes_enum.at(rand()%shapes_enum.size());
                        if(a==shapes::I)
                            tetromino_last="I";
                        else if(a==shapes::J)
                            tetromino_last="J";
                        else if(a==shapes::L)
                            tetromino_last="L";
                        else if(a==shapes::O)
                            tetromino_last="O";
                        else if(a==shapes::S)
                            tetromino_last="S";
                        else if(a==shapes::T)
                            tetromino_last="T";
                        else if(a==shapes::Z)
                            tetromino_last="Z";
                        temp_obj->set_variables(rand()%10+1,rand()%2+1,rand()%4,rand()%2+1);
                        temp_obj->Play_game(a);
                        temp_obj->animate();
                        cout<<temp_obj->lastMove(tetromino_last);
                        file<<temp_obj->lastMove(tetromino_last);
                        cout<<"\nTotal move number of Game is "<<temp_obj->numberOfMoves()<<endl;
                        file<<"\nTotal move number of Game is "<<temp_obj->numberOfMoves()<<endl;
         }
         temp_obj->writeToFile(file);
         i++;
    }
    file.close();
    file1.close();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout<<"\033[32m"<<"driver1 HAS been Finish. Results are in output.1 txt . you can look there "<<"\033[0m"<<endl;          
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
    
    