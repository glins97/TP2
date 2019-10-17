#pragma once
using namespace std;

#include "baseinput.hpp"

class TextInputManager: public BaseInputManager{
    public:
    string filename;
    list<list<string>> load();
    TextInputManager(string filename);
};
