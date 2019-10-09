#pragma once
using namespace std;

#include "input.hpp"

class TextInputManager: public InputManager{
    public:
    char* filename;
    list<list<string>> load();
    TextInputManager(char* filename);
};
