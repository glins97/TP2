#include "csvinput.hpp"

CSVInputManager::CSVInputManager(string filename){ 
    this->filename = filename;
};

list<list<string>> CSVInputManager::load(){
    cout << "CSVInputManager load" << endl;
    list<string> content = _loadFile(filename);
    return this->_splitContent(content);
}