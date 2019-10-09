#include "csvinput.hpp"

CSVInputManager::CSVInputManager(char* filename){ 
    this->filename = filename;
};

list<list<string>> CSVInputManager::load(){
    list<string> content = _loadFile(filename);
    return this->_splitContent(content);
}