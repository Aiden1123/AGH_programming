#pragma once
#include "Operation.h"
#include <iostream>

/**Sum of two arguments*/
class Sum : public Operation {
    
    public:
    
    Sum(MathExpr &a,MathExpr &b);
    
    protected:
    
    double eval();
    void print();
};
