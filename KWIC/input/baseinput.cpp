#include "baseinput.hpp"

list<string> BaseInputManager::_loadFile(string filename){
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

list<string> BaseInputManager::_splitTitle(string title){
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

list<list<string>> BaseInputManager::_splitContent(list<string> content){
    auto res = list<list<string>>();
    for (string title: content){
        auto splitted = _splitTitle(title); 
        res.push_back(splitted);
    }    
    return res;
}