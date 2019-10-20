#include "textinput.hpp"

TextInputManager::TextInputManager(string filename){
    this->filename = filename;
};

list<string> TextInputManager::_loadFile(string filename){
    list<string> content = list<string>();
    char filename_[filename.length() + 1]; 
    strcpy(filename_, filename.c_str()); 

    FILE* fp = fopen(filename_, "r");
    if (fp == NULL)
        exit(1);

    char* line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, fp)) != -1) {
        content.push_back(line);
    }
    fclose(fp);
    if (line) free(line);
    return content;
}

list<list<string>> TextInputManager::load(){
    cout << "TextInputManager load" << endl;
    list<string> content = _loadFile(filename);
    return this->_splitContent(content);
}