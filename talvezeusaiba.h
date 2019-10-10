#pragma once

#include <iostream>

class Exp
{
 public:
 virtual void print() = 0;
 virtual int eval() = 0;
};
class Add : public Exp
{
 public:
 Exp *left, *right;
 virtual ~Add()
 {
	 delete left;
	 delete right;
 }

 Add(Exp *l, Exp *r);
 void print() override;
 int eval() override;
};
class Neg : public Exp
{
 public:
 Exp *expr;
 virtual ~Neg()
 {
	 delete expr;
 }

 Neg(Exp *e);
 void print() override;
 int eval() override;
};
class Lit : public Exp
{
 public:
 int value = 0;
 Lit(int v);
 void print() override;
 int eval() override;
};
class Test
{
 public:
 Lit *ltree;
 Add *atree;
 Neg *ntree;
 virtual ~Test()
 {
	 delete ltree;
	 delete atree;
	 delete ntree;
 }

 Test();
 virtual void run();
};
