#ifndef LISTITEMHEADERINT
#define LISTITEMHEADERINT

#include <string>

class ListItemInt {
  
    public:
        ListItemInt * next = 0;
        
        ListItemInt(int value);

        int value;
        int count(int parents);
        void clear();
        int get(int index, int parents);
        void remove(int index, int parents);
        void insert(int index, int parents, int value);
        void add(int value);
        std::string toString();
};

#endif