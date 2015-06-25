#ifndef INTERATORHEADERINT
#define INTERATORHEADERINT

#include <string>
#include "ListItemInt.h"

class IteratorInt {
    private:
        int index = 0;
        ListItemInt * item = 0;
    
    public:
        IteratorInt(ListItemInt * item);
        bool hasNext();
        int getIndex();
        int getNext();
        int getValue();
};

#endif