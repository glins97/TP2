#include "mul.hpp"
#include "iostream"

int MulExp::identify(string expression){
    int index = 0;
    for (auto chr: expression){
        if (chr == '*')
            return index;
        index++;
    }
    return -1;
}

int MulExp::eval(string lexp, string rexp, int lv, int rv){
    return lv * rv;
}
