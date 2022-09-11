#pragma once
#include "Operation.h"
#include <iostream>

/**Ratio of two arguments*/
class Ratio : public Operation {
    
    public:
    
    Ratio(MathExpr &a,MathExpr &b);
    
    protected:
    
    double eval();
    void print();
};
