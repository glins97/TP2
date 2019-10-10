#pragma once
using namespace std;

#include <vector>
#include <string>

class ExpBase{
    public:
    virtual int eval(string lexp, string rexp, int lv, int rv){return 0;};
    virtual int identify(string expression){return false;};
    virtual void get_splits(string input, string* left_input, string* right_input);

};

#include "base.hpp"
#include "literal.hpp"
#include "add.hpp"