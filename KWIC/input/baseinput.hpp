#pragma once
using namespace std;

#include <string>
#include <list>
#include <fstream>

class InputManager{
    public:
    virtual list<list<string>> load(){
        return list<list<string>>();};
    
    list<string> _splitTitle(string title);
    list<list<string>> _splitContent(list<string> content);
    list<string> _loadFile(char* filename);
};

#include "textinput.hpp"
#include "csvinput.hpp"