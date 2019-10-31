#pragma once
using namespace std;

#include "baseinput.hpp"

class CSVInputManager: public BaseInputManager{
    public:
    string filename;
    list<list<string>> load();
    list<string> _loadFile(string filename);
    CSVInputManager(string filename);
};
