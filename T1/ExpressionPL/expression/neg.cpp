#include "neg.hpp"
#include "iostream"

int NegExp::identify(string expression){
    int index = 0;
    for (auto chr: expression){
        if (chr == '-')
            return index;
        index++;
    }
    return -1;
}

int NegExp::eval(string lexp, string rexp, int lv, int rv){
    return lv - rv;
}
