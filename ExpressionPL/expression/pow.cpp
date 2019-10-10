#include "pow.hpp"
#include "iostream"

#include <math.h>

int PowExp::identify(string expression){
    int index = 0;
    for (auto chr: expression){
        if (chr == '^')
            return index;
        index++;
    }
    return -1;
}

int PowExp::eval(string lexp, string rexp, int lv, int rv){
    return pow(lv, rv);
}
