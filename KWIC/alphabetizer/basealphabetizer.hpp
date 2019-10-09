#pragma once
using namespace std;

#include <iostream>
#include <string>
#include <list>

class AlphabetizerManager{
    public:
    virtual list<list<string>> sort(list<list<string>> titles){ return list<list<string>>(); };
    list<string> getLowestValueTitle(list<list<string>> titles);
    list<string> compareTitles(list<string> a, list<string> b);
};

#include "crappyalphabetizer.hpp"
#include "quickalphabetizer.hpp"