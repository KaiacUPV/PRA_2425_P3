#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2425_P1/ListLinked.h"  

template <typename V>
class HashTable: public Dict<V>{

    private:
        int n;
        int max;
        ListLinked<TableEntry<V>>* table;

        int h(std::string key){
            int val_ascii = 0;
            for(int i = 0; i < key.size(); i++ ){
                val_ascii += int(key.at(i));
            }
            int pos = val_ascii % max;
            return pos;
        }


    public:
        HashTable(int size){
            new ListLinked<T>* table[size];
            n = 0;
            max = size;
        }

        ~HashTable(){
            delete [] table;
        }

        void insert(std::string key, V value) override{
            TableEntry par_keyval = TableEntry(key, value);
            
        }

        V search(std::string key) override; 
        V remove(std::string key) override;

        int entries() override{
            return n;
        }
        
        
};

#endif