#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {
    private:
        BSTree<TableEntry<V>>* tree; 

    public:
        BSTreeDict(): tree(new BSTree<TableEntry<V>>()){};

        ~BSTreeDict(){
            delete tree;
        }
        
        void insert(std::string key, V value) override{
            TableEntry<V> entry(key, value); // Crea una entrada
            tree->insert(entry); // Inserta en el ABB
        }

        V search(std::string key) override{
            TableEntry<V> entry(key); 
            TableEntry<V> found = tree->search(entry); 
            return found.value; 
        }

        V remove(std::string key) override{
            TableEntry<V> entry(key); 
            TableEntry<V> found = tree->search(entry); 
            tree->remove(entry); 
            return found.value; 
        }
        
        int entries() override{
            return tree->size(); 
        }

         friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs) {
        out << *bs.tree; // Delegar al operador << de BSTree<TableEntry<V>>
        return out;
    }

        V operator[](std::string key){
            return search(key); 
        }        

};

#endif