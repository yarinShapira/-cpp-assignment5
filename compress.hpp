# pragma once 

namespace itertools {

    template <typename container, typename bool_container>
    class compress {
        container cont;
        bool_container bool_cont;


        public:
            compress(container c, bool_container bc) : cont(c), bool_cont(bc) {}

        class iterator {
            typename container::iterator current;
            typename bool_container::iterator bool_current;
            typename container::iterator end;
            typename bool_container::iterator bool_end;
            //compress* comp;

            public:
                iterator(typename container::iterator c,typename container::iterator e, typename bool_container::iterator bc, typename bool_container::iterator be)
                 : current(c), bool_current(bc), end(e), bool_end(be) {
                     while(bool_current != bool_end && current != end && !(*bool_current)){
                        ++current;
                        ++bool_current;
                    }
                }

                
                auto operator*() const {return *current;}

                iterator& operator++() {
                    ++current;
                    ++bool_current;
                    while(bool_current != bool_end && current != end && !(*bool_current)){
                        ++current;
                        ++bool_current;
                    }
                    return *this;
                }

                const iterator operator++(int) {
                    iterator temp = *this;
                    ++current;
                    ++bool_current;
                    while(bool_current != bool_end && current != end && !(*bool_current)){
                        ++current;
                        ++bool_current;
                    }
                    return temp;
                }

                bool operator==(const iterator& it) const {return current==it.current && bool_current==it.bool_current;}

                bool operator!=(const iterator& it) const {return current!=it.current && bool_current!=it.bool_current;}

        };

        iterator begin() {
            return iterator{cont.begin(), cont.end(), bool_cont.begin(), bool_cont.end()};
        }

        iterator end() {
            return iterator{cont.end(),cont.end(), bool_cont.end(), bool_cont.end()};
        }
    };
}