#include "add.hpp"

bool AddExp::identify(string expression){
    for (auto chr: expression){
        if (chr == this->op[0])
            return true;
    }
    return false;
}
