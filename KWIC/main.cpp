#include "input.hpp"
#include "output.hpp"
#include "alphabetizer.hpp"
using namespace std;

int main(){
    char filename[] = "files/2";

    auto titles = loadTitlesFromFilename(filename);
    printTitles(titles);

    titles = sortTitles(titles);
    printTitles(titles);
    return 0;
}