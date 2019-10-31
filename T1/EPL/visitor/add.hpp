#pragma once
using namespace std;

#include <string>
#include "expr.hpp"
#include "../expr/add.hpp"

class Add;
class AddExprVisitor: virtual public ExprVisitor {
public:
  virtual void VisitAdd(Add* add) = 0;
};