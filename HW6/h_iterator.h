/* Hamza Konaç - 210104004202 - Gebze Technical University */
#ifndef H_ITERATOR_H
#define H_ITERATOR_H
#include <memory>
using namespace std;

namespace GTU
{

    template<class T>
    class GTUIterator
    {
        public:
            GTUIterator(T* p) : ptr(p) {}
            using value_type = T;
            using reference = T&;
            using pointer = T*;
            using difference_type = std::ptrdiff_t;
            using iterator_category = std::random_access_iterator_tag;
            GTUIterator(const GTUIterator<T>& object);
            GTUIterator(const GTUIterator<T>&& object);
            GTUIterator();
            GTUIterator(shared_ptr<T> ptr);
            T& operator*() ;
            T& operator->();
            GTUIterator<T> operator++();
            GTUIterator<T> operator--();

            template<typename U> friend bool operator==(const GTUIterator<U>& obj1, const GTUIterator<U>& obj2);
            template<typename U> friend bool operator!=(const GTUIterator<U>& obj1, const GTUIterator<U>& obj2);
            GTUIterator<T>& operator=(GTUIterator<T>&& other);
            GTUIterator<T>& operator=(GTUIterator<T>& other);
            GTUIterator<T> operator++(int) { GTUIterator<T> tmp(*this); ++(*this); return tmp; }
            GTUIterator<T> operator--(int) { GTUIterator<T> tmp(*this); --(*this); return tmp; }

            friend GTUIterator<T>  operator+(const GTUIterator<T> & it, difference_type n) { return GTUIterator<T> (it.ptr + n); }
            friend GTUIterator<T>  operator+(difference_type n, const GTUIterator<T> & it) { return GTUIterator<T> (it.ptr + n); }
            friend GTUIterator<T>  operator-(const GTUIterator<T> & it, difference_type n) { return GTUIterator<T> (it.ptr - n); }
            friend difference_type operator-(const GTUIterator<T> & lhs, const GTUIterator<T> & rhs) { return lhs.ptr - rhs.ptr; }

            friend bool operator==(const GTUIterator<T> & lhs, const GTUIterator<T> & rhs) { return lhs.ptr == rhs.ptr; }
            friend bool operator!=(const GTUIterator<T> & lhs, const GTUIterator<T> & rhs) { return lhs.ptr != rhs.ptr; }
            friend bool operator<(const GTUIterator<T> & lhs, const GTUIterator<T> & rhs) { return lhs.ptr < rhs.ptr; }
            friend bool operator>(const GTUIterator<T> & lhs, const GTUIterator<T> & rhs) { return lhs.ptr > rhs.ptr; }
            friend bool operator<=(const GTUIterator<T> & lhs, const GTUIterator<T> & rhs) { return lhs.ptr <= rhs.ptr; }
            friend bool operator>=(const GTUIterator<T> & lhs, const GTUIterator<T> & rhs) { return lhs.ptr >= rhs.ptr; }
            reference operator[](difference_type n) const { return ptr[n]; }

            bool empty();
            T* getPtr();

        private:
            T* ptr;
    };
}


#endif