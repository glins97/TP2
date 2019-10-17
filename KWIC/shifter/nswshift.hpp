#pragma once
using namespace std;

#include "baseshift.hpp"

class NoStopWordsShifterManager: public BaseShifterManager{
    public:
    list<list<string>> shift(list<list<string>> titles);
    list<list<string>> shiftTitle(list<string> title);

};
