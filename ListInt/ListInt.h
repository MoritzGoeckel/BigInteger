#ifndef LISTHEADERINT
#define LISTHEADERINT

#include "ListItemInt.h"
#include "IteratorInt.h"
#include <string>

class ListItemInt;

class ListInt {
  
    private:
        ListItemInt * root = 0;
    
    public:
        void add(int value);
        void insert(int value, int index);
        void remove(int index);
        int get(int index);
        void clear();
        int count();
        void print();
        std::string toString();
        IteratorInt * getIterator();
};

#endif