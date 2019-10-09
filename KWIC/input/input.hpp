#pragma once
using namespace std;

#include <iostream>
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

class TextInputManager: public InputManager{
    public:
    char* filename;
    list<list<string>> load();
    TextInputManager(char* filename);
};

class CSVInputManager: public InputManager{
    public:
    char* filename;
    list<list<string>> load();
    CSVInputManager(char* filename);
};
