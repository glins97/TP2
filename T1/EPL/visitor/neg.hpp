#pragma once
using namespace std;

#include <string>
#include "expr.hpp"
#include "../expr/neg.hpp"

class Neg;
class NegExprVisitor: virtual public ExprVisitor {
public:
  virtual void VisitNeg(Neg* neg) = 0;
};