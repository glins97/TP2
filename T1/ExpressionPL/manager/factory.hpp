#pragma once
using namespace std;

#include "manager.hpp"
#include "../expression/expression.hpp"

class ManagerFactory{
    public:
    vector<ExpBase*> supported_operators;
    Manager request(vector<string> operator_ids);
    ManagerFactory(vector<ExpBase*> supported_operators);
};
