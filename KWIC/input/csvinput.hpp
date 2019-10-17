#pragma once
using namespace std;

#include "baseinput.hpp"

class CSVInputManager: public BaseInputManager{
    public:
    string filename;
    list<list<string>> load();
    CSVInputManager(string filename);
};
