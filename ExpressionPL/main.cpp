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

    manager.run("2 ^ 8 + 3 * 2 - 5 + 2 ^ 2");
    cout << "Final result: " <<  manager.value << endl;
}
