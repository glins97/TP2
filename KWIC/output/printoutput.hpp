#pragma once
using namespace std;

#include "output.hpp"

class PrintOutputManager: public OutputManager{
    public:
    void dump(list<list<string>> titles);
    void printList(list<string> l);
    void printTitles(list<list<string>> titles);
};

