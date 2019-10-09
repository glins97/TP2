#pragma once
using namespace std;

#include <list>
#include <string>

#include "input.hpp"
#include "output.hpp"
#include "alphabetizer.hpp"
#include "shift.hpp"

class KWIC{
    public:
    list<list<string>> data;

    InputManager* inputManager;
    OutputManager* outputManager;
    AlphabetizerManager* alphabetizerManager;
    ShifterManager* shifterManager;

    void run();
    KWIC();
    KWIC(InputManager* inputManager, OutputManager* outputManager,
        AlphabetizerManager* alphabetizerManager, ShifterManager* shifterManager);
};
