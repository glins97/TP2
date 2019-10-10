#pragma once
using namespace std;

#include "base.hpp"

class AddExp: public ExpBase{
    string op = "+";
    bool identify(string expression);
};