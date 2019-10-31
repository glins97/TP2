#pragma once
using namespace std;

#include <string>
#include "../expr/neg.hpp"
#include "neg.hpp"
#include "evaluator.hpp"

class EvaluatorVisitorNeg: public NegExprVisitor, public EvaluatorVisitor {
public:
  void VisitNeg(Neg* neg) {
    neg->GetLhs()->Accept(this);
    neg->GetRhs()->Accept(this);
    _values[neg] = _values[(neg->GetLhs())] - _values[(neg->GetRhs())];
  }
};