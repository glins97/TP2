#pragma once
using namespace std;

#include <iostream>
#include <string>
#include <list>

class OutputManager{
    public:
    virtual void dump(list<list<string>> titles){};
};


class PrintOutputManager: public OutputManager{
    public:
    void dump(list<list<string>> titles);
    void printList(list<string> l);
    void printTitles(list<list<string>> titles);
};
