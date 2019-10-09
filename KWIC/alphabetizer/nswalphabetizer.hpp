#pragma once
using namespace std;

#include "basealphabetizer.hpp"

class NSWAlphabetizerManager: public AlphabetizerManager{
    public:
    list<list<string>> sort(list<list<string>> titles);
};
