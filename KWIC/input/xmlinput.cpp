#include "xmlinput.hpp"

XMLInputManager::XMLInputManager(char* filename){ 
    this->filename = filename;
};

list<list<string>> XMLInputManager::load(){
    cout << "XMLInputManager load" << endl;
    return list<list<string>>();
}