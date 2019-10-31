#pragma once
using namespace std;

#include <iostream>
#include "base.hpp"
#include "../visitor/neg.hpp"

class Neg: public ExprBase {
public:
  void Accept(ExprVisitor* visitor) {
    auto visitor_ = dynamic_cast<NegExprVisitor*>(visitor);
    visitor_->VisitNeg(this);
  }

  Neg(ExprBase* lhs, ExprBase* rhs);
  string ToString();
  double Eval();

  ExprBase* GetLhs() const {
    return _lhs;
  }

  ExprBase* GetRhs() const {
    return _rhs;
  }
  
private:
  ExprBase* _lhs;
  ExprBase* _rhs;
};