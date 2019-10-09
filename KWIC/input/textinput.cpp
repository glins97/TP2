#include "textinput.hpp"

TextInputManager::TextInputManager(char* filename){ 
    this->filename = filename;
};

list<list<string>> TextInputManager::load(){
    list<string> content = _loadFile(filename);
    return this->_splitContent(content);
}