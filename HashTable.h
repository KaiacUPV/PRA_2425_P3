#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "../PRA_2425_P1/ListLinked.h"  

using namespace std;


template <typename V>
class HashTable: public Dict<V>{
       private:
        int n;
        int max;
        ListLinked<TableEntry<V>>* table;

        int h(string key){
            int val_ascii = 0;
            for(int i = 0; i < key.size(); i++ ){
                val_ascii += int(key.at(i));
            }
            int pos = val_ascii % max;
            return pos;
        }


    public:
        
        HashTable(int size): n(0), max(size){
            table = new ListLinked<TableEntry<V>> [size];
        }

        ~HashTable(){
            delete [] table;
        }

        int capacity(){
            return max;
        }

        friend ostream& operator<<(ostream &out, 
        const HashTable<V> &th){
            for(int i = 0; i < th.max; i++){
                out <<  "Posición " << i <<" : "  << th.table[i] << endl;
                
            }
            return out;
        }


        V operator[](string key){
             int pos = h(key);
              for(int i = 0; i < table[pos].size(); i++){  
                if(table[pos].get(i).key == key){    
                    return table[pos].get(i).value;
                }
            }

            throw std::runtime_error("");
        }


        //heredados de Dict<V>
        void insert(string key, V value) override{
            TableEntry<V> entrada = TableEntry(key, value);
            int pos = h(key);
            for(int i = 0; i < table[pos].size(); i++){  
                if(table[pos].get(i).key == key){ 
                    throw std::runtime_error("");
                }
            }

            table[pos].prepend(entrada);  //añadimos el elemento al principio porque el orden no importa 
            n++;           
        }

 
        V search(string key) override{
            return operator[](key);
        }

        V remove(string key) override{
            int pos = h(key);
            for(int i = 0; i < table[pos].size(); i++){  
                if(table[pos].get(i).key == key){    
                    V valor = table[pos].get(i).value;
                    table[pos].remove(i);
                    n--;
                    return valor;
                }
            }

            throw std::runtime_error("");

        }

        int entries() override{
            return n;
        }
        

};

#endif