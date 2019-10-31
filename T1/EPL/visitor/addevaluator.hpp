#pragma once
using namespace std;

#include <string>
#include "../expr/add.hpp"
#include "add.hpp"
#include "evaluator.hpp"

class EvaluatorVisitorAdd: public AddExprVisitor, public EvaluatorVisitor {
public:
  void VisitAdd(Add* add) {
    add->GetLhs()->Accept(this);
    add->GetRhs()->Accept(this);
    _values[add] = _values[(add->GetLhs())] + _values[(add->GetRhs())];
  }
};