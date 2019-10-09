#pragma once
using namespace std;

#include <algorithm>
#include <string>
#include <list>
#include <iostream>

class ShifterManager{
    public:
    virtual list<list<string>> shift(list<list<string>> titles){ return list<list<string>>(); };
};

#include "nswshift.hpp"
#include "swshift.hpp"