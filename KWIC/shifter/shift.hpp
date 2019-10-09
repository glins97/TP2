#pragma once
using namespace std;

#include <algorithm>
#include <string>
#include <list>

class ShifterManager{
    public:
    virtual list<list<string>> shift(list<list<string>> titles){ return list<list<string>>(); };
};

#include "rightshift.hpp"
#include "leftshift.hpp"