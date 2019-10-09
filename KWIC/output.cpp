#include "output.hpp"


void PrintOutputManager::dump(list<list<string>> titles){
    printTitles(titles);
}

void PrintOutputManager::printTitles(list<list<string>> titles){
    for (auto title: titles){
        this->printList(title);
    }
    cout << endl;
}

void PrintOutputManager::printList(list<string> l){
    auto it = l.begin();
    cout << "[";
    for (int i; i < l.size(); i++){
        cout << "'" << *next(it, i) << "', ";
    }
    cout << "]" << endl;
}
