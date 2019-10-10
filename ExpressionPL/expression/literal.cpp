#include "literal.hpp"

bool LiteralExp::identify(string expression){
    string numbers = "0123456789";
    for (auto chr: expression){
        for (auto n: numbers)
            if (chr != n) return false; 
    }
    return true;
}
