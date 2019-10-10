#pragma once
using namespace std;

#include <vector>
#include <string>

class ExpBase{
    public:
    string op;
    virtual bool identify(string expression){return false;};
};

#include "base.hpp"
#include "literal.hpp"
#include "add.hpp"