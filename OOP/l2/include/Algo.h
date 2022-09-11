#pragma once
#include "Argumenty.h"

/**Abstract class for algorithms*/
class Algo {

    public:

    virtual Argumenty wykonaj(const Argumenty &args) const = 0;     //executes given algorithm on args and returns result
    virtual Algo *sklonuj() const = 0;                              //creates a copy of algorithm                        
};
