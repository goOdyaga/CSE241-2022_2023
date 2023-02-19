/* Hamza konaç- 210104004202 - Gebze Technical University */

#include "hw4_lib.h"


namespace doys
{
        /* ----------------------------- Inner class (DayOfYear class) function implementations ----------------------------- */

    DayOfYearSet::DayOfYear::DayOfYear() : day(1), month(1)
    {    }
    
    DayOfYearSet::DayOfYear::DayOfYear(int dayInput, int monthInput) : day(dayInput), month(monthInput)
    {    }
    
    DayOfYearSet::DayOfYear&  DayOfYearSet::DayOfYear::operator=(const DayOfYear& rightSide)/*assign operator*/
    {
        this->day = rightSide.day;
        this->month = rightSide.month;
        return *this;
    }
    
    DayOfYearSet::DayOfYear::DayOfYear(const DayOfYear & object)/*copy constructor*/
    {

        this->day=object.day;
        this->month=object.month;
    }

    void DayOfYearSet::DayOfYear::setDay(int dayInput)
    {
        setDay(dayInput);
    }

    void DayOfYearSet::DayOfYear::setMonth(int monthInput)
    {
        setMonth(monthInput);
    }

    inline int DayOfYearSet::DayOfYear::getDay() const{return day;};
    
    inline int DayOfYearSet::DayOfYear::getMonth() const{return month;};

    bool DayOfYearSet::DayOfYear::operator==(DayOfYearSet::DayOfYear &obj1)
    {
        if((this->getMonth()==obj1.getMonth()) && (this->getDay()==obj1.getDay())) 
            return true;/*if value's of the object's are same we will return true*/
        return false;
    }

    bool DayOfYearSet::DayOfYear::operator!=(DayOfYearSet::DayOfYear &obj1)
    {
        if(*this==obj1) return false;
        return true;
    }

    ostream& operator <<(ostream& outputStream, const DayOfYearSet::DayOfYear& object1)
    {
        cout << "(Day: " << object1.getDay() << ' ';/*print the console dayofyear class's objects data's */
        cout << "Month: " << object1.getMonth() << ')';
        return outputStream;
    }


    /* ----------------------------- DayOfYearSet class function implementations ----------------------------- */

   DayOfYearSet::DayOfYearSet(const initializer_list<DayOfYear> &doylist)
    {
        doyArr=nullptr; /* if there is no allocated memory to doyArr we don't free doyArr. we check this condition with nullptr*/
        DayOfYearSet temp;
        int i=-1;
        for(auto ip=doylist.begin();ip!=doylist.end();ip++)/*we use list iterator*/
            temp=temp+const_cast<DayOfYear&>(*ip);/*we use operator+ function for append dayofyear in dayofyearset*/
        
        *this=temp; /*temp is local variable so that distructor delete data. before that we assign temp's data's to this pointer*/
    }

    DayOfYearSet::DayOfYearSet( DayOfYear * PdoyArr, int size)
    {
        /*private constructor take dayofyear array and it's size and assign values */
        doyArr = PdoyArr;
        arraySize = size;
    }

    DayOfYearSet::DayOfYearSet()
    {
        doyArr=nullptr;
        arraySize=0;
    } 

    DayOfYearSet::~DayOfYearSet()
    {
        delete [] doyArr;
    }
    
    DayOfYearSet::DayOfYearSet(const DayOfYearSet& Object)
    {   /*copy constructor*/
    cout<<"qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"<<endl;
        this->arraySize = Object.getSize();
        this->doyArr = new DayOfYear[arraySize];
        for(int i = 0;i<arraySize;i++)
            this->doyArr[i] = Object.getArray()[i];
    }


    inline DayOfYearSet::DayOfYear* DayOfYearSet::getArray() const{return doyArr;};

    inline int DayOfYearSet::getSize() const{return arraySize;}

    void DayOfYearSet::remove(DayOfYear& removeDoy)
    {   /*we use operator-  funcction for remove dayofyear object*/
        DayOfYearSet temp=*this-removeDoy;
        *this=temp;
    }


    DayOfYearSet& DayOfYearSet::operator=(const DayOfYearSet& rtSide)
    {
        if(*this!=rtSide)/*temp=temp --> user can do this assignment therefore we require to check this condition*/
        {
            arraySize = rtSide.getSize();
            if(doyArr!=nullptr)
                delete [] doyArr;
                doyArr = new DayOfYearSet::DayOfYear[arraySize];
                for(int i=0;i<arraySize;i++)
                    getArray()[i] = rtSide.getArray()[i];
        }
        return *this;
    }

