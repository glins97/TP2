#pragma once
using namespace std;

#include "alphabetizer.hpp"

class NSWAlphabetizerManager: public AlphabetizerManager{
    public:
    list<list<string>> sort(list<list<string>> titles);
};
