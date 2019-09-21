#pragma once
using namespace std;

#include <iostream>
#include <string>
#include <list>
#include <fstream>

list<string> loadFile(char* filename);
void printList(list<string> l);