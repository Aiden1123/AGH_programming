#include "Sum.h"
#include <iostream>

Sum::Sum(MathExpr &a,MathExpr &b) : Operation(a,b) {}

double Sum::eval() {
    return a.eval() + b.eval();
}

void Sum::print() {
    std::cout<<"(";
    a.print();
    std::cout<<"+";
    b.print();
    std::cout<<")";
}
