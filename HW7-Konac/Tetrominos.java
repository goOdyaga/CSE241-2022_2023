import java.util.Arrays;
import java.util.ArrayList;

/**
 * this class provide give tetorminos the data tpye
 * @author HAMZA KONAÇ - 210104004202
 * @version 1.0
 * @since 14.01.2023
 */
// enum shapes {I,O,T,J,L,S,Z };

// class ArrayList<ArrayList<Character>> extends ArrayList<ArrayList<Character>> { }

/**
 * This class represent for Tetris game's terominos. It include for create a tetromino all necesseary methods and data's
 * @author HAMZA KONAÇ - 210104004202
 * @version 1.1
 * @since 14.01.2023
 */
public class Tetrominos
{
    private ArrayList<ArrayList<Character>>  shape;
    private shapes shape_of_obj;
    
    /**
     * DEFAULT CONSTRUCTER
     */
    public Tetrominos()
    {}
    
    /**
     * constructor THAT TAKE TETROMINOS ENUM TYPE
     * @param in
     */
    public Tetrominos(shapes in)
    {
        if(in==shapes.I)
        {
            shape=to_represent_I();
            shape_of_obj=shapes.I;

        }
        else if(in==shapes.J)
        {
            shape=to_represent_J();
            shape_of_obj=shapes.J;
        }
        else if(in==shapes.L)
        {
            shape=to_represent_L();
            shape_of_obj=shapes.L;
        }
        else if(in==shapes.O)
        {
            shape=to_represent_O();
            shape_of_obj=shapes.O;
        }
        else if(in==shapes.S)
        {
            shape=to_represent_S();
            shape_of_obj=shapes.S;
        }
        else if(in==shapes.T)
        {
            shape=to_represent_T();
            shape_of_obj=shapes.T;
        }
        else if(in==shapes.Z)
        {
            shape=to_represent_Z();
            shape_of_obj=shapes.Z;
        }
    }
    
    /**
     * function of Arraylist that are Fill an Arraylist according to tetromino I
     * @return Tetromino I
     */
    public ArrayList<ArrayList<Character>> to_represent_I()
    {
      shape_of_obj=shapes.I;
      ArrayList<ArrayList<Character>> new_ = new ArrayList<>();
      for (int i = 0; i < 3; i++) {
          ArrayList<Character> innerList = new ArrayList<>();
          innerList.add('I');
          innerList.add(' ');
          innerList.add(' ');
          new_.add(innerList);
      }
      return new_;
    }
    
    /**
     * function of Arraylist that are Fill an Arraylist according to tetromino O
     * @return Arraylist of Tetromino O
     */
    public ArrayList<ArrayList<Character>> to_represent_O()
    {
      shape_of_obj=shapes.O;
      ArrayList<ArrayList<Character>> new_=new ArrayList<>();
      for( int i=0;i<2;i++)
      {
        ArrayList<Character> temp= new ArrayList<>();
        temp.add('O');
        temp.add('O');
        new_.add(temp);
      }
      return new_;
    }
    
    /**
     * function of Arraylist that are Fill an Arraylist according to tetromino T
     * @return Arraylist of Tetromino T
     */
    public ArrayList<ArrayList<Character>> to_represent_T()
    {
      shape_of_obj=shapes.T;
      ArrayList<ArrayList<Character>> new_=new ArrayList<>();
      ArrayList<Character> temp=new ArrayList<>(Arrays.asList(' ',' ',' '));
      ArrayList<Character> temp1=new ArrayList<>(Arrays.asList('T','T','T'));
      ArrayList<Character> temp2=new ArrayList<>(Arrays.asList(' ','T',' '));
      new_.add(temp);
      new_.add(temp1);
      new_.add(temp2);
      return new_;
    }
    
    /**
     * function of Arraylist that are Fill an Arraylist according to tetromino J
     * @return Arraylist of Tetromino J
     */
    public ArrayList<ArrayList<Character>> to_represent_J()
    {
      shape_of_obj=shapes.T;
      ArrayList<ArrayList<Character>> new_=new ArrayList<>();
      ArrayList<Character> temp=new ArrayList<>(Arrays.asList(' ',' ','J'));
      ArrayList<Character> temp1=new ArrayList<>(Arrays.asList(' ',' ','J'));
      ArrayList<Character> temp2=new ArrayList<>(Arrays.asList(' ','J','J'));
      new_.add(temp);
      new_.add(temp1);
      new_.add(temp2);
      return new_;
    }
    
