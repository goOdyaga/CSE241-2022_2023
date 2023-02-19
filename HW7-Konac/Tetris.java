import java.util.ArrayList;
import java.util.Random;
import java.io.File;  // Import the File class
import java.io.PrintWriter;

/**
 * @author Hamza KONAÇ
 */
public class Tetris 
{
    private Tetrominos objec_of_tetrominos;/*type of tetromino objects*/
    private int x,y;/*row and column of tetromino objects*/
    private ArrayList<ArrayList<Character>>vect;/*contain of tetromino object*/
    private String first_part,second_part;/*first and second part use for create game board. first part is row and second part is column*/
    private int move_count,move_direct,direct_count,rotate_direct;/*move and rotate data's*/
    private ArrayList<ArrayList<Character >>game_board;
    private int total_move;
    private boolean first_draw;


    /**
     * Default contructor
     */
    public Tetris()
    {
        
    }
    
    /**
     * Constructor that take board row and colum. With this valu it will create game board and draw it the screen
     * @param input
     */
    public Tetris(String input)
    {
        game_board =new ArrayList<ArrayList<Character> >();
        while(true)
        {

            if(input_controller(input))/*taking string for gameboard size*/
            {
                for(int i=0;i<Integer.parseInt(second_part);i++)
                {
                    ArrayList<Character>  temp = new ArrayList<>();
                    for(int j=0;j<Integer.parseInt(first_part);j++)
                        temp.add(' ');
                    
                    game_board.add(temp);
                }
                
                // for(int j=)
                //game_board.resize(Integer.parseInt(first_part),vector<char>(Integer.parseInt(second_part),' '));
                break;
            }

            else
            {
                System.out.print("Invalid game board size . Try again please!!\n");
                return;
                // cerr<<"Invalid game board size . Try again please!!"<<endl;
            }
        }
        this.draw();
    }

    /**
     * take Tetrominos object and add it to tetris board after that animate it
     * @param in
     */
    public void Play_game(shapes in)
    {
        ArrayList<ArrayList<Character>>new_ = new ArrayList<>();
        Tetrominos temp=new Tetrominos(in);
        // System.out.print("\n*******************************\n");
        // print(temp.get_shape());
        // System.out.print("\n*******************************\n");
        objec_of_tetrominos=temp;
        for(int i=0;i<direct_count;i++)
            temp.rotate(rotate_direct);
        vect=deepCopy(temp.get_shape());
        // print(vect);
        // System.out.print("\n*******************************\n");
        if(temp.get_shape_of_obj()==shapes.I)
        {

            if(direct_count%2==0)
            {
                ArrayList<Character> innerList = new ArrayList<>();
                ArrayList<Character> innerList1 = new ArrayList<>();
                ArrayList<Character> innerList2 = new ArrayList<>();
                innerList.add('I');
                innerList1.add('I');
                innerList2.add('I');
                new_.add(innerList);
                new_.add(innerList1);
                new_.add(innerList2);
                vect.clear();
                vect=deepCopy(new_);
            }
            else
            {
                ArrayList<Character> innerList = new ArrayList<>();
                innerList.add('I');
                innerList.add('I');
                innerList.add('I');
                new_.add(innerList);
                vect.clear();
                vect=deepCopy(new_);   
            }
        }
                    // vect={{'I','I','I'}};
        else if(temp.get_shape_of_obj()==shapes.O)
        {
            ArrayList<Character> innerList = new ArrayList<>();
                ArrayList<Character> innerList1 = new ArrayList<>();
                innerList.add('O');
                innerList.add('O');
                innerList1.add('O');
                innerList1.add('O');
                new_.add(innerList);
                new_.add(innerList1);
                vect.clear();
                vect=deepCopy(new_);   
        }
                    // vect={{'O','O'},{'O','O'}};
        else
            vect=deepCopy(temp.resize_ArrayList(vect));
        // System.out.print("ppppppppppppppppppppppppppppppppppppppppppppppppp");
        // print(vect);
        // System.out.print("ppppppppppppppppppppppppppppppppppppppppppppppppp");
        temp.set_shape(vect);
        x=vect.size();
        y=vect.get(0).size();
        this.add(temp);
    }

