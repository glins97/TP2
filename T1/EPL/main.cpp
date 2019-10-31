#include "expr/neg.hpp"
#include "expr/add.hpp"
#include "expr/literal.hpp"
#include "visitor/printer.hpp"
#include "visitor/evaluator.hpp"
#include "visitor/addevaluator.hpp"
#include "visitor/negevaluator.hpp"

#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
  auto l1 = new Literal(1.25);
  auto l2 = new Literal(2.00);

  auto a1 = new Add(l1, l2);
  auto a2 = new Add(l1, a1);
  auto n1 = new Neg(l1, l2);

  auto e1 = new EvaluatorVisitor;
  auto e2 = new EvaluatorVisitorAdd;
  auto e3 = new EvaluatorVisitorNeg;
  auto e4 = new PrinterVisitor;

  a2->Accept(e2);
  // a2->Accept(e4);
  cout << e2->GetValue(a1) << endl;
  // cout << e4->GetValue(a2) << endl;
  // std::unique_ptr<ExprBase> c2(new Literal(2.2));

  // std::unique_ptr<Expr> fc(new FunctionCall("foo", *c1));
  // std::unique_ptr<Expr> p2(new BinaryPlus(*fc, *c2));

  // EvaluatorWithFunctionCall e;
  // p2->Accept(&e);
  // std::cout << e.GetValueForExpr(*p2) << "\n";

  return 0;
}
