#pragma once
using namespace std;

#include "baseinput.hpp"

class SQLInputManager: public BaseInputManager{
    public:
    list<list<string>> load();
};