    /**
     * control file name obey .txt formats
     * @return
     */
    public boolean control_file_name( String file_name) 
    {
        int m=file_name.indexOf(' ');
        if(!(m<file_name.length()&&m>=0))
        {
            String reverse_String="";
            Character ch;
            for (int i=0; i<file_name.length(); i++)
            {
                ch= file_name.charAt(i); //extracts each character
                reverse_String= ch+reverse_String; //adds each character in front of the existing String
            }
            String txt=reverse_String.substring(0,4);
            if(txt=="txt.")
                return true;
            return false;
        }
        return false;
    }

    /**
     * control parameter contain number or not . if  parameter contain number funciton will return true
     * @return
     */
    public static boolean is_number( String s) 
    {
        try
        {
            int a=Integer.parseInt(s);
            return true;
        }
        catch(NumberFormatException e)
        {
            System.out.println("Invalid board size");
            return false;
        }
        // return s.matches(".*[0-9].*")==true;
    };

    /**
     * set variables for movea and rotate
     * @param move_count1
     * @param move_direct1
     * @param direct_count1
     * @param rotate_direct1
     */
    public void set_variables(int move_count1,int move_direct1,int direct_count1,int rotate_direct1)
    {
        move_count=move_count1;
        move_direct=move_direct1;
        direct_count=direct_count1;
        rotate_direct=rotate_direct1;
    }
    
    /**
     * control input for create board.if input not like this sample "sizexsize" funciton will return false
     * @param input
     * @return
     */
    public boolean 
    input_controller(String input)
    {
        int first_x=input.indexOf("x");/*control input for play game*/
        
        first_part=input.substring(0,first_x);
        second_part=input.substring(first_x+1,input.length());
        // System.out.print(first_part+" -- "+second_part);
        return is_number(first_part)&&is_number(second_part) ;
        // if()
        //     return true;
        // return false;
    }

    /**
     * return  tetromino objct type
     * @return
     */
    public  Tetrominos get_objec_of_tetrominos(){return objec_of_tetrominos;};

    /**
     * return size of shape's column
     * @return
     */
    public  int get_x() {return x;};

    /**
     * return size of shape's row
     * @return
     */
    public  int get_y() {return y;};    

    /**
     * draw the Tetris board
     */
    public void draw() 
    {
        ArrayList<String> colors=new ArrayList<>();
        colors.add("\033[38;2;255;0;0m");
        colors.add("\033[38;2;0;255;0m");
        colors.add("\033[38;2;0;0;255m");
        colors.add("\033[38;2;0;255;255m");
        colors.add("\033[38;2;255;0;255m");
        colors.add("\033[38;2;255;255;0m");
        colors.add("\033[38;2;255;130;0m");
        colors.add("\033[38;2;0;130;255m");
        // {"\033[30m","\033[31m","\033[32m","\033[33m","\033[34m","\033[35m","\033[36m","\033[37m"};
        if(first_draw)
        {   
            int a=Integer.parseInt(first_part)+5;
            int b=Integer.parseInt(second_part)+5;
            System.out.printf("\33[%sA\33[%sD",Integer.toString(a),Integer.toString(b));
            // System.out.printf( "\3)3["<<Integer.toString(a)<<"A"<<"\33["<<Integer.toString(a)<<"D";/*at the first draw cursor dont backforward. after first step it can cursor backward delete game board redraw on it*/
        }
        try {
            Thread.sleep(50);
        } catch (InterruptedException e) {
            // Handle exception
        }
        first_draw=true;
        Random rand = new Random();
        for(var i=0;i<game_board.size()+2;i++ )
        {
            for(var j=0;j<game_board.get(0).size()+2;j++ )
            {
                // System.out.printf( i<<)" "<<j<<endl;
                if(i==0)
                    System.out.printf( "X ");
                else if(j==0)
                    System.out.printf( "X ");
                else if(i==game_board.size()+1)
                    System.out.printf( "X ");
                else if(j==game_board.get(0).size()+1)
                    System.out.printf( "X ");
                // else if(game_board.get(i-1).get(j-1)==' ') 
                //     System.out.print("-");
                else
                {
                    if(game_board.get(i-1).get(j-1) == ' ')
                    System.out.print("  ");
                    else
                        System.out.printf( "%s%c %s",colors.get(rand.nextInt(colors.size())),game_board.get(i-1).get(j-1),"\033[0m");
                    // cout<<colors.at(rand()%colors.size())<<game_board.at(i-1).at(j-1)<< "\033[0m";

                }
            }
            System.out.printf("\n");
        }

    }
    
