#pragma once
using namespace std;

#include "baseinput.hpp"

class DBLPInputManager: public BaseInputManager{
    public:
    list<list<string>> load();
};
