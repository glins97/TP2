#pragma once
using namespace std;

#include <algorithm>
#include <string>
#include <list>

class ShifterManager{
    public:
    virtual list<list<string>> shift(list<list<string>> titles){ return list<list<string>>(); };
};

class RightShifterManager: public ShifterManager{
    public:
    list<list<string>> shift(list<list<string>> titles);
    list<list<string>> shiftTitle(list<string> title);

};

class LeftShifterManager: public ShifterManager{
    public:
    list<list<string>> shift(list<list<string>> titles);
    list<list<string>> shiftTitle(list<string> title);

};