    ostream& operator <<(ostream& outputStream, const DayOfYearSet& object1)
    {
        for(int i=0;i<object1.getSize();i++)
        {
            outputStream << "Array's " << i+1 << ". element:\nDay -> " << object1.getArray()[i].getDay() << endl << "Month -> " << object1.getArray()[i].getMonth() << endl << endl;
        }
        return outputStream;
    }

    const DayOfYearSet operator+(const DayOfYearSet& object1, const DayOfYearSet& object2)
    {
       
        DayOfYearSet::DayOfYear* newArr;/*we decleare new array for union of two set*/
        vector<DayOfYearSet::DayOfYear> temp,temp2;
        for(int i=0;i<object2.getSize();i++)/*first push object1's element to temp2 vector*/
            temp2.push_back(object1.getArray()[i]);
        
        for(int i=0;i<object2.getSize();i++)
        {
            if(object1.control_doy_obj(object2.getArray()[i])==false)/*if object2's element dont contain object1's elemnt we push tihs elemnt to temp*/
                    temp.push_back(object1.getArray()[i]);
        }

        newArr = new DayOfYearSet::DayOfYear[object1.getSize() +temp.size()]; /* Allocate memory for dynamic array for exact size*/
        temp2.insert(temp2.end(), temp.begin(), temp.end());/*we append temp to temp2*/
        int i=-1;
        for(auto ptr=temp2.begin();ptr!=temp2.end();ptr++)
            newArr[++i]=*ptr;/*assign vector element to newArr */
        return DayOfYearSet(newArr,object1.getSize() +temp.size());
    }

    const DayOfYearSet operator+( DayOfYearSet& object1,  DayOfYearSet:: DayOfYear& object2)
    {
        if(object2.getMonth()<0 || object2.getMonth() > 12 || object2.getDay()<0 || object2.getDay()>31) return object1;
        if(object2.getMonth()==4 || object2.getMonth()==6 || object2.getMonth()==9 || object2.getMonth()==11)
            if(object2.getDay()>30) return object1;
        else if(object2.getMonth()==2)
            if(object2.getDay()>28) return object1;
        /* End of checking */

        bool duplicate = false;
        int sizeOfArray = object1.getSize();

        for(int i=0;i<sizeOfArray;i++)/*if object1 contain object2 we couldn't append object1*/
            if(object1.getArray()[i]==object2) return object1;
 
        vector<DayOfYearSet::DayOfYear> temp;

        for(int i=0;i<object1.getSize();i++)
            temp.push_back(object1.getArray()[i]);
        temp.push_back(object2);/*firstly append object1 values after append object2*/
        
        DayOfYearSet::DayOfYear* newArr = new DayOfYearSet:: DayOfYear[sizeOfArray+1];
        
        int i=-1;
        for(auto ptr=temp.begin();ptr!=temp.end();ptr++)
            newArr[++i]=*ptr;/*assign vector element to array*/
        return DayOfYearSet(newArr,sizeOfArray+1);
    }

    const DayOfYearSet operator-(const DayOfYearSet& object1, const DayOfYearSet& object2)
    {
        vector<DayOfYearSet::DayOfYear> temp;
        for(int i=0;i<object1.getSize();i++)
        {
            if(object2.control_doy_obj(object1.getArray()[i])==false) /*  */
                temp.push_back(object1.getArray()[i]); /* append object1 items that items not contained by object1*/
        }

        DayOfYearSet::DayOfYear* newArr=new DayOfYearSet::DayOfYear[temp.size()];

        int i=-1;
        for(auto ptr=temp.begin();ptr!=temp.end();ptr++)
            newArr[++i]=*ptr;/*assign temp elements to in newarray*/

        return DayOfYearSet(newArr,temp.size());
    }

