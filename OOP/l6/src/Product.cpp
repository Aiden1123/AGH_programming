#include "Product.h"
#include <iostream>

Product::Product(MathExpr &a,MathExpr &b) : Operation(a,b) {}

double Product::eval() {
    return a.eval() * b.eval();
}

void Product::print() {
    std::cout<<"(";
    a.print();
    std::cout<<"*";
    b.print();
    std::cout<<")";
}
