#ifndef PFARRAAY_H
#define PFARRAAY_H

#include "h_iterator.h"
#include<memory>
#include<iostream>
#include<algorithm>

using namespace std;

namespace GTU
{
    template<class T>
    class PFArray
    {
        public:
            PFArray(/* args */);
            PFArray(int capacity_value);
            PFArray(const PFArray<T>& copy_object);/*copy constructer*/
            // ~PFArray();
            bool empty() const;  // Checks that the set is empty or not
            int size() const; // Returns the size of the set
            bool erase(GTUIterator<T>& iter); // Erase the element that the iterator in the parameter points 
            void clear(); // Clears all the content of the array
            GTUIterator<T> begin() const; // Returns the iterator that points the first element
            GTUIterator<T> end() const; // Returns the iterator that points the end
            GTUIterator<T> const  cbegin() const; // Returns the constant iterator that points the first element
            GTUIterator<T> const  cend() const; // Returns the constant iterator that points the end
            
            void addElement(T element);
            bool full( ) const;
            inline int getNumberUsed( ) const{return used;};
            int get_capacity()const{return capacity;};
            inline void emptyArray( ){clear();};
            T& operator[](int index);
            PFArray<T>& operator =(const PFArray& rightSide);

            
        private:
            inline shared_ptr<T> get_ptr()const{return ptr;};
            shared_ptr<T> ptr;
            int capacity;/*allocate memory firstly and fill it include*/
            int used;/*for every filling element increase one by one*/
            /* data */
    };
};


#endif