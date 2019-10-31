#pragma once
using namespace std;

#include <iostream>
#include "base.hpp"

class Literal: public ExprBase {
public:
  
  void Accept(ExprVisitor* visitor) {
    visitor->VisitLiteral(this);
  }

  Literal(double value);
  string ToString();
  double Eval();
  double GetValue(){ return _value; };

private:
  double _value;
};