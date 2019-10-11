#include "manager.hpp"
#include <iostream>

Manager::Manager(vector<ExpBase*> operators){
    this->operators = vector<ExpBase*>(operators);
    this->value = 0;
    this->expression = "0";
    this->selected_operator = nullptr;
}

void Manager::eval(string input){
    this->run(input);
    cout << "Result: " <<  this->value << endl;
}

void Manager::run(string input){
    this->expression = input;

    int split_index = -1;
    bool operator_matched = false;
    for (auto op: this->operators){
        split_index = op->identify(input);
        if (split_index > -1){
            operator_matched = true;
            this->selected_operator = op;
            this->split(input);
            break;
        }
    }

    if (!operator_matched)
        cout << "Expression '" << this->expression << "' has no operator matches." << endl;
}

void Manager::split(string input){
    input = this->trim(input);

    string left_input;
    string right_input;

    this->left = new Manager(this->operators);
    this->right = new Manager(this->operators);
    this->selected_operator->
        get_splits(input, &left_input, &right_input);

    if (left_input == "" && right_input == "")
        this->left->expression = input;    

    if (left_input != ""){
        this->left->run(left_input);
    }

    if (right_input != ""){
        this->right->run(right_input);
    }

    this->value = this->selected_operator->eval(
        this->left->expression,
        this->right->expression,
        this->left->value,
        this->right->value
    );
}


string Manager::trim(string input){
    int front = 0;
    int back = 0;
    bool started = false;

    for (auto chr: input){
        if (chr == ' ') {
            if (!started) front++;
            back++;
        }
        if (chr != ' ') {
            back = 0;
            started = true;
        }
    }

    return input.substr(front, input.length() - back);
}
