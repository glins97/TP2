#include "nemseioquetofazendomesmo.h"

Add::Add(Exp *l, Exp *r)
{
left = l;
right = r;
}

void Add::print()
{
left->print();
std::wcout << L"+";
right->print();
}

int Add::eval()
{
return left->eval() + right->eval();
}

Neg::Neg(Exp *e)
{
	expr = e;
}

void Neg::print()
{
std::wcout << L"-(";
expr->print();
std::wcout << L")";
}

int Neg::eval()
{
return expr->eval() * -1;
}

Lit::Lit(int v)
{
	value = v;
}

void Lit::print()
{
std::wcout << value;
}

int Lit::eval()
{
	return value;
}

Test::Test()
{
ltree = new Lit(3);
atree = new Add(ltree, ltree);
ntree = new Neg(ltree);
}

void Test::run()
{
ltree->print();
atree->print();
ntree->print();
std::wcout << ltree->eval() << std::endl;
std::wcout << atree->eval() << std::endl;
std::wcout << ntree->eval() << std::endl;
}
