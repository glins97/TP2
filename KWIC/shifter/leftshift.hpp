#pragma once
using namespace std;

#include "shift.hpp"

class LeftShifterManager: public ShifterManager{
    public:
    list<list<string>> shift(list<list<string>> titles);
    list<list<string>> shiftTitle(list<string> title);

};
