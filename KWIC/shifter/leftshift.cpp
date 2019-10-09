#include "leftshift.hpp"

list<list<string>> LeftShifterManager::shift(list<list<string>> titles){
    auto res = list<list<string>>();
    for (auto title: titles){
        for (auto shifted: shiftTitle(title)){
            res.push_front(shifted);    
        }
    }
    return res;
}

list<list<string>> LeftShifterManager::shiftTitle(list<string> title){
    auto res = list<list<string>>();
    auto newTitle = list<string>(title);
    for (int i = 0; i < newTitle.size(); i++){
        auto back = newTitle.back();
        newTitle.pop_back();
        newTitle.push_front(back);
        res.push_front(newTitle);
    }
    return res;
}
