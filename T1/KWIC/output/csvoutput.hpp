#pragma once
using namespace std;

#include "baseoutput.hpp"

class CSVOutputManager: public BaseOutputManager{
    public:
    void dump(list<list<string>> titles);
};

