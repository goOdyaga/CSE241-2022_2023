#include "PFArray.h"

namespace GTU
{
    template<class T>
    PFArray<T>::PFArray():used(0),capacity(0)
    {
        ptr=NULL;
    }

    template<class T>
    PFArray<T>::PFArray(int capacity_value):used(0),capacity(capacity_value)
    {
        std::shared_ptr<T> sp = std::shared_ptr<T>(new T[10]);
        ptr=std::move(sp);
    }

    template<class T>
    PFArray<T>::PFArray(const PFArray<T> & copy_object )
    {
        capacity=copy_object.get_capacity();
        used=copy_object.size();
        GTUIterator<T> iter(copy_object.begin());
        ptr = std::shared_ptr<T>(new T[capacity]);
        GTUIterator<T> iter1(get_ptr());
        GTUIterator<T> ptr_itr(ptr);
        for(int i=0;i<capacity;i++)
        {
            *(ptr_itr)=*iter;
            ++iter;
            ++ptr_itr;
        }
    }

    template<class T>
    bool PFArray<T>::empty() const
    {
        return size()==0;
    }

    template<class T>
    int PFArray<T>::size() const
    {
        return used;
    }

    template<class T>
    bool PFArray<T>::erase(GTUIterator<T> &iter)
    {
	    std::shared_ptr<T> new_contain = std::shared_ptr<T>(new T[size()-1]);
        GTUIterator<T> new_iter(new_contain);
        GTUIterator<T> iter_temp(begin());
        bool control=false;
        while(iter_temp!=end())
        {
            if(*iter!=*iter_temp)
            {
                *new_iter=*iter_temp;
                ++new_iter;
                ++iter_temp;
            }
            else
            {
                ++iter_temp;
                control=true;
            }
        }
        ptr=std::move(new_contain);
        if(control)
            used--;
        return control;
    }

    template<class T>
    void PFArray<T>::clear()
    {
    	std::shared_ptr<T> new_ptr=shared_ptr<T>(new T [capacity]);
        ptr=std::move(new_ptr);
        used=0;
    }

    template<class T>
    GTUIterator<T> PFArray<T>::begin() const
    {
        GTUIterator<T> iter(get_ptr());
        return iter;
    }

    template<class T>
    GTUIterator<T> PFArray<T>::end() const 
    {
        GTUIterator<T> iter(begin());
        int count=0;
        int size_=size();
        while(count<size_)
        {
            ++iter;
            count++;
        }
        return iter;
    }   


    template<class T>
    GTUIterator<T> const PFArray<T>::cbegin() const
    {
        GTUIterator<T> iter(get_ptr());
        return iter;
    }

    template<class T>
    GTUIterator<T> const PFArray<T>::cend() const 
    {
        GTUIterator<T> iter(begin());
        int count=0;
        int size_=size();
        while(count<size_)
        {
            ++iter;
            ++size_;
        }
        return iter;
    }   

    template<class T>
    void PFArray<T>::addElement(T element)
    {
	    std::shared_ptr<T> new_ptr = std::shared_ptr<T>(new T[capacity+10]);//(new T [capacity+10]);
        if(used<=capacity)
        {
            GTUIterator<T> iter(get_ptr());
            while(iter!=end())
            {
                ++iter;
            }
            *iter=element;
            used++;
        }
        else
        {
            capacity=capacity+10;
            GTUIterator<T> itr(get_ptr());
            GTUIterator<T> itr1(new_ptr.get());
    		itr=begin();
	            while(itr!=end())
            {

                *itr1=*itr;
                ++itr1;
                ++itr;
            }
            *itr1=element;
            used++;
            ptr=std::move(new_ptr);
        }
    }

    template<class T>
    bool PFArray<T>::full() const
    {
        return capacity==used;
    }

    template<class T>
    T& PFArray<T>:: operator[](int index)
    {
        GTUIterator<T> it(begin());
        int i=0;
        while(i<index)
        {
            ++it;
            ++i;
        }
        return *it;
    }

    template<class T>
    PFArray<T>& PFArray<T>:: operator =(const PFArray<T>& rightSide)
    {
        GTUIterator<T> it1(begin());
        GTUIterator<T> it2(rightSide.begin());
        if(it1!=it2)
        {
            shared_ptr<T> new_ptr=shared_ptr<T>(new T[rightSide.get_capacity()]);
            GTUIterator<T> new_itr(new_ptr);
            used=rightSide.size();
            capacity=rightSide.get_capacity();
            while(it2!=rightSide.end())
            {
                *new_itr=*it2;
                ++new_itr;
                ++it2;
            }
            ptr=std::move(new_ptr);
        }
        return *this;
    }
}