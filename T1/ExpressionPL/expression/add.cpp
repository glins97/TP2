#include "add.hpp"
#include "iostream"

int AddExp::identify(string expression){
    int index = 0;
    for (auto chr: expression){
        if (chr == '+')
            return index;
        index++;
    }
    return -1;
}

int AddExp::eval(string lexp, string rexp, int lv, int rv){
    return lv + rv;
}
