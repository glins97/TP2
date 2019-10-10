#include "literal.hpp"
#include "iostream"

int LiteralExp::identify(string expression){
    string numbers = "0123456789";

    if (expression == "" || expression == " ") return -1;
    int index = 0;
    for (auto chr: expression){
        bool nan = true;
        if (chr == ' '){
            index++;
            continue;
        }
        for (auto n: numbers){
            if (chr == n) 
                nan = false; 
        }
        if (nan) return -1;
    }
    return index;
}

int LiteralExp::eval(string lexp, string rexp, int lv, int rv){
    return stoi(lexp) + stoi(rexp);
}
