#pragma once
using namespace std;

#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h> 

class BaseInputManager{
    public:
    virtual list<list<string>> load(){
        cout << "BaseInputManager load" << endl;
        return list<list<string>>();};
    
    list<string> _splitTitle(string title);
    list<list<string>> _splitContent(list<string> content);
    list<string> _loadFile(string filename);
};
