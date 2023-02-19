/* Hamza konaç- 210104004202 - Gebze Technical University */

#ifndef HW4_LIB_H
#define HW4_LIB_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
using namespace std;

namespace doys
{
    class  DayOfYearSet
    {
        public:

            class DayOfYear
            {
                public:
                    DayOfYear(); /* No-parameter constructor, will initiliaze the variables as 1th January */
                    DayOfYear(int day, int month); /* Constructor that will initiliaze the variables as parameters */
                    DayOfYear(const DayOfYear & object); /* Copy constructor */
                    int getDay() const; /* Getter function for accessing to day variable */
                    int getMonth() const; /* Getter function for accessing to month variable */
                    void setDay(int dayInput); /* Setter function to change day variable */
                    void setMonth(int monthInput); /* Setter function to change month variable */
                    bool operator==(DayOfYear &obj1); /* == Operator Overloading */
                    bool operator!=(DayOfYear &obj1); /* != Operator Overloading */
                    DayOfYear& operator=(const DayOfYear& rightSide); /* Assignment Operator Overloading */
                    friend ostream& operator <<(ostream& outputStream, const DayOfYearSet::DayOfYear& object1);
                    
                private:
                    int month;
                    int day;

            };

            DayOfYearSet();
            DayOfYearSet(const initializer_list<DayOfYear> &doylist); /* Constructor that takes a list of DayOfYear objects. */
            DayOfYearSet(const DayOfYearSet& Object); /* Copy contructor */
            ~DayOfYearSet(); /* Destructor */
            int getSize() const; /* Getter function to access the variable that keeps the size of array */
            void remove(DayOfYear& removeDoy); /* Removes an element from the set. If there is no match with the element in the parameter, return false */
            bool control_doy_obj(const DayOfYearSet::DayOfYear & compr_obj) const;            

            DayOfYearSet& operator=(const DayOfYearSet& rtSide); /* Overloading assignment operator */
            friend ostream& operator <<(ostream& outputStream, const DayOfYearSet& object1);
            friend bool operator==(const DayOfYearSet& object1, const DayOfYearSet& object2);
            friend bool operator!=(const DayOfYearSet& object1, const DayOfYearSet& object2);
            friend const DayOfYearSet operator+(const DayOfYearSet& object1, const DayOfYearSet& object2);
            friend const DayOfYearSet operator+( DayOfYearSet& object1,  DayOfYearSet:: DayOfYear& object2);
            friend const DayOfYearSet operator-(const DayOfYearSet& object1, const DayOfYearSet& object2);
            friend const DayOfYearSet operator-(DayOfYearSet& object1,  DayOfYearSet::DayOfYear& object2);
            friend const DayOfYearSet operator^(const DayOfYearSet& object1, const DayOfYearSet& object2);
            friend const DayOfYearSet operator!(const DayOfYearSet& object1);
            const DayOfYearSet::DayOfYear operator[](int size);
            static void saveFile(fstream& file, DayOfYearSet& object); /* Save the object to txt file */

        private:
            // list<DayOfYearSet::DayOfYear> doylist;
            DayOfYear* getArray() const;/*private constructor*/
            DayOfYearSet( DayOfYear * PdoyArr, int size); /* Constructor that takes a dynamic array of DayOfYear objects. */
            DayOfYear* doyArr; /* */
            int arraySize;
            
    };
}
#endif