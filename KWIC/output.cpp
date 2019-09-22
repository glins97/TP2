#include "output.hpp"

void printList(list<string> l){
    auto it = l.begin();
    for (int i; i < l.size(); i++){
        cout << "[" << i + 1 << "] -> " << *next(it, i);
    }
    cout << endl;
}

void printTitles(list<list<string>> titles){
    for (auto title: titles){
        cout << '\t';
        printList(title);
    }
    cout << endl;
}