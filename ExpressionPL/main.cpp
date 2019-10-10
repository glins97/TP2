using namespace std;

#include "manager/manager.hpp"
#include <iostream>

int main(){
    Manager manager = Manager(vector<ExpBase*>({
        new PowExp(),
        new MulExp(),
        new AddExp(),
        new NegExp(),
        new LiteralExp()
    }));

    manager.run("2 ^ 8");
    cout << "Final result: " <<  manager.value << endl;
}