    /**
     * function of Arraylist that are Fill an Arraylist according to tetromino S
     * @return Arraylist of Tetromino S
     */
    public ArrayList<ArrayList<Character>> to_represent_S()
    {
      shape_of_obj=shapes.T;
      ArrayList<ArrayList<Character>> new_=new ArrayList<>();
      ArrayList<Character> temp=new ArrayList<>(Arrays.asList(' ',' ',' '));
      ArrayList<Character> temp1=new ArrayList<>(Arrays.asList(' ','S','S'));
      ArrayList<Character> temp2=new ArrayList<>(Arrays.asList('S','S',' '));
      new_.add(temp);
      new_.add(temp1);
      new_.add(temp2);
      return new_;
    }
    
    /**
     * function of Arraylist that are Fill an Arraylist according to tetromino Z
     * @return Arraylist of Tetromino Z
     */
    public ArrayList<ArrayList<Character>> to_represent_Z()
    {
      shape_of_obj=shapes.T;
      ArrayList<ArrayList<Character>> new_=new ArrayList<>();
      ArrayList<Character> temp=new ArrayList<>(Arrays.asList(' ',' ',' '));
      ArrayList<Character> temp1=new ArrayList<>(Arrays.asList('Z','Z',' '));
      ArrayList<Character> temp2=new ArrayList<>(Arrays.asList(' ','Z','Z'));
      new_.add(temp);
      new_.add(temp1);
      new_.add(temp2);
      return new_;
    }
    
    /**
     * function of Arraylist that are Fill an Arraylist according to tetromino L
     * @return Arraylist of Tetromino L
     */
    public ArrayList<ArrayList<Character>> to_represent_L()
    {
      shape_of_obj=shapes.T;
      ArrayList<ArrayList<Character>> new_=new ArrayList<>();
      ArrayList<Character> temp=new ArrayList<>(Arrays.asList('L',' ',' '));
      ArrayList<Character> temp1=new ArrayList<>(Arrays.asList('L',' ',' '));
      ArrayList<Character> temp2=new ArrayList<>(Arrays.asList('L','L',' '));
      new_.add(temp);
      new_.add(temp1);
      new_.add(temp2);
      return new_;
    }
    
    /**
     * assign rside objects shape to this object's shape
     * @param rside
     * @return
     */
    public Tetrominos equal(Tetrominos rside)
    {
      // shape = new ArrayList<>();
      //   shape.resize(rside.get_shape().size(),vector<char>(rside.get_shape().at(0).size()));
      //   for(int i=0;i<rside.get_shape().size();i++)
      // {
        //     for(int j=0;j<rside.get_shape().at(0).size();j++)
        //         shape.at(i).at(j)=rside.get_shape().at(i).at(j);
        // }
      shape =deepCopy( rside.get_shape());
      shape_of_obj=rside.shape_of_obj;
      return this;   
    }
    