    const DayOfYearSet operator-(DayOfYearSet& object1,  DayOfYearSet::DayOfYear& object2)
    {
        int sizeOfArray = object1.getSize();

        /* If there are no elements in the array yet */
        if(sizeOfArray==0) return object1;

        vector<DayOfYearSet::DayOfYear> temp;
        for(int i=0;i<sizeOfArray;i++)/*if object1 element's not same to object we will append items to temp*/
        {
            if(object1.getArray()[i]!=object2)
            {
                temp.push_back(object1.getArray()[i]);
            }
        }
        sizeOfArray = object1.getSize() - 1;

        if(object1.getSize()==temp.size()) return object1; /* If there is no match, return false because object1 not contain object2 */
        DayOfYearSet:: DayOfYear* newArr = new DayOfYearSet::DayOfYear[sizeOfArray];
        int i=-1;
        for(auto ptr=temp.begin();ptr!=temp.end();ptr++)
            newArr[++i]=*ptr;/* assign temps element to object1*/ 

        return DayOfYearSet(newArr,sizeOfArray);
    }

    const DayOfYearSet operator^(const DayOfYearSet& object1, const DayOfYearSet& object2)
    {
        vector<DayOfYearSet::DayOfYear> intersection;

        /* Determine the cardinality of the intersection set */
        for(int i=0;i<object1.getSize();i++)
        {
            for(int k=0;k<object2.getSize();k++)
            {
                if(object1.getArray()[i] == object2.getArray()[k])/*if there is intersection elment we push it to temp*/
                    intersection.push_back(object1.getArray()[i]);
            }
        }
        DayOfYearSet::DayOfYear* newArr = new DayOfYearSet::DayOfYear[intersection.size()]; /* Allocate memory for dynamic array for exact size*/
         int ct = -1; /* Indicates next index that will be assigned */
        
        for(auto ptr=intersection.begin();ptr!=intersection.end();ptr++)
            newArr[++ct]=*ptr;/* assign temps element to object1*/ 

        return DayOfYearSet(newArr,intersection.size());
    }

    const DayOfYearSet operator!(const DayOfYearSet& object1)
    {
        decltype(365-object1.getSize()) size;
        size = 365-object1.getSize(); /* Size of new array that will be returned */
        DayOfYearSet::DayOfYear* newArr = new DayOfYearSet::DayOfYear[size]; /* New array declaration */
        int ct = 0; /* The next index of array that will be assigned */

        int day = 1;
        int month = 1;

        while(month<=12)
        {
            DayOfYearSet::DayOfYear date(day,month);
            bool flag = true; /* Indicates whether the date ,that is generated, is in the object. If it is NOT in the object, flag will be true */
            /* Check whether the date that is generated is in the object */

            for(int i=0;i<object1.getSize();i++)
            {
                if(date==object1.getArray()[i]) flag = false;
            }

            if(flag==true) /* The date that is generated is NOT in the object, add the date to array that will be returned */
            {
                newArr[ct] = date;
                ct++;
            }

            if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) /* If the month has 31 days */
            {
                if(day==31)
                {
                    day = 1;
                    month++;
                }
                else day++;
            }

            else if(month==2) /* If the month is February */
            {
                if(day==28)
                {
                    day = 1;
                    month++;
                }
                else day++;
            }

            else /* If the month has 30 days */
            {
                if(day==30)
                {
                    day = 1;
                    month++;
                }
                else day++;
            }
        }

        return DayOfYearSet(newArr, size);
    }

    bool operator==(const DayOfYearSet& object1, const DayOfYearSet& object2)
    {
        if(object1.getSize()!=object2.getSize()) return false; /* If the size of arrays are not the same, that means the objects is NOT equal */

        for(int i=0;i < object1.getSize();i++)
        {
            if(object2.control_doy_obj(object1.getArray()[i])==false)
                return false;
        }

        return true;
    }

    bool operator!=(const DayOfYearSet& object1, const DayOfYearSet& object2)
    {
        if(object1==object2) 
            return false;
        return true;
    }

    const DayOfYearSet::DayOfYear DayOfYearSet::operator[](int index)
    {
        return getArray()[index];
    }

    void DayOfYearSet::saveFile(fstream &file,  DayOfYearSet &object) /* Save the object to txt file */
    {
        for(int i=0;i<object.getSize();i++)
        {
            file << "Index " << i+1 << ": (Day: " << object.getArray()[i].getDay() << ", Month: " << object.getArray()[i].getMonth() << ")\n";
        }
        file << "\n\n";
        
    }

    bool DayOfYearSet::control_doy_obj(const DayOfYearSet::DayOfYear & compr_obj) const
    {
        for(int i=0;i<getSize();i++)
            if(getArray()[i]==const_cast<DayOfYear&>(compr_obj))/* we control dayofyearset for contain or not contain object2*/
                return true;
        return false;
    }
}


