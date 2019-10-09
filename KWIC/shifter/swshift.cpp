#include "swshift.hpp"

list<list<string>> StopWordsShifterManager::shift(list<list<string>> titles){
    auto res = list<list<string>>();
    for (auto title: titles){
        for (auto shifted: shiftTitle(title)){
            res.push_front(shifted);    
        }
    }
    cout << "StopWordsShifterManager shift" << endl;
    return res;
}

list<list<string>> StopWordsShifterManager::shiftTitle(list<string> title){
    auto res = list<list<string>>();
    auto newTitle = list<string>(title);
    for (int i = 0; i < newTitle.size(); i++){
        auto back = newTitle.back();
        if (this->in(back, this->sw)) 
            continue;
        newTitle.pop_back();
        newTitle.push_front(back);
        res.push_front(newTitle);
    }
    return res;
}

StopWordsShifterManager::StopWordsShifterManager(list<string> sw){
    this->sw = list<string>(sw);
};

template <class T>
bool StopWordsShifterManager::in(T obj, list<T> collection){
    for (T item: collection)
        if (item == obj)
            return true;
    return false;
}
