#pragma once
using namespace std;

#include <vector>
#include <string>
#include "../expression/expression.hpp"

class Manager{
    public:
    int value = 0;
    string expression = "0";
    Manager* left;
    Manager* right;
    ExpBase* selected_operator;
    vector<ExpBase*> operators;

    Manager(vector<ExpBase*> operators);
    void split(string input);
    void run(string expression);
    void eval(string expression);
    string trim(string input);

};