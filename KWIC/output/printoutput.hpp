#pragma once
using namespace std;

#include "baseoutput.hpp"

class PrintOutputManager: public BaseOutputManager{
    public:
    void dump(list<list<string>> titles);
    void printList(list<string> l);
    void printTitles(list<list<string>> titles);
};

