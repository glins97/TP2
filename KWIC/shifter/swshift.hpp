#pragma once
using namespace std;

#include "baseshift.hpp"

class StopWordsShifterManager: public ShifterManager{
    public:
    list<string> sw;
    list<list<string>> shift(list<list<string>> titles);
    list<list<string>> shiftTitle(list<string> title);
    StopWordsShifterManager(list<string> sw);
    template <class T>
    bool in(T obj, list<T> collection);
};
