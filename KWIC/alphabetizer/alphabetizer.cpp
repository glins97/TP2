#include "alphabetizer.hpp"

list<string> AlphabetizerManager::getLowestValueTitle(list<list<string>> titles){
    auto lowest = titles.front();
    for (auto title: titles){
        lowest = this->compareTitles(lowest, title);
    }
    return lowest;
}

list<string> AlphabetizerManager::compareTitles(list<string> a, list<string> b){
    if (a == b)
        return a;

    auto base = a;
    auto size = a.size();
    auto sizeB = b.size();
    if (sizeB < size){
        size = b.size();
        base = b;
    }
    
    auto aIt = a.begin();
    auto bIt = b.begin();
    for (int i = 0; i < size; i++){
        auto aWord = (*next(aIt, i));
        auto bWord = (*next(bIt, i));
        if (bWord < aWord)
            return b;
        else if (aWord < bWord)
            return a;
        
    }

    return base;
}