# pragma once 

#include <iostream>
using namespace std;

namespace itertools {

    template <typename functor, typename container>
    class filterfalse {

        functor func;
        container cont;
        
        public:
            filterfalse(functor f, container c) : func(f), cont(c) {}

        class iterator {
            typename container::iterator current;
            typename container::iterator end;
            functor bool_func;

            public:
                iterator(typename container::iterator s, typename container::iterator e, functor f)
                 : current(s), end(e), bool_func(f) {
                     while(current != end && bool_func(*current))
                        ++current;
                 }

                auto operator*() const {
                    return *current;
                }

                iterator& operator++() {
                    ++current;
                    while(current != end && bool_func(*current)) // while the current element of the container satisfies the condition
                        ++current;
                    return *this;
                }

                const iterator operator++(int) {
                    iterator temp = *this;
                     ++current;
                    while(current != end && bool_func(*current)) // while the current element of the container satisfies the condition
                        ++current;
                    return temp;
                }

                bool operator==(const iterator& it) const {return current == it.current;}

                bool operator!=(const iterator& it) const {return current != it.current;}

        };

        iterator begin() {
            return iterator{cont.begin(), cont.end(), func};
        }

        iterator end() {
            return iterator{cont.end(), cont.end(), func};
        }
    };
}