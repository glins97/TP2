#pragma once
using namespace std;

#include "base.hpp"

class LiteralExp: public ExpBase{
    public:
    int identify(string expression);
    int eval(string lexp, string rexp, int lv, int rv);
    void get_splits(string input, string* left_input, string* right_input);
};