import java.util.Scanner;
import java.io.PrintWriter;


/**
 * @author Hamza KONAÇ
 */
public class driver2
{
    /**
     * 
     * @param args main
     */
    public static void main(String args[])
    {
        String temp;
        String board_size;
        Tetris temp_obj;
        boolean control=true;
        Scanner scanner=new Scanner(System.in);
        while (true)
        {
            System.out.print("1:PLAY GAME\n");
            System.out.print("2:EXIT GAME\n\n");
            temp=scanner.nextLine();
            temp=temp.replaceAll("\n", "");
            System.out.println(temp);

            // getline(cin,temp);
            if(temp.equals("1"))
            {
                while(true)
                {
                    System.out.println("Enter Game Board Size (sample:15x15) ");
                    temp=scanner.nextLine();
                    temp=temp.replaceAll("\n", "");
                    try {
                        temp_obj=new  Tetris(temp);
                        if(temp_obj.get_game_board().size()!=0)
                            break;
                    
                    } catch (Exception e) {
                        System.out.println("Object couldnt create because of wrong size input\n");
                        // TODO: handle exception
                    }
                }
                    int move_count,move_direct,direct_count,rotate_direct;
                    while (true)
                    {
                        System.out.println("\033c");
                        temp_obj.draw();
                        control=true;
                        System.out.print("1.Enter Tetromino Name\n");
                        System.out.print("Q:Save file and quit\n");
                        temp=scanner.nextLine();
                        temp=temp.replaceAll("\n", "");
                        // getline(cin,temp);
                        if(temp.equals("I")||temp.equals("i"))
                            temp_obj.Play_game(shapes.I);
                        else if(temp.equals("o")||temp.equals("O"))
                            temp_obj.Play_game(shapes.O);
                        else if(temp.equals("l")||temp.equals("L"))
                            temp_obj.Play_game(shapes.L);
                        else if(temp.equals("s")||temp.equals("S"))
                            temp_obj.Play_game(shapes.S);
                        else if(temp.equals("t")||temp.equals("T"))
                            temp_obj.Play_game(shapes.T);
                        else if(temp.equals("z")||temp.equals("Z"))
                            temp_obj.Play_game(shapes.Z);
                        else if(temp.equals("J")||temp.equals("j"))
                            temp_obj.Play_game(shapes.J);
                        else if(temp.equals("q")||temp.equals("Q"))
                        {
                            System.out.print("ENTER FILE NAME...(extension of file have to be txt and file name must contain only letters");
                            temp=scanner.nextLine();
                            temp=temp.replaceAll("\n", "");
                            // getline(cin,temp);
                
                            if(temp_obj.control_file_name(temp))   
                            {
                                System.out.print("TRUE FILE NAMEEEE");
                                //  String file_name("output");
                                //     file_name=file_name+to_String(TetrisVector.total_object)+".txt";
                                PrintWriter file = null;

                                try
                                {
                                    file = new PrintWriter(temp, "UTF-8");   
                                }
                                catch (Exception ex)  
                                {
                                    System.out.printf("The text cannot open!\n");
                                }
                                temp_obj.writeToFile(file);
                                file.close();
                            }
                            else    
                                System.out.print("FALSE FILE NAMEEE");
                            break;
                        }
                        else
                        {
                            System.out.print("Invalid input");
                            control=false;

                        }
                        if(control)
                        {

                            String tetromino_last= new String(temp);
                            // temp_obj.Play_game(shapes.);

                            System.out.print("Choose Rotate Direction \n");
                            System.out.println("1-LEFT\n");
                            System.out.println("2-RIGHT\n");
                            System.out.println("3-NONE");
                            while(true)
                            {
                                // getline(cin,temp);
                                temp=scanner.nextLine();
                                temp=temp.replaceAll("\n", "");
                                if((temp.charAt(0)<'1'||temp.charAt(0)>'3')||temp.length()>1||temp.length()==0) 
                                    System.out.print("Invalid temp.try Again!!\n");
                                else
                                    break;
                            }
                            rotate_direct=Integer.parseInt(temp);        
                            while(true)
                            {
                                System.out.print("Enter count of rotate  direction number\n");
                                // getline(cin,temp);
                                temp=scanner.nextLine();
                                temp=temp.replaceAll("\n", "");
                                if((temp.charAt(0)<'1'||temp.charAt(0)>'5')||temp.length()>1||temp.length()==0) 
                                {
                                    System.out.print("Invalid temp.try Again!!");
                                    //return Play_game();
                                }
                                else 
                                    break;
                            }
                        
                            direct_count=Integer.parseInt(temp);
                            System.out.print("Choose Move Direction \n");
                            System.out.println("1-LEFT\n");
                            System.out.println("2-RIGHT\n");
                            System.out.println("3-NONE\n\n");
                            
                            while (true)
                            {
                                // getline(cin,temp);
                                temp=scanner.nextLine();
                                temp=temp.replaceAll("\n", "");

                                if((temp.charAt(0)<'1'||temp.charAt(0)>'3')||temp.length()>1||temp.length()==0) 
                                {
                                    System.out.print("Invalid temp.try Again!!\n");
                                }
                                else
                                    break;
                            }
                            
                            move_direct=Integer.parseInt(temp);
                            while (true)
                            {
                                System.out.print("Enter count of move  direction number\n");
                                // getline(cin,temp);
                                temp=scanner.nextLine();
                                temp=temp.replaceAll("\n", "");
                                if(Tetris.is_number(temp)) 
                                {
                                    move_count=Integer.parseInt(temp);

                                    break;
                                }
                                else
                                    System.out.print("Invalid temp.try Again!!\n");
                            }
                            temp_obj.set_variables(move_count,move_direct,direct_count,rotate_direct);
                            temp_obj.Play_game(temp_obj.get_objec_of_tetrominos().get_shape_of_obj());
                            temp_obj.animate();
                            System.out.print(temp_obj.lastMove(tetromino_last));
                            System.out.print("\nTotal move number of Game is ");
                            System.out.print(temp_obj.numberOfMoves());
                            System.out.println("\n");;

                        }
                        
                            /* code */
                    }
                    
                

            }
            else if(temp.equals("2"))
            {
                System.out.print("GAME'S HAS FINISHED\n");
                    break;
            }
        }
        scanner.close();
    }
}
