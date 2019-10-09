#include "input.hpp"

TextInputManager::TextInputManager(char* filename){ 
    this->filename = filename;
};

list<list<string>> TextInputManager::load(){
    list<string> content = _loadFile(filename);
    return this->_splitContent(content);
}

CSVInputManager::CSVInputManager(char* filename){ 
    this->filename = filename;
};

list<list<string>> CSVInputManager::load(){
    list<string> content = this->_loadFile(filename);
    return this->_splitContent(content);
}

list<string> InputManager::_loadFile(char* filename){
    list<string> content = list<string>();

    FILE* fp = fopen(filename, "r");
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

list<string> InputManager::_splitTitle(string title){
    auto res = list<string>();
    string word = "";
    for (char c: title){
        if (c == ' ' || c == '\r' || c == '\n'){
            res.push_back(word);
            word = "";
        }
        else{
            word += c;
        }
    }
    if (word != "") res.push_back(word);
    return res;
}

list<list<string>> InputManager::_splitContent(list<string> content){
    auto res = list<list<string>>();
    for (string title: content){
        auto splitted = _splitTitle(title); 
        res.push_back(splitted);
    }    
    return res;
}