#pragma once
using namespace std;

#include "alphabetizer.hpp"

class SWAlphabetizerManager: public AlphabetizerManager{
    public:
    list<list<string>> sort(list<list<string>> titles);
};
