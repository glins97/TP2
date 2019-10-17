#include "factory/factory.hpp"
using namespace std;

int main(){
    auto factory = KWICFactory();
    auto kwic = factory.request_new_kwic();
    kwic.run();
    return 0;
}