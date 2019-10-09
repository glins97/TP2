#pragma once
using namespace std;

#include "baseshift.hpp"

class StopWordsShifterManager: public ShifterManager{
    public:
    list<list<string>> shift(list<list<string>> titles);
    list<list<string>> shiftTitle(list<string> title);

};
