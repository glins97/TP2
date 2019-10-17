#pragma once
using namespace std;

#include <algorithm>
#include <string>
#include <list>
#include <iostream>

class BaseShifterManager{
    public:
    virtual list<list<string>> shift(list<list<string>> titles){ 
        cout << "BaseShifterManager shift" << endl;        
        return list<list<string>>();
    };
};
