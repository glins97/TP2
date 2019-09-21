#include "input.hpp"

list<string> loadFile(char* filename){
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


void printList(list<string> l){
    auto it = l.begin();
    for (int i; i < l.size(); i++){
        cout << "[" << i + 1 << "] -> " << *next(it, i);
    }
    cout << endl;
}