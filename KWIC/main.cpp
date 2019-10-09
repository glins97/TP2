#include "input/input.hpp"
#include "output/output.hpp"
#include "alphabetizer/alphabetizer.hpp"
#include "shifter/shift.hpp"
#include "kwic/kwic.hpp"
using namespace std;

void setKWIC(KWIC* variable){
    char filename[] = "resources/2";
    *variable = KWIC(
        new TextInputManager(filename),
        new PrintOutputManager(),
        new NSWAlphabetizerManager(),
        new RightShifterManager());
}

int main(){
    KWIC kwic; setKWIC(&kwic);
    kwic.run();
    return 0;
}