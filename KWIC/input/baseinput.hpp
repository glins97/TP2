#pragma once
using namespace std;

#include <string>
#include <list>
#include <fstream>
#include <iostream>

class BaseInputManager{
    public:
    virtual list<list<string>> load(){
        cout << "BaseInputManager load" << endl;
        return list<list<string>>();};
    
    list<string> _splitTitle(string title);
    list<list<string>> _splitContent(list<string> content);
    list<string> _loadFile(char* filename);
};

#include "textinput.hpp"
#include "csvinput.hpp"
#include "xmlinput.hpp"
#include "sqlinput.hpp"
#include "dblpinput.hpp"