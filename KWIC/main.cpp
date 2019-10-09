#include "input.hpp"
#include "output.hpp"
#include "alphabetizer.hpp"
#include "shift.hpp"
#include "kwic.hpp"
using namespace std;

void setKWIC(KWIC* variable){
    char filename[] = "files/2";
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