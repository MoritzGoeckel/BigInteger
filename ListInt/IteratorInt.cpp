#ifndef ITERATORINT
#define ITERATORINT

    #include <string>
    #include "ListItemInt.h"
    #include "IteratorInt.h"

    IteratorInt::IteratorInt(ListItemInt * item){
        this->item = item;   
    }
    
    bool IteratorInt::hasNext(){
        return item != 0;
    }
    
    int IteratorInt::getIndex(){
        return this->index;
    }

    int IteratorInt::getNext(){
        if(item == 0)
            return 0;

        int output = item->value;
        
        if(this->item->next != 0)
        {
            this->index++;
            this->item = item->next;
        }
        else
            item = 0;
        
        return output;
    }

    int IteratorInt::getValue(){
        return item->value;   
    }

#endif