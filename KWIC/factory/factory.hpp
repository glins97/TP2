#pragma once
using namespace std;

#include "../kwic/kwic.hpp"
#include "../input/inputs.hpp"
#include "../output/outputs.hpp"
#include "../shifter/shifters.hpp"
#include "../alphabetizer/alphabetizers.hpp"

class KWICFactory{
    public:
    KWIC request_new_kwic();

    private:
    BaseInputManager* _get_input_manager();
    BaseOutputManager* _get_output_manager();
    BaseShifterManager* _get_shifter_manager();
    BaseAlphabetizerManager* _get_alphabetizer_manager();
    void clearConsole();
    int handleChoice(int minValue, int maxValue);
    int requestMenuChoice(list<string> headers);
    
};
