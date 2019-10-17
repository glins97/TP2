#pragma once
using namespace std;

#include "basealphabetizer.hpp"

class CrappyAlphabetizerManager: public BaseAlphabetizerManager{
    public:
    list<list<string>> sort(list<list<string>> titles);
};
