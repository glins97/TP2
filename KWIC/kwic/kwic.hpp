#pragma once
using namespace std;

#include <list>
#include <string>

#include "../input/input.hpp"
#include "../output/output.hpp"
#include "../alphabetizer/alphabetizer.hpp"
#include "../shifter/shift.hpp"

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
