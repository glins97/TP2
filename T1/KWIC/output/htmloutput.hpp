#pragma once
using namespace std;

#include "baseoutput.hpp"

class HTMLOutputManager: public BaseOutputManager{
    public:
    void dump(list<list<string>> titles);
};

