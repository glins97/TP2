#pragma once
using namespace std;

#include "../visitor/expr.hpp"
#include <string>

class ExprBase {
public:
  virtual void Accept(ExprVisitor* visitor) = 0;
};