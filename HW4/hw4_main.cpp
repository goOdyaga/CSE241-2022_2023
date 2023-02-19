/* Hamza konaç- 210104004202 - Gebze Technical University */

/* NOTE FOR T.A. -> All the outputs in the console, is printed to text file too. It is easier to check */
/* NOTE FOR T.A. -> Operator [] can only be checked as console output. It is not printed to text file */
/* NOTE FOR T.A. -> Complement set example's elements is printed to text file. They are not printed as console output because of its length */

#include "hw4_lib.h"

using namespace doys;


int main()
{
    fstream file;
    file.open("output.txt",ios::out);
  
    /* Object1 initiliazed with list_initialazier parameter contsructor */
    DayOfYearSet object1{DayOfYearSet::DayOfYear(7,4),DayOfYearSet::DayOfYear(3,3),DayOfYearSet::DayOfYear(4,4),DayOfYearSet::DayOfYear(5,5),
    DayOfYearSet::DayOfYear(6,6),DayOfYearSet::DayOfYear(7,8),DayOfYearSet::DayOfYear(12,32),DayOfYearSet::DayOfYear(2,31)};
    cout << "Size of object1: " << object1.getSize() << endl;
    file << "Size of object1: " << object1.getSize() << endl;
    DayOfYearSet::saveFile(file,object1);
    /* Object2 initiliazed with list parameter constructor */
    DayOfYearSet object2{DayOfYearSet::DayOfYear(1,1),DayOfYearSet::DayOfYear(2,2),DayOfYearSet::DayOfYear(4,8),DayOfYearSet::DayOfYear(5,8),
    DayOfYearSet::DayOfYear(6,8),DayOfYearSet::DayOfYear(7,8),DayOfYearSet::DayOfYear(7,8),DayOfYearSet::DayOfYear(1,30)};
    file << "Size of object2: " << object2.getSize() << endl;
    DayOfYearSet::saveFile(file,object2);
    cout << "Size of object2: " << object2.getSize() << endl << endl;



    /* Print the information, then compare the object1 and object2 */
    cout << "OBJECT1:\n" << object1 << endl;
    cout << "OBJECT2:\n" << object2;
    cout << "Comparing object1 and object2: ";
    if(object1==object2) 
        cout << "The objects are equal!\n";
    else if(object1!=object2) 
        cout << "The objects are NOT equal!\n\n";

    /* Print the intersection set of object1 and object2 */
    DayOfYearSet intersec = object1 ^ object2;
    cout << "Size of intersection set of object1 and object2: " << intersec.getSize();
    cout << "\nThe intersection set of object1 and object2:\n";
    cout << intersec;
    file << "Size of intersection set of object1 and object2: " << intersec.getSize() << endl;
    DayOfYearSet::saveFile(file,intersec);

    /* Print the union set of object1 and object2 */
    DayOfYearSet unions = object1 + object2;
    cout << "Size of union set: " << unions.getSize();
    cout << "\nThe union set of object1 and object2:\n";
    cout << unions;
    file << "Size of union set of object1 and object2: " << unions.getSize() << endl;
    DayOfYearSet::saveFile(file,unions);

    /* Print the difference set object1-object2 */
    DayOfYearSet difference1 = object1 - object2;
    cout << "Size of difference set (object1-object2): " << difference1.getSize();
    cout << "\nThe difference set (object1-object2)\n";
    cout << difference1;
    file << "Size of difference set (object1-object2): " << difference1.getSize() << endl;
    DayOfYearSet::saveFile(file,difference1);

    /* Print the difference set object2-object1 */
    DayOfYearSet difference2 = object2 - object1;
    cout << "Size of difference set (object2-object1): " << difference2.getSize();
    cout << "\nThe difference set (object2-object1):\n";
    cout << difference2;
    file << "Size of difference set (object2-object1): " << difference2.getSize() << endl;
    DayOfYearSet::saveFile(file,difference2);
    
   
   /* initialize new element*/
    DayOfYearSet::DayOfYear newElement(9,11);
    DayOfYearSet::DayOfYear newElement2(31,12);

    object1=object1+ newElement;
    file << "Size of object1 after adding a new element: " << object1.getSize() << endl;
    DayOfYearSet::saveFile(file,object1);
    cout << "Size of object2: " << object2.getSize() << endl << endl;

    object2=object2+ newElement2;
    file << "Size of object2 after adding a new element: " << object2.getSize() << endl;
    DayOfYearSet::saveFile(file,object2);
    cout << "Size of object2: " << object2.getSize() << endl << endl;

    cout << "Size of object1 after adding new element: " << object1.getSize() << endl;
    cout << "Size of object2 after adding new element: " << object2.getSize() << endl << endl;

    /* Print the intersection set of object1 and object2 after adding new elements */
    intersec = object1 ^ object2;
    cout << "Size of intersection set after adding new element: " << intersec.getSize();
    cout << "\nThe intersection set of object1 and object2 after adding new elements:\n";
    cout << intersec;
    file << "Size of intersection set of object1 and object2 after adding new elements: " << intersec.getSize() << endl;
    DayOfYearSet::saveFile(file,intersec);

    /* Print the union set of object1 and object2 after adding new elements */
    unions = object1 + object2;
    cout << "Size of unions set after adding new element: " << unions.getSize();
    cout << "\nThe unions set of object1 and object2 after adding new elements:\n";
    cout << unions;
    file << "Size of unions set of object1 and object2 after adding new elements:: " << unions.getSize() << endl;
    DayOfYearSet::saveFile(file,unions);

    /* Print the difference set object1-object2 after adding new elements*/
    difference1 = object1 - object2;
    cout << "Size of difference set (object1-object2) after adding new elements: " << difference1.getSize();
    cout << "\nThe difference set (object1-object2) after adding new elements\n";
    cout << difference1;
    file << "Size of difference set object1-object2 after adding new elements:: " << difference1.getSize() << endl;
    DayOfYearSet::saveFile(file,difference1);
    

    /* Print the difference set object2-object1 after adding new elements*/
    difference2 = object2 - object1;
    cout << "Size of difference set (object2-object1) after adding new elements: " << difference2.getSize();
    cout << "\nThe difference set (object2-object1) after adding new elements:\n";
    cout << difference2;
    file << "Size of unions set object2-object1 after adding new elements:: " << difference2.getSize() << endl;
    DayOfYearSet::saveFile(file,difference2);

    /* Removing some elements from the objects */
    object1=object1-newElement;
    file << "Size of object1 after removing some elements with operator-: " << object1.getSize() << endl;
    DayOfYearSet::saveFile(file,object1);

    object2.remove(newElement2);
    file << "Size of object2 after removing some elements: " << object2.getSize() << endl;
    DayOfYearSet::saveFile(file,object2);

    cout << "Size of object1 after removing some elements with operator-: " << object1.getSize() << endl;
    cout << "Size of object2 after removing some elements: " << object2.getSize() << endl << endl;

    /* Print the intersection set of object1 and object2 after removing some elements */
    intersec = object1 ^ object2;
    cout << "Size of intersection set after removing some elements: " << intersec.getSize();
    cout << "\nThe intersection set of object1 and object2 after removing some elements:\n";
    cout << intersec;
    file << "Size of intersection set of object1 and object2 after removing some elements: " << intersec.getSize() << endl;
    DayOfYearSet::saveFile(file,intersec);

    /* Print the union set of object1 and object2 after removing some elements */
    unions = object1 + object2;
    cout << "Size of unions set after removing some elements: " << unions.getSize();
    cout << "\nThe unions set of object1 and object2 after removing some elements:\n";
    cout << unions;
    file << "Size of union set of object1 and object2 after removing some elements: " << unions.getSize() << endl;
    DayOfYearSet::saveFile(file,unions);

    /* Print the difference set object1-object2 after removing some elements*/
    difference1 = object1 - object2;
    cout << "Size of difference set (object1-object2) after removing some elements: " << difference1.getSize();
    cout << "\nThe difference set (object1-object2) after removing some elements\n";
    cout << difference1;
    file << "Size of difference set object1-object2 after removing some elements: " << difference1.getSize() << endl;
    DayOfYearSet::saveFile(file,difference1);

    /* Print the difference set object2-object1 after removing some elements*/
    difference2 = object2 - object1;
    cout << "Size of difference set (object2-object1) after removing some elements: " << difference2.getSize();
    cout << "\nThe difference set (object2-object1) after removing some elements:\n";
    cout << difference2;
    file << "Size of difference set object2-object1 after removing some elements: " << difference2.getSize() << endl;
    DayOfYearSet::saveFile(file,difference2);

    /* Testing [] oparator */
    cout << "1. index of object1 = " << object1[1] << endl;
    file << "CHECKING THE [] OPERATOR (it can only be observed in console output)->\n1. index of object1 = ( Day: " << object1[1].getDay() << "), (Month: " << object1[1].getMonth() << ")\n";

    cout << "3. index of object2 = " << object2[3] << endl << endl;
    file << "3. index of object2 = ( Day: " << object2[3].getDay() << "), (Month: " << object2[3].getMonth() << ")\n\n";

    /* Check Complement Set of object1 */
    DayOfYearSet comp = !object1;

    cout << "The size of complement set of object1 (!object1): " << comp.getSize() << endl;
    file << "The size of complement set of object1 (!object1): " << comp.getSize() << endl;
    DayOfYearSet::saveFile(file,comp);

    file.close();


}

