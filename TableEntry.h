#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

using namespace std;

template <typename V> 
class TableEntry{
    public:
    //atributos
    string key;
    V value;

    //constructores
    TableEntry(string key, V value) : key(key), value(value) {}
    TableEntry(string key) : key(key), value(V{}) {}
    TableEntry() : key(""), value(V{}) {}

    //sobrecargda de ops
    friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
        return te1.key == te2.key;
    }

    friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return !(te1 == te2); // Basada en la implementación de ==
    }

    friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){
        out << "{" << te.key << " -> " << te.value << "}" << endl;
        return out;
    }

};

#endif