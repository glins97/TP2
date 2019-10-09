#pragma once
using namespace std;

#include <iostream>
#include <string>
#include <list>

class OutputManager{
    public:
    virtual void dump(list<list<string>> titles){};
};

#include "printoutput.hpp"