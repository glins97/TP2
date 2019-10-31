#include "nswshift.hpp"

list<list<string>> NoStopWordsShifterManager::shift(list<list<string>> titles){
    auto res = list<list<string>>();
    for (auto title: titles){
        for (auto shifted: shiftTitle(title)){
            res.push_back(shifted);    
        }
    }

    cout << "NoStopWordsShifterManager shift" << endl;
    return res;
}

list<list<string>> NoStopWordsShifterManager::shiftTitle(list<string> title){
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
