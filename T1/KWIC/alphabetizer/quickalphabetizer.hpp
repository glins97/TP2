#pragma once
using namespace std;

#include "basealphabetizer.hpp"

class QuickAlphabetizer: public BaseAlphabetizerManager{
    public:
    list<list<string>> sort(list<list<string>> titles);
};
