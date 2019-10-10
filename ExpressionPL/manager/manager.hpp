#pragma once
using namespace std;

#include <vector>
#include <string>
#include "../expression/expression.hpp"

class Manager{
    /*
        Manager has:
            selected_operator;
            left manager;
            right manager;

            run ->
            iterates thru expression + operators
            until it finds a char that matches operator;
            then it splits expression into left and right, and 
            recursively calls its manager run; 
    */
    public:
    int value;
    Manager* left;
    Manager* right;
    ExpBase* selected_operator;
    string expression;
    vector<ExpBase*> operators;

    Manager();
    void run(string expression);
};