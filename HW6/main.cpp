#include<iostream>
#include "PFArray.h"
#include "PFArray.cpp"
#include "h_iterator.h"
#include "h_iterator.cpp"
using namespace GTU;


void to_uppercase(char& c)
{
    c = std::toupper(c);
}

int main()
{
    PFArray<int> new_obj(5);
    cout<<endl<<"\n**************Type of new_obj2 is int *********"<<endl<<endl;
    cout<<"Size of new_obj is "<<new_obj.size()<<endl<<endl;
    cout<<"AddElemnet function Test\n"<<endl;
    new_obj.addElement(1);    
    new_obj.addElement(2);    
    new_obj.addElement(3);    
    new_obj.addElement(4);
    new_obj.addElement(5);
    cout<<"After Add element"<<endl<<endl;

    cout<<"Size of new_obj is "<<new_obj.size()<<endl<<endl;
    cout<<"Print element of new_obj by iTerator\n"<<endl;
    for(auto ptr=new_obj.begin();ptr!=new_obj.end();++ptr)
        cout<<*ptr<<" "<<endl;
    cout<<"\nTest Full function\n";
    if(new_obj.full())
        cout<<"\nPFArray is fulled\n";
    else
        cout<<"\nThere is empty space for new element\n"<<endl;
    cout<<"Size: "<<new_obj.size()<<" Capacity: "<<new_obj.get_capacity()<<endl<<endl;  
    new_obj.addElement(6);
    new_obj.addElement(7);
    new_obj.addElement(8);
    new_obj.addElement(9);
    cout<<"Test Full function\n";
    if(new_obj.full())
        cout<<"\nPFArray is fulled\n";
    else
        cout<<"\nThere is empty space for new element\n"<<endl;
    cout<<"Size: "<<new_obj.size()<<" Capacity: "<<new_obj.get_capacity()<<endl<<endl; 
    cout<<"Print element by for range loop\n";
    for(auto ptr:new_obj)
        cout<<ptr<<" ";
    cout<<"\nPrint element by for index \n";

    for(int i=0;i<new_obj.size();i++)
        cout<<new_obj[i]<<" ";
    cout<<"\n";
    cout<<"Erase FUnction TEST\n";
    while(!(new_obj.empty()))
    {
        auto iter=new_obj.begin();
        int a=*iter;
        if( new_obj.erase(iter)) 
            cout<<"Value of new_obj.begin() : "<<a<<" Element is Erased\n";
    }
    cout<<"Empty function Test\n";
    if(new_obj.empty())
        cout<<"\nPFArray is empty\n";
    else
        cout<<"\nPFArray is not empty"<<new_obj.size()<<"\n";
    cout<<"\nsize of new_obj after erease operations "<<new_obj.size()<<endl;
  
    PFArray<float> new_obj2(5);
    new_obj2.addElement(2.1);
    new_obj2.addElement(3.2);
    new_obj2.addElement(5.4);
    new_obj2.addElement(224.1);
    new_obj2.addElement(2.1234);
    new_obj2.addElement(1352.1);
    new_obj2.addElement(2.1134);
    new_obj2.addElement(256675.1);
    new_obj2.addElement(2.11243);
    new_obj2.addElement(23245.1);
    cout<<endl<<"\n**************Type of new_obj2 is Float *********"<<endl<<endl;
    cout<<"Size of new_obj2 is "<<new_obj2.size()<<endl<<endl;
    cout<<"Capacity of new_obj2 is "<<new_obj2.get_capacity()<<endl<<endl;
    cout<<"clear function  is runned"<<endl<<endl;
    new_obj2.clear();
    cout<<"Size of new_obj2 is "<<new_obj2.size()<<endl<<endl;
    cout<<"Capacity of new_obj2 is "<<new_obj2.get_capacity()<<endl<<endl;
    cout<<"Print element by for range loop\n"<<endl;
    for(auto ptr:new_obj2)
        cout<<ptr<<" ";
    
    cout<<endl<<"NEW ELEMENTS APPEND TO NEW_OBJ2"<<endl;
    new_obj2.addElement(2.1134);
    new_obj2.addElement(256675.1);
    new_obj2.addElement(2.11243);
    new_obj2.addElement(23245.1);
    cout<<"\nPrint element by for index \n\n";

    for(int i=0;i<new_obj2.size();i++)
        cout<<new_obj2[i]<<" ";
    PFArray<float> new_obj3;
    cout<<"\n\nnew_obj3 Assign to new_obj2"<<endl<<endl;
    new_obj3=new_obj2;
    cout<<"Size of new_obj2 "<<new_obj2.size()<<endl<<endl;
    cout<<"Capacity of new_obj2 "<<new_obj2.get_capacity()<<endl<<endl;
    cout<<"Size of new_obj3 "<<new_obj3.size()<<endl<<endl;
    cout<<"Capacity of new_obj3" <<new_obj3.get_capacity()<<endl<<endl;
    cout<<"\nElements of new_obj3 "<<endl<<endl;
    for(auto ptr:new_obj3)
        cout<<ptr<<" ";
    cout<<"\nElements of new_obj2"<<endl<<endl;
    for(auto ptr:new_obj2)
        cout<<ptr<<" ";
    cout<<"\n\n\n Testing find funciton in algorithm library\n"<<endl;
    auto it = std::find(new_obj2.begin(), new_obj2.end(), 3);
    if (it != new_obj2.end())
    {
        std::cout << "3 was found ind new_obj2 "  << '\n';
    }
    else
    {
        std::cout << "3 was not found\n";
    }
    cout<<"Appending 3 in new_obj3"<<endl;
    new_obj2.addElement(3);

    it = std::find(new_obj2.begin(), new_obj2.end(), 3);
    if (it != new_obj2.end())
    {
        std::cout << "3 was found ind new_obj2 "  << '\n';
    }
    else
    {
        std::cout << "3 was not found\n";
    }

    PFArray<char> new_obj4(8);
    new_obj4.addElement('h');
    new_obj4.addElement('a');
    new_obj4.addElement('m');
    new_obj4.addElement('z');
    new_obj4.addElement('a');
    new_obj4.addElement(' ');
    new_obj4.addElement('k');
    new_obj4.addElement('o');
    new_obj4.addElement('n');
    new_obj4.addElement('a');
    new_obj4.addElement('c');

    cout<<endl<<"\n**************Type of new_obj2 is Char *********"<<endl<<endl;
    cout<<"Size of new_obj4 is "<<new_obj4.size()<<endl;
    cout<<"Capacity of new_obj4 is "<<new_obj4.get_capacity()<<endl;
    cout<<"\nElements of new_obj4"<<endl;
    for(auto ptr:new_obj4)
        cout<<ptr<<" ";
    cout<<"\n\n\nTesting for_each funciton in algorithm library\n"<<endl;
    std::for_each(new_obj4.begin(),new_obj4.end(),::to_uppercase);
    cout<<"\nElements of new_obj4 after for_each with uppercase"<<endl;
    for(auto ptr:new_obj4)
        cout<<ptr<<" ";

    PFArray<double> new_obj5(8);
    new_obj5.addElement(3.2);
    new_obj5.addElement(4.2);
    new_obj5.addElement(1.1);
    new_obj5.addElement(-23);
    new_obj5.addElement(31.32);
    new_obj5.addElement(45);
    new_obj5.addElement(1.31);
    new_obj5.addElement(42.1);
    new_obj5.addElement(54.32);
    new_obj5.addElement(233.1);
    new_obj5.addElement(1);

    cout<<endl<<"\n**************Type of new_obj2 is Double *********"<<endl<<endl;
    cout<<"Size of new_obj4 is "<<new_obj5.size()<<endl;
    cout<<"Capacity of new_obj4 is "<<new_obj5.get_capacity()<<endl;
    cout<<"\nElements of new_obj4"<<endl;
    for(auto ptr:new_obj5)
        cout<<ptr<<" ";
    std::sort(new_obj5.begin(),new_obj5.end());
    cout<<"\n\n\n Testing sort funciton in algorithm library\n"<<endl;
    cout<<"AFTER SORTİNG\n";
    for(auto ptr:new_obj5)
        cout<<ptr<<" ";


    
    
    

}