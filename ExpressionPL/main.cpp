using namespace std;

#include "manager/manager.hpp"

int main(){
    Manager manager = Manager();
    manager.operators.push_back(new AddExp());
    manager.operators.push_back(new LiteralExp());
    manager.run("1+1");
}
