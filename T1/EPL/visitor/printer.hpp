#pragma once
using namespace std;

#include <string>
#include <map>
#include "../expr/literal.hpp"

class PrinterVisitor: public virtual ExprVisitor{
public:
  std::map<ExprBase*, string> _values;
  string GetValue(ExprBase* e) {
    return _values[e];
  }

  void VisitLiteral(Literal* l) {
    _values[l] = to_string(l->GetValue());
  }
};