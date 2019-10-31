#include "neg.hpp"

Neg::Neg(ExprBase* lhs, ExprBase* rhs){
    this->_lhs = lhs;
    this->_rhs = rhs;
}
