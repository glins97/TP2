#include "printoutput.hpp"

void PrintOutputManager::dump(list<list<string>> titles){
    cout << "PrintOutputManager dump" << endl;    
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
