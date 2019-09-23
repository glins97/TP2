#include "input.hpp"
#include "output.hpp"
#include "alphabetizer.hpp"
#include "shift.hpp"
using namespace std;

int main(){
    char filename[] = "files/2";

    auto titles = loadTitlesFromFilename(filename);
    titles = shiftTitles(titles);
    titles = sortTitles(titles);
    printTitles(titles);
    return 0;
}