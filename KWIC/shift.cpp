#include "shift.hpp"

list<list<string>> shiftTitle(list<string> title){
    auto res = list<list<string>>();
    auto newTitle = list<string>(title);
    for (int i = 0; i < newTitle.size(); i++){
        auto front = newTitle.front();
        newTitle.pop_front();
        newTitle.push_back(front);
        res.push_back(newTitle);
    }
    return res;
}

list<list<string>> shiftTitles(list<list<string>> titles){
    auto res = list<list<string>>();
    for (auto title: titles){
        for (auto shifted: shiftTitle(title)){
            res.push_back(shifted);    
        }
    }
    return res;
}
