using namespace std;

#include "manager/factory.hpp"
#include <iostream>

int main(){
    
    // Factory of managers that COULD 
    // support those expressions
    auto factory = ManagerFactory(vector<ExpBase*>({
        new AddExp(),
        new NegExp(),
        new MulExp(),
        new PowExp(),
        new LiteralExp()
    }));

    // NO OPERATORS
    // auto manager1 = factory.request(vector<string>({
    // }));
    // manager1.eval("1");

    // LITERAL, SINGLE DIGIT EVAL
    // auto manager2 = factory.request(vector<string>({
    //     "L"
    // }));
    // manager2.eval("1");
    // manager2.eval("2");

    // LITERAL, MULTIPLE DIGITS EVAL
    // auto manager3 = factory.request(vector<string>({
    //     "L"
    // }));
    // manager3.eval("1989");

    // LITERAL & ADD, SINGLE ADDITION
    // auto manager4 = factory.request(vector<string>({
    //     "L", "+"
    // }));
    // manager4.eval("5 + 16");

    // LITERAL & ADD, SPACING
    // auto manager4b = factory.request(vector<string>({
    //     "L", "+"
    // }));
    // manager4b.eval("5+ 16");
    // manager4b.eval("       5+ 16   ");

    // LITERAL & ADD, MULTIPLE ADDITION
    // auto manager5 = factory.request(vector<string>({
    //     "L", "+"
    // }));
    // manager5.eval("5 + 16 + 21 + 100");

    // LITERAL & NEG
    // auto manager6 = factory.request(vector<string>({
    //     "L", "-"
    // }));
    // manager6.eval("-10");
    // manager6.eval("--10");
    // manager6.eval("---10");
    // manager6.eval("15 - 10");

    // LITERAL & MUL & POW
    // auto manager7 = factory.request(vector<string>({
    //     "L", "*", "^" 
    // }));
    // manager7.eval("2 * 5 ^ 2");
    // manager7.eval("3 * 2 ^ 10");
    // manager7.eval("3 * 2 ^ 10 * 3");

    // LITERAL & MUL & POW, ORDER OF INCLUSION
    // auto manager7b = factory.request(vector<string>({
    //     "L", "^", "*" 
    // }));
    // manager7b.eval("2 * 5 ^ 2");
    // manager7b.eval("3 * 2 ^ 10");
    // manager7b.eval("3 * 2 ^ 10 * 3");

    // ALL OF THE ABOVE
    auto manager8 = factory.request(vector<string>({
        "L", "-", "+", "*", "^" 
    }));
    manager8.eval("1 + 1"); 
    manager8.eval("1000 + 2 ^ 10 * 2 - 1"); // 1000 + 2048 - 1 = 3047

}
