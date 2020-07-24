# pragma once 

namespace itertools {
    
    class range{
       
        int last, first;
        public:
            //range() {}
            range(int x, int y) : first(x), last(y) {}


        class iterator {
            int val;

            public:
                iterator(int r) : val(r) {}

                int operator*() const { return val; }
                //++i
                iterator& operator++() {
                    val++;
                    return *this;
                }

                // i++
                const iterator operator++(int) {
                    iterator temp = *this;
                    val++;
                    return temp;
                }

                bool operator==(const iterator& it) const {
                    return val == *it;
                }

                bool operator!=(const iterator& it) const {
                    return val != *it;
                }
        };

        iterator begin() const {
            return iterator{this->first};
        }

        iterator end() const  {
            return iterator{this->last};
        }
    };
}