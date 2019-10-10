#include "manager.hpp"
#include <iostream>

Manager::Manager(vector<ExpBase*> operators){
    this->operators = vector<ExpBase*>(operators);
    this->value = 0;
    this->expression = "0";
    this->selected_operator = nullptr;
}

void Manager::run(string input){
    this->expression = input;

    int split_index = -1;
    for (auto op: this->operators){
        split_index = op->identify(input);
        if (split_index > -1){
            cout << "Splitting on: '" << input[split_index] << "'" << endl;
            this->selected_operator = op;
            this->split(input, split_index);
            break;
        }
    }

}

void Manager::split(string input, int split_index){
    input = this->trim(input);

    string left_input = trim(input.substr(0, split_index));
    string right_input = trim(input.substr(split_index+1, input.length()));

    this->left = new Manager(this->operators);
    this->left->expression = this->expression;
    this->right = new Manager(this->operators);
    if (left_input != ""){
        cout << "Left -> ";
        cout << "'" << left_input << "'" << endl;
        this->left->run(left_input);
    }

    if (right_input != ""){
        cout << "Right -> ";
        cout << "'" << right_input << "'" << endl;
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
