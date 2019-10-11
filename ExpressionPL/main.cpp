using namespace std;

#include "manager/factory.hpp"
#include <iostream>

int main(){
    auto factory = ManagerFactory(vector<ExpBase*>({
        new AddExp(),
        new NegExp(),
        new MulExp(),
        new PowExp(),
        new LiteralExp()
    }));

    auto manager = factory.request(vector<string>({
        "L", "+"
    }));
    manager.eval("100 + 10");
}
