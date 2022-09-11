#pragma once
#include "MathExpr.h"

/**Single number in double format*/
class Primitive : public MathExpr{
    
    double val;     //value             
    
    public:
    
    Primitive(double value);
    void Set(double value);     //sets the new value
    void print();               //prints value
    double eval();              //returns value
};
