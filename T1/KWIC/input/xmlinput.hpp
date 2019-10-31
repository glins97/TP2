#pragma once
using namespace std;

#include "baseinput.hpp"

class XMLInputManager: public BaseInputManager{
    public:
    string filename;
    list<list<string>> load();
    XMLInputManager(string filename);
};
