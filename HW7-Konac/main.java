// import java.util.Arrays;
import java.util.ArrayList;
import java.util.Scanner;
// import java.lang.*;
// import java.io.*;
// import java.util.*;

public class main {
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
    };
    public static void main(String args[])
    {
        ArrayList<Integer> x=new ArrayList<>();
        System.out.println(x.size());
        System.out.println();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a line of text: ");
        String input = scanner.nextLine();
        System.out.println("You entered: " + input);
        input = scanner.nextLine();
        System.out.println("You entered: " + input);
        ArrayList<ArrayList<Character>> game_board =new ArrayList<ArrayList<Character> >();
                ArrayList<Character>  temp = new ArrayList<>();
                for(int i=0;i<Integer.parseInt("10");i++)
                    temp.add(' ');
                
                for(int i=0;i<Integer.parseInt("10");i++)
                    game_board.add(temp);
        int a=' '+65;
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                game_board.get(i).set(j,'m');
        
        for(int i=0;i<10;i++)
        {

            for(int j=0;j<10;j++)
            {
                System.out.print(game_board.get(i).get(j)+" ");
                // game_board.get(i).set(j,'m');
                
            }
            System.out.print("\n");
        }
        
        if(a=='a')
            System.out.print(a+" hamza");
        int m;
        if(true)
            m=1;
        if(true)
            m=2;
        if(true)
            m=3;
        ArrayList<Integer> arra=new ArrayList<>();
        arra.add(1);
        arra.add(1);
        arra.add(1);
        arra.add(1);
        System.out.print("\n--> "+arra.get(m)+"\n");


        // for(int i=0;i<100;i++)
        // {
        //     try {
        //         Thread.sleep(50);
        //     } catch (InterruptedException e) {
        //         // Handle exception
        //     }
        //     System.out.print("hhhhhhhhhhhhhhhhhhhhhhhhhhhhhh hamza\n");
        // }
        // System.out.print("\033c");


        System.out.print("\n");
        boolean hm=is_number("1234a");
        System.out.print(hm);
        System.out.printf("\n");
        String str= "hamza.txt" ,nstr="";
        Character ch;
        for (int i=0; i<str.length(); i++)
        {
            ch= str.charAt(i); //extracts each character
            System.out.printf("%c ",ch);
            nstr= ch+nstr; //adds each character in front of the existing string
        }
         System.out.print(nstr);

        // String input = "Hello";
        System.out.print(input.matches(".*[0-9].*"));
    }
}
