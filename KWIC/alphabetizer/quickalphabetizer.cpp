#include "quickalphabetizer.hpp"

list<list<string>> QuickAlphabetizer::sort(list<list<string>> titles){
    auto res = list<list<string>>();
    while(titles.size()){
        auto title = this->getLowestValueTitle(titles);
        res.push_back(title);
        titles.remove(title);
    }

    cout << "QuickAlphabetizerManager sort" << endl;
    return res;
}
