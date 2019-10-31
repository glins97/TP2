#pragma once
using namespace std;

#include "baseoutput.hpp"

class XMLOutputManager: public BaseOutputManager{
    public:
    void dump(list<list<string>> titles);
};

