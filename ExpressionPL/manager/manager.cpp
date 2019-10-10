#include "manager.hpp"
#include <iostream>

Manager::Manager(){
}

void Manager::run(string input){
    for (auto manager: this->operators){
        cout << manager->identify(input) << endl;
    }
}