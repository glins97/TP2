#pragma once
using namespace std;

#include "base.hpp"

class NegExp: public ExpBase{
    int identify(string expression);
    int eval(string lexp, string rexp, int lv, int rv);
};