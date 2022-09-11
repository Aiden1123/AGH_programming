#pragma once
#include "MathExpr.h"

/**Operation with two arguments*/
class Operation : public MathExpr{
    
    protected:
    
    MathExpr &a;    //argument on the left
    MathExpr &b;    //argument on the right
    
    public:
    
    Operation(MathExpr &a,MathExpr &b) : a(a), b(b) {}  //constructor with values' initialisation
    void PrintWithValue();                              //prints the operation with its value
};
