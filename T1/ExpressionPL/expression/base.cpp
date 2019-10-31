#include "base.hpp"

void ExpBase::get_splits(string input, string* left_input, string* right_input){
    int split_index = this->identify(input);
    
    *left_input = input.substr(0, split_index);
    *right_input = input.substr(split_index+1, input.length());
}
