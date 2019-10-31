#pragma once
using namespace std;

#include <iostream>
#include "base.hpp"
#include "../visitor/printer.hpp"
#include "../visitor/expr.hpp"
#include "../visitor/add.hpp"

class Add: public ExprBase {
public:
  void Accept(ExprVisitor* visitor) {
    auto visitor_ = dynamic_cast<AddExprVisitor*>(visitor);
    if (visitor_ != nullptr){
      visitor_->VisitAdd(this);
      return;
    } 

    auto p = new PrinterVisitor;
    // auto visitor2_ = dynamic_cast<PrinterVisitor*>(visitor);
    // if (visitor2_ != nullptr) 
    //   visitor2_->VisitAdd(this);
  }

  Add(ExprBase* lhs, ExprBase* rhs);
  ExprBase* GetLhs() const {
    return _lhs;
  }

  ExprBase* GetRhs() const {
    return _rhs;
  }
  
private:
  ExprBase* _lhs;
  ExprBase* _rhs;
};