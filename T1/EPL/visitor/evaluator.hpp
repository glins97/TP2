#pragma once
using namespace std;

#include <string>
#include <map>
#include "../expr/literal.hpp"
#include "../expr/add.hpp"
#include "expr.hpp"

#include <iostream>

class EvaluatorVisitor: public virtual ExprVisitor{
public:
  std::map<ExprBase*, double> _values;
  double GetValue(ExprBase* e) {
    return _values[e];
  }

  void VisitLiteral(Literal* l) {
    _values[l] = l->GetValue();
  }
};