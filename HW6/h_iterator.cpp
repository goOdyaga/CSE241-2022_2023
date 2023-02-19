#include "h_iterator.h"

namespace GTU
{
    template<class T>
    GTUIterator<T>::GTUIterator(){}

    template<class T>
    GTUIterator<T>::GTUIterator(const GTUIterator<T>&obj)
    {
        ptr=obj.ptr;
    }

    template<class T>
    GTUIterator<T>::GTUIterator(const GTUIterator<T>&&obj)
    {
        ptr=std::move(obj.ptr);
    }

    template<class T>
    GTUIterator<T>::GTUIterator(shared_ptr<T> inputptr)
    {
        ptr=inputptr.get();
    }

    template<class T>
    T& GTUIterator<T>::operator*() 
    {
        return *ptr;
    }

    template<class T>
    T& GTUIterator<T>::operator->() 
    {
        return *ptr;
    }

    template<class T>
    GTUIterator<T> GTUIterator<T>::operator--()
    {
        ptr= (ptr-1);
        return *this;
    }

    template<class T>
    GTUIterator<T> GTUIterator<T>::operator++()
    {
        ptr= (ptr+1);
        return *this;

    }

    template<class U>
    bool operator==(const GTUIterator<U> &obj1,const GTUIterator<U> &obj2)
    {
        if(obj1.ptr == obj2.ptr)
            return true;
        return false;
    }

    template<class U>
    bool operator!=(const GTUIterator<U> &obj1,const GTUIterator<U> &obj2)
    {
        if(obj1.ptr != obj2.ptr)
            return true;
        return false;
    }

    template<class T>
    GTUIterator<T>& GTUIterator<T>::operator=(GTUIterator<T>&&other)
    {
        // ptr=other.ptr;
        ptr = std::move(other.ptr);
        return *this;
    }

    template<class T>
    GTUIterator<T>& GTUIterator<T>::operator=(GTUIterator<T>&other)
    {
        ptr=other.ptr;
        return *this;
    }
    
    template<class T>
    T* GTUIterator<T>::getPtr()
    {
        return ptr;
    }

    template<class T>
    bool GTUIterator<T>::empty()
    {
        if(ptr==NULL)
            return true;
        return false;
    }
} // namespace GTU