#pragma once
using namespace std;

#include <string>

class Literal;
class ExprVisitor{
public:
  virtual void VisitLiteral(Literal* literal) = 0;
};