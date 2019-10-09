#include "kwic.hpp"

KWIC::KWIC(){};
KWIC::KWIC(BaseInputManager* inputManager, BaseOutputManager* outputManager,
        AlphabetizerManager* alphabetizerManager, ShifterManager* shifterManager){
    this->inputManager = inputManager;
    this->outputManager = outputManager;
    this->alphabetizerManager = alphabetizerManager;
    this->shifterManager = shifterManager;
};

void KWIC::run(){
    this->data = this->inputManager->load();
    this->data = this->shifterManager->shift(this->data);
    this->data = this->alphabetizerManager->sort(this->data);
    this->outputManager->dump(this->data);
}
