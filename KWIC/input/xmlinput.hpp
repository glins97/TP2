#pragma once
using namespace std;

#include "baseinput.hpp"

class XMLInputManager: public BaseInputManager{
    public:
    char* filename;
    list<list<string>> load();
    XMLInputManager(char* filename);
};
