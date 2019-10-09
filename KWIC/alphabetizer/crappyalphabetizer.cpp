#include "crappyalphabetizer.hpp"

list<list<string>> CrappyAlphabetizerManager::sort(list<list<string>> titles){
    auto res = list<list<string>>();
    while(titles.size()){
        auto title = this->getLowestValueTitle(titles);
        res.push_back(title);
        titles.remove(title);
    }

    cout << "CrappyAlphabetizerManager sort" << endl;
    return res;
}
