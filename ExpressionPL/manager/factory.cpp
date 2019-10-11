#include "factory.hpp"
#include "iostream"
Manager ManagerFactory::request(vector<string> operator_ids){
    auto operators = vector<ExpBase*>();    
    for (string op: operator_ids){
        for (auto exp: this->supported_operators){
            if (op == exp->get_op())
                operators.push_back(exp);
        }
    }

    return Manager(operators);
}

ManagerFactory::ManagerFactory(vector<ExpBase*> supported_operators){
    this->supported_operators = supported_operators;
}
