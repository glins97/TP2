#include "textinput.hpp"

TextInputManager::TextInputManager(string filename){
    this->filename = filename;
};

list<list<string>> TextInputManager::load(){
    cout << "TextInputManager load" << endl;
    list<string> content = _loadFile(filename);
    return this->_splitContent(content);
}