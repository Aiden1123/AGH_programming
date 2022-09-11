#pragma once

/**General mathematical expression with undifined number of arguments 
   Abstract class */    
class MathExpr {

    public:
    
    void virtual print() = 0;       //prints expretion to console
    double virtual eval() = 0;      //calculates value of expression

};
