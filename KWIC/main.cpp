#include "input.hpp"
#include "output.hpp"
using namespace std;

int main(){
    char filename[] = "files/2";

    auto titles = loadTitlesFromFilename(filename);
    printTitles(titles);
    return 0;
}