using namespace std;

#include "manager/manager.hpp"
#include <iostream>

int main(){
    Manager manager = Manager(vector<ExpBase*>({
        new AddExp(),
        new NegExp(),
        new LiteralExp()
    }));

    manager.run("2 + 9 - 3");
    cout << "Final result: " <<  manager.value << endl;
}
