#include "input.hpp"
using namespace std;

int main(){
    char filename[] = "files/1";

    list<string> content = loadFile(filename);
    printList(content);
    return 0;
}