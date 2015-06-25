#ifndef LISTITEMINT
#define LISTITEMINT

#include <string>

#include "ListItemInt.h"

    ListItemInt::ListItemInt(int value)
    {
        this->value = value;
    }

    ListItemInt::~ListItemInt(){

    }

    int ListItemInt::count(int parents)
    {
        if(next != 0)
            return next->count(parents + 1) + 1;
        else
            return 1;
    }

    void ListItemInt::clear()
    {
        if(next != 0)
            next->clear();
        
        delete(next);
        next = 0;
    }

    int ListItemInt::get(int index, int parents)
    {
        if(index == parents)
            return value;
        
        if(next != 0)
            return next->get(index, parents + 1);
        
        //Out of range
        throw;
    }

    void ListItemInt::remove(int index, int parents)
    {
        if(next != 0)
        {
            if(parents + 1 == index)
            {
                if(next->next != 0)
                {
                    ListItemInt * newNext = next->next;
                    delete(next);
                    next = newNext;
                }
                else
                {
                    delete(next);
                    next = 0;
                }
            }
            else
                next->remove(index, parents + 1);
        }
        else
        {
            //Out of range
            throw;
        }
    }

    void ListItemInt::insert(int index, int parents, int value)
    {
        if(next != 0)
        {
            if(parents + 1 == index)
            {
                ListItemInt * oldNext = next;
                next = new ListItemInt(value);
                next->next = oldNext;
            }
            else
                next->insert(index, parents + 1, value);
        }
        else
        {
            if(parents + 1 == index)
            {
                next = new ListItemInt(value);
            }
            else
            {
                //Out of range
                throw;
            }
        }
    }

    void ListItemInt::add(int value)
    {
        if(next != 0)
            next->add(value);
        else
        {
            next = new ListItemInt(value);
        }
    }

    std::string ListItemInt::toString()
    {   
        if(next != 0)
            return std::to_string(value) + " " + next->toString();
        else
            return std::to_string(value);
    }

#endif
