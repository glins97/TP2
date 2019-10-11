#pragma once
using namespace std;

#include <iostream>
#include <string>
#include <list>

class BaseOutputManager{
    public:
    virtual void dump(list<list<string>> titles){
        cout << "BaseOutputManager dump" << endl;        
    };
};
