#pragma once
#include "Operation.h"
#include <iostream>

/**Product of two arguments*/
class Product : public Operation {
    
    public:
    
    Product(MathExpr &a,MathExpr &b);
    
    protected:
    
    double eval();
    void print();
};
