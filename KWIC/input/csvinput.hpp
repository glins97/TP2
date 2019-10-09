#pragma once
using namespace std;

#include "baseinput.hpp"

class CSVInputManager: public BaseInputManager{
    public:
    char* filename;
    list<list<string>> load();
    CSVInputManager(char* filename);
};
