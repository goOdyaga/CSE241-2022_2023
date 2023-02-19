import java.util.ArrayList;
import java.util.Random;
import java.io.PrintWriter;
import java.io.Writer;


/**
 * @author Hamza KONAÇ
 */
public class driver1
{
    /**
     * 
     * @param args main
     */
    public static void main(String args[])
    {
        PrintWriter file = null;

        try
        {
        file = new PrintWriter("output.txt", "UTF-8");   
        }
        catch (Exception ex)  
        {
            System.out.printf("The text cannot open!\n");
        }
        Tetris temp_obj;
        ArrayList<Tetris> ArrayList_abs_obj=new ArrayList<>();
        ArrayList_abs_obj.add(new Tetris("20x20"));
        ArrayList_abs_obj.add(new Tetris("10x10"));
        ArrayList_abs_obj.add(new Tetris("15x15"));
        Random rand=new Random();
        int i=0;
        while (i<3)
        {
           temp_obj=ArrayList_abs_obj.get(i);/*assign temp_object pointer to differnet type class objects*/
           System.out.print("\033c");
            for(int j=0;j<15;j++)
            {

                String tetromino_last=new String("");
                ArrayList<shapes> shapes_enum=new ArrayList<>();
                shapes_enum.add(shapes.I);
                shapes_enum.add(shapes.J);
                shapes_enum.add(shapes.L);
                shapes_enum.add(shapes.O);
                shapes_enum.add(shapes.S);
                shapes_enum.add(shapes.T);
                shapes_enum.add(shapes.Z);
                shapes a=shapes_enum.get(rand.nextInt(shapes_enum.size()));
                if(a==shapes.I)
                    tetromino_last="I";
                else if(a==shapes.J)
                    tetromino_last="J";
                else if(a==shapes.L)
                    tetromino_last="L";
                else if(a==shapes.O)
                    tetromino_last="O";
                else if(a==shapes.S)
                    tetromino_last="S";
                else if(a==shapes.T)
                    tetromino_last="T";
                else if(a==shapes.Z)
                    tetromino_last="Z";
                temp_obj.set_variables(rand.nextInt(10)+1,rand.nextInt(2)+1,rand.nextInt(4),rand.nextInt(2)+1);
                temp_obj.Play_game(a);
                temp_obj.animate();
                System.out.printf("%s",temp_obj.lastMove(tetromino_last));
                System.out.print("\nTotal move number of Game is "+temp_obj.numberOfMoves()+"\n");

            }
            temp_obj.writeToFile(file);
            i++;
        }
        file.close();
        System.out.printf("%s3 Different game board which have different size have already runned.\n","\033[32m");
        System.out.print("Game board final view saved to output.txt with total movement\n");
        System.out.printf("You can control game board there easily%s\n","\033[0m");
    }
    
}
