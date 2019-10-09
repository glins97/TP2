#pragma once
using namespace std;

#include <list>
#include <string>

#include "../input/baseinput.hpp"
#include "../output/baseoutput.hpp"
#include "../alphabetizer/basealphabetizer.hpp"
#include "../shifter/baseshift.hpp"

class KWIC{
    public:
    list<list<string>> data;

    BaseInputManager* inputManager;
    BaseOutputManager* outputManager;
    AlphabetizerManager* alphabetizerManager;
    ShifterManager* shifterManager;

    void run();
    KWIC();
    KWIC(BaseInputManager* inputManager, BaseOutputManager* outputManager,
        AlphabetizerManager* alphabetizerManager, ShifterManager* shifterManager);
};
