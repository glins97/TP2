#pragma once
using namespace std;

#include "base.hpp"

class LiteralExp: public ExpBase{
    bool identify(string expression);
};