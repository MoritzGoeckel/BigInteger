#ifndef LISTINT
#define LISTINT

#include <string>

#include "ListInt.h"
#include "ListItemInt.h"

#include <iostream>

        ListInt::~ListInt(){
            clear();
        }

        void ListInt::add(int value)
        {    
            if(root != 0)
                root->add(value);
            else
                root = new ListItemInt(value);
        }

        void ListInt::insert(int value, int index){
            if(index != 0)
                root->insert(index, 0, value);
            else
            {
                ListItemInt * oldRoot = root;
                root = new ListItemInt(value);
                root->next = oldRoot;
            }
        }

        void ListInt::remove(int index){
            if(index == 0)
            {
                if(root->next != 0)
                {
                    ListItemInt * oldRoot = root;
                    root = root->next;
                    delete(oldRoot);
                }
                else
                    delete(root);
            }
            else
                root->remove(index, 0);
        }

        int ListInt::get(int index){
            return root->get(index, 0);
        }

        void ListInt::clear(){
            if(root != 0)
            {
                root->clear();
                delete(root);
                root = 0;
            }
        }

        int ListInt::count(){
            if(root != 0)
                return root->count(0);
            else
                return 0;
        }

        void ListInt::print(){
            std::cout << this->toString() << std::endl;
        }

        std::string ListInt::toString(){
            if(root != 0)
                return root->toString();
            else
                return "NULL";
        }

        IteratorInt *ListInt::getIterator(){
            return new IteratorInt(root);
        }

#endif
