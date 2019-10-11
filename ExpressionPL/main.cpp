using namespace std;

#include "manager/manager.hpp"
#include <iostream>

int main(){
    Manager manager = Manager(vector<ExpBase*>({
        new AddExp(),
        new NegExp(),
        new MulExp(),
        new PowExp(),
        new LiteralExp()
    }));

    manager.run("3 + -2 * 2^2 + 2 ^ 2 ");
    cout << "Final result: " <<  manager.value << endl;
}
