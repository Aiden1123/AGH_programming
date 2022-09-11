#include "Ratio.h"
#include <iostream>

Ratio::Ratio(MathExpr &a,MathExpr &b) : Operation(a,b) {}

double Ratio::eval() {
    return a.eval() / b.eval();
}

void Ratio::print() {
    std::cout<<"(";
    a.print();
    std::cout<<"/";
    b.print();
    std::cout<<")";
}
