#pragma once
using namespace std;

#include <list>
#include <string>

#include "../input/inputs.hpp"
#include "../output/outputs.hpp"
#include "../alphabetizer/alphabetizers.hpp"
#include "../shifter/shifters.hpp"

class KWIC{
    public:
    list<list<string>> data;

    BaseInputManager* inputManager;
    BaseOutputManager* outputManager;
    BaseAlphabetizerManager* alphabetizerManager;
    BaseShifterManager* shifterManager;

    void run();
    KWIC();
    KWIC(BaseInputManager* inputManager, BaseOutputManager* outputManager,
        BaseAlphabetizerManager* alphabetizerManager, BaseShifterManager* shifterManager);
};
