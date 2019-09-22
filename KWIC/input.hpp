#pragma once
using namespace std;

#include <iostream>
#include <string>
#include <list>
#include <fstream>

list<string> _splitTitle(string title);
list<list<string>> _splitContent(list<string> content);

list<string> _loadFile(char* filename);
list<list<string>> loadTitlesFromFilename(char* filename);
