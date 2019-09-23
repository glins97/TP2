#include "alphabetizer.hpp"

list<string> compareTitles(list<string> a, list<string> b){
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
        {
            return a;
        }
        
    }

    return base;
}

list<string> getLowestValueTitle(list<list<string>> titles){
    auto lowest = titles.front();
    for (auto title: titles){
        lowest = compareTitles(lowest, title);
    }
    return lowest;
}

list<list<string>> sortTitles(list<list<string>> titles){
    auto res = list<list<string>>();
    while(titles.size()){
        auto title = getLowestValueTitle(titles);
        res.push_back(title);
        titles.remove(title);
    }
    return res;
}


