#include "nswalphabetizer.hpp"

list<list<string>> NSWAlphabetizerManager::sort(list<list<string>> titles){
    auto res = list<list<string>>();
    while(titles.size()){
        auto title = this->getLowestValueTitle(titles);
        res.push_back(title);
        titles.remove(title);
    }
    return res;
}
