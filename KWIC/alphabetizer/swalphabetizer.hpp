#pragma once
using namespace std;

#include "basealphabetizer.hpp"

class SWAlphabetizerManager: public AlphabetizerManager{
    public:
    list<list<string>> sort(list<list<string>> titles);
};
