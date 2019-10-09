#pragma once
using namespace std;

#include "baseinput.hpp"

class CSVInputManager: public InputManager{
    public:
    char* filename;
    list<list<string>> load();
    CSVInputManager(char* filename);
};
