GTUIterator<T> operator++(int) { GTUIterator<T> tmp(*this); ++(*this); return tmp; }
            // GTUIterator<T> operator--(int) { GTUIterator<T> tmp(*this); --(*this); return tmp; }