    /**
     * This function take direction and rotate to tetromino  this direction 
     * @param direction direction is lef or right
     */
    public void rotate(int direction)
    {
      ArrayList<ArrayList<Character>> temp=deepCopy(shape);
      // for(int i=0;i<get_shape().size();i++)
      // {
      //   ArrayList<Character> TEm=new ArrayList<>();
      //   for(int j=0;j<get_shape().get(0).size();j++)
      //   {
      //     TEm.add(get_shape().get(i).get(j));
      //   }
      //   temp.add(TEm);
      // }
      // get_shape();
      if(shape_of_obj==shapes.O||shape_of_obj==shapes.I)
          return;
      if(1==direction)
      {
    
          shape.get(0).set(0, temp.get(2).get(0));;//   - - -
          shape.get(0).set(1, temp.get(1).get(0));;//   - - -
          shape.get(0).set(2, temp.get(0).get(0));;//   - - -
          shape.get(1).set(0, temp.get(2).get(1));;//   I think all shapes are cube
          shape.get(1).set(1, temp.get(1).get(1));;//   so that I return cube
          shape.get(1).set(2, temp.get(0).get(1));;//   - - -
          shape.get(2).set(0, temp.get(2).get(2));;//   - - -
          shape.get(2).set(1, temp.get(1).get(2));;//   - - -
          shape.get(2).set(2, temp.get(0).get(2));;//   - - -
        // shape.at(0).at(1)=temp.at(1).at(0);//   - - - 
          // shape.at(0).at(2)=temp.at(0).at(0);//   - - -
          // shape.at(1).at(0)=temp.at(2).at(1);//I think all shapes are cube 
          // shape.at(1).at(1)=temp.at(1).at(1);// so that I return cube 
          // shape.at(1).at(2)=temp.at(0).at(1);//
          // shape.at(2).at(0)=temp.at(2).at(2);//
          // shape.at(2).at(1)=temp.at(1).at(2);//
          // shape.at(2).at(2)=temp.at(0).at(2);//
      }    

      else if(2==direction)
      {
          shape.get(0).set(0, temp.get(0).get(2));;//   - - -
          shape.get(0).set(1, temp.get(1).get(2));;//   - - -
          shape.get(0).set(2, temp.get(2).get(2));;//   - - -
          shape.get(1).set(0, temp.get(0).get(1));;//   I think all shapes are cube
          shape.get(1).set(1, temp.get(1).get(1));;//   so that I return cube
          shape.get(1).set(2, temp.get(2).get(1));;//   - - -
          shape.get(2).set(0, temp.get(0).get(0));;//   - - -
          shape.get(2).set(1, temp.get(1).get(0));;//   - - -
          shape.get(2).set(2, temp.get(2).get(0));;//   - - -
          // shape.at(0).at(0)=temp.at(0).at(2);
          // shape.at(0).at(1)=temp.at(1).at(2);
          // shape.at(0).at(2)=temp.at(2).at(2);
          // shape.at(1).at(0)=temp.at(0).at(1);
          // shape.at(1).at(1)=temp.at(1).at(1);
          // shape.at(1).at(2)=temp.at(2).at(1);
          // shape.at(2).at(0)=temp.at(0).at(0);
          // shape.at(2).at(1)=temp.at(1).at(0);
          // shape.at(2).at(2)=temp.at(2).at(0);
      }
    }
     /**
      * assign shape that private member ot Tetromino class to temp that is parameter of set_shap function
      * @param temp
      */
    public  void set_shape(ArrayList<ArrayList<Character>> temp) {shape.clear();;shape=deepCopy(temp);};
    
    /**
     * shape that private member ot Tetromino class
     * @return shape
     */
    public   ArrayList<ArrayList<Character>> get_shape() {return shape;}
    
    /**
     * shape that private member of Tetromino class
     * @return shape_of_bj
     */
    public  shapes get_shape_of_obj(){ return shape_of_obj;};
    
    /**
     * take other shape_of_obj arraylist and remove full empty row and column
     * @param other
     * @return other
     */
    public ArrayList<ArrayList<Character>>  resize_ArrayList(ArrayList<ArrayList<Character>>  other)
    {
        int counter1=0,counter2=0;
      
        int x=other.size(),y=other.get(0).size();
        
        for(int i=0;i<other.size();i++)
        {
          counter1+=other.get(i).get(0)/*.get(i)[0]*/;
          counter2+=other.get(i).get(other.get(0).size()-1);
        }
        if(counter1/32==other.size())
        {
          for(int i=0;i<x;i++)
              other.get(i).remove(0);

        }
        else if(counter2/32==other.size())
        {
        
          for(int i=0;i<x;i++)
              other.get(i).remove(other.get(i).size()-1);

        }

        else
        {
          counter2=0;
          for(int i=0;i<y;i++)
          {
            
              counter2+=other.get(other.get(0).size()-1).get(i);
          }
          if(counter2/32==other.get(0).size())
              other.remove(other.size()-1);
        }
        return other;
      }

    public static  ArrayList<ArrayList<Character>> deepCopy(ArrayList<ArrayList<Character>> originalList) 
      {
        ArrayList<ArrayList<Character>> deepCopy = new ArrayList<ArrayList<Character>>();
        for (var item : originalList) 
        {
          ArrayList<Character> temp=new ArrayList<>();
          for (var item1 : item) 
            temp.add(item1);
            // deepCopy.add(item);
          deepCopy.add(temp);
        }
        return deepCopy;
    }
}