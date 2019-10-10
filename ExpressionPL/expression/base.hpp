#pragma once
using namespace std;

#include <vector>
#include <string>

class ExpBase{
    public:
    virtual int eval(string lexp, string rexp, int lv, int rv){return 0;};
    virtual int identify(string expression){return false;};
};

#include "base.hpp"
#include "literal.hpp"
#include "add.hpp"