    /**
     * This funciton add Tetrominos object to top of the game board
     * @param obj1
     */
    public void  add( Tetrominos obj1 )
    {
        // print(obj1.get_shape());
        // System.out.print("-----------------------------------------------------");
        // System.out.print("--> "+obj1.get_shape().size()+"\n");
        // System.out.print("--> "+obj1.get_shape().get(0).size()+"\n");
        
        this.draw();
        // System.out.print("000000000000000000000000000000000000000000000000000000000");
        for( int i=0;i<obj1.get_shape().size();i++)
        {
            for( int j=0;j<obj1.get_shape().get(0).size();j++)
            {    
                // System.out.print("\nhhhhh "+i+" "+j+" " +(int)((game_board.get(0).size())/2)+" hhhh\n");
                if(game_board.get(i).get(j+((game_board.get(0).size())/2))==' ')
                    game_board.get(i).set(j+((game_board.get(0).size())/2),obj1.get_shape().get(i).get(j));
                else
                {
                    System.out.printf("THERE IS NO SPACE FOR NEW TETROMINO.GAME HAS FINISHED\n");
                    // cerr<<"THERE IS NO SPACE FOR NEW TETROMINO.GAME HAS fileISHED"<<endl;
                    // Öreturn;
                    System.exit(1);
                }
            }
        }
        
        this.draw();
        // System.out.print("111111111111111111111111111111111111111111111111111111");
        for( var i=0;i<obj1.get_shape().size();i++)
        {
            for( var j=0;j<obj1.get_shape().get(0).size();j++)
            {   
                game_board.get(i).set(j+(game_board.get(0).size()/2),' ');
            }
        }
        // System.out.print("22222222222222222222222222222222222222222222222222222222222222222222");

        this.draw();
    }

    /**
     * this function add Tetrominos and place it to by move direction and count. while doing it animate it step by step
     */
    public void animate()
    {
        int i=0,j=Integer.parseInt(second_part)/2,z=0,row_total=0;
        boolean exitt=false,eqit2=false;
        
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
                            if(game_board.get(k+z).get(l+(Integer.parseInt(second_part)/2)-i)==' ')
                                game_board.get(k+z).set(l+(Integer.parseInt(second_part)/2)-i,vect.get(k).get(l));
                        }
                    }
                    this.draw();
                    for(int k=0;k<get_x();k++)
                    {
                        for(int l=0;l<get_y();l++)
                        {
                            game_board.get(k+z).set(l+(Integer.parseInt(second_part)/2)-i,' ');
                        }
                    } 
                    i++;
                    exitt=false;
                    for(int m=0;m<get_x();m++)
                    {
                        int c=game_board.get(m+z).get((Integer.parseInt(second_part)/2)-i)+vect.get(m).get(0)-' ';
                        if(!(c==' '||c==vect.get(m).get(0)||c==game_board.get(m+z).get((Integer.parseInt(second_part)/2)-i)))
                            exitt=true;
                    }
                    if(exitt)
                    {
                            --i;   
                        for(int k=0;k<get_x();k++)
                        {
                            for(int l=0;l<get_y();l++)
                            {
                                if(game_board.get(k+z).get(l+(Integer.parseInt(second_part)/2)-i)==' ')
                                    game_board.get(k+z).set(l+(Integer.parseInt(second_part)/2)-i,vect.get(k).get(l));
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
                                if(game_board.get(k+z).get(l+(Integer.parseInt(second_part)/2)-i)==' ')
                                    game_board.get(k+z).set(l+(Integer.parseInt(second_part)/2)-i,vect.get(k).get(l));
                            }
                        } 
                        i++;
                    }
                }
                if(i!=0)
                    --i;
                exitt=false;
                row_total=(Integer.parseInt(second_part)/2)-i;
            }
            else
            {
                System.out.print("The specified number of spaces does not exist in the specified direction\n");
                // cout<<"The specified number of spaces does not exist in the specified direction"<<endl;
                move_direct=0;
                return;
            }
            

        }
        if(move_direct==2)
        {
            if(j+move_count+get_y()-1<(Integer.parseInt(second_part)))
            {
                while(i<=move_count)
                {
                    for(int k=0;k<get_x();k++)
                    {
                        for(int l=0;l<get_y();l++)
                        {
                            if(game_board.get(k+z).get(l+(Integer.parseInt(second_part)/2)+i)==' ')
                                game_board.get(k+z).set(l+(Integer.parseInt(second_part)/2)+i,vect.get(k).get(l));
                        }
                    }
                    this.draw();
                    for(int k=0;k<get_x();k++)
                    {
                        for(int l=0;l<get_y();l++)
                        {
                            game_board.get(k+z).set(l+(Integer.parseInt(second_part)/2)+i,' ');
                        }
                    } 
                    i++;
                    exitt=false;
                    for(int m=0;m<get_x();m++)
                    {
                        int c=game_board.get(m+z).get((Integer.parseInt(second_part)/2)-i)+vect.get(m).get(0)-' ';
                        if(!(c==' '||c==vect.get(m).get(0)||c==game_board.get(m+z).get((Integer.parseInt(second_part)/2)+i)))
                            exitt=true;
                    }
                    if(exitt)
                    {
                        --i;   
                        for(int k=0;k<get_x();k++)
                        {
                            for(int l=0;l<get_y();l++)
                            {
                                if(game_board.get(k+z).get(l+(Integer.parseInt(second_part)/2)+i)==' ')
                                    game_board.get(k+z).set(l+(Integer.parseInt(second_part)/2)+i,vect.get(k).get(l));
                            }
                        }
                        break;
                    }
                }
                if(i!=0)
                    --i;
                exitt=false;
                row_total=(Integer.parseInt(second_part)/2)+i;
            }
            else
            {
                System.out.print("The specified number of spaces does not exist in the specified direction\n");
                // cout<<"The specified number of spaces does not exist in the specified direction"<<endl;
                move_direct=0;
                return;
            }
        }
        
        while(z+get_x()<Integer.parseInt(first_part))
        {
            // System.out.print("************************************************************************"+row_total+"\n");
        //    row_totalz 
            for(int m=0;m<get_y();m++)
            {
                int c=game_board.get((z+get_x()-1)).get(m+row_total)+vect.get(get_x()-1).get(m)-' ';
                if(((c==game_board.get((z+get_x()-1)).get(m+row_total)))&&c!=' ')
                    eqit2=true;
            }
            if(eqit2)
            {
                // cout<<"YAGSAAAAAA"<<endl;
                for(int k=0;k<get_x();k++)
                {
                    for(int l=0;l<get_y();l++)
                    {
                        if(game_board.get(k+z).get(l+row_total)==' ')
                            game_board.get(k+z).set(l+row_total,vect.get(k).get(l));
                    }
                }
                this.draw();
                break;
                // exit(0);

            }
            else
            {
                for(int k=0;k<get_x();k++)
                {
                    for(int l=0;l<get_y();l++)
                    {
                        if(game_board.get(k+z).get(l+row_total)==' ')
                            game_board.get(k+z).set(l+row_total,vect.get(k).get(l));
                    }
                }
            }
            this.draw();
            
            for(int k=0;k<get_x();k++)
            {
                for(int l=0;l<get_y();l++)
                {
                    game_board.get(k+z).set(l+row_total,' ');
                }
            }  
            z++;
            if((z+get_x()-1)==Integer.parseInt(first_part)-1)
            {
                //--z;
                for(int k=0;k<get_x();k++)
                {
                    for(int l=0;l<get_y();l++)
                    {
                        if(game_board.get(k+z).get(l+row_total)==' ')
                            game_board.get(k+z).set(l+row_total,vect.get(k).get(l));
                    }
                }
                this.draw();
                break;
                // ++z;
            }
            for(int m=0;m<get_y();m++)
            {
                int c=game_board.get((z+get_x()-1)).get(m+row_total)+vect.get(get_x()-1).get(m)-' ';
                if(!(c==' '||c==vect.get(get_x()-1).get(m)||c==game_board.get((z+get_x()-1)).get(m+row_total)))
                    exitt=true;
            }
            if(exitt)
            {
                // cout<<"YAGAAAA"<<endl;
               // exit(0);
                --z;
                for(int k=0;k<get_x();k++)
                {
                    for(int l=0;l<get_y();l++)
                    {
                        if(game_board.get(k+z).get(l+row_total)==' ')
                            game_board.get(k+z).set(l+row_total,vect.get(k).get(l));
                    }
                }
                break;
            }
            
        }
    }

    /**
     * 
     * @param tetromino
     * @return
     */
    public String lastMove(String tetromino) 
    {
        // String str="";
        try
        {
            if(move_direct==1)
            {   
                return "Last move of "+tetromino+" Tetromino is to left and it move "+Integer.toString(move_count)+" square\n";
            }
            else if(move_direct==2)
            {
                return "Last move of "+tetromino+" Tetromino is to right and it move "+Integer.toString(move_count)+" square\n";
            }
            throw new Exception("Last move operation is Invalid!!");
        }
        catch(Exception move_direct_catch)
        {
            System.out.print(move_direct_catch);
            // throw new Exception
            // cout<<"Last move operation is Invalid!!";
        }
        
        return "CONTROL";
    }

    /**
     * return total move of game board
     * @return
     */
    public int numberOfMoves ()
    {
        try
        {
            if(move_direct==1||move_direct==2)
            {
                total_move+=move_count;
                return total_move;
            }
            else 
                throw new Exception("Invalid move direction");
        }
        catch(Exception move_direction)
        {
            return total_move;
        }
        
    }

    public void print(ArrayList<ArrayList<Character>>other)
    {
        for(int i=0;i<other.size();i++)
        {
            for(int j=0;j<other.get(0).size();j++)
            {
                if(other.get(i).get(j)==' ')
                    System.out.print("-");
                    else
                    System.out.print(other.get(i).get(j));
                }
            System.out.print("\n");
            
        }
    }

    public static <T> ArrayList<ArrayList<T>> deepCopy(ArrayList<ArrayList<T>> originalList) 
      {
        ArrayList<ArrayList<T>> deepCopy = new ArrayList<ArrayList<T>>();
        for (var item : originalList) 
        {
          ArrayList<T> temp=new ArrayList<>();
          for (var item1 : item) 
            temp.add(item1);
            // deepCopy.add(item);
          deepCopy.add(temp);
        }
        return deepCopy;
    }

    public void writeToFile(PrintWriter file) 
    {
        file.print("TOTAL MOVE NUMBER IS: ");
        file.print(total_move+"\n");
        file.print("GAME :\n");
        
        for(var x:game_board)
        {
            for(var y: x )
            {
                if(y==' ')
                    file.print("-");
                else
                    file.print(y);
            }
            file.print("\n");
        }
    }

    /**
     * it wil return game gameboard
     * @return
     */
    public ArrayList<ArrayList<Character>> get_game_board()
    {
        return game_board;
    }
}
