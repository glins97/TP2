#include "kwic/kwic.hpp"
using namespace std;

int main(){
    char filename[] = "resources/2";
    KWIC kwic = KWIC(                   // Managers:
        new CSVInputManager(filename),  // Input 
        new PrintOutputManager(),       // Output
        new NSWAlphabetizerManager(),   // Alphabetizer
        new RightShifterManager()       // Shifter
    );

    kwic.run();
    return 0;
}