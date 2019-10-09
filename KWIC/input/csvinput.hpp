#pragma once
using namespace std;

#include "input.hpp"

class CSVInputManager: public InputManager{
    public:
    char* filename;
    list<list<string>> load();
    CSVInputManager(char* filename);
};
