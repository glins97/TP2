#include "output.hpp"

void printList(list<string> l){
    auto it = l.begin();
    cout << "[";
    for (int i; i < l.size(); i++){
        cout << "'" << *next(it, i) << "', ";
    }
    cout << "]" << endl;
}

void printTitles(list<list<string>> titles){
    for (auto title: titles){
        printList(title);
    }
    cout << endl;
}