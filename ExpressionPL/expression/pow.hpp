#pragma once
using namespace std;

#include "base.hpp"

class PowExp: public ExpBase{
    string get_op(){ return "^"; }
    int identify(string expression);
    int eval(string lexp, string rexp, int lv, int rv);
};