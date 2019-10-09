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

#include "printoutput.hpp"
#include "textoutput.hpp"
#include "csvoutput.hpp"
#include "xmloutput.hpp"
#include "htmloutput.hpp"