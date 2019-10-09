#pragma once
using namespace std;

#include "baseoutput.hpp"

class TextOutputManager: public BaseOutputManager{
    public:
    void dump(list<list<string>> titles);
};

