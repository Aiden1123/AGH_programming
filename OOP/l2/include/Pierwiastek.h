#pragma once
#include <math.h>
#include "Algo.h"

/**Square root*/
class Pierwiastek : public Algo{

    public:

    Argumenty wykonaj(const Argumenty &args) const{         //returns Argumenty object with square root of each value in args
        
        Argumenty res(args.getSize());          //create Argumenty object to store the result
        
        for(int i=0;i<args.getSize();i++) {     
            res(i,sqrt(args.getArg(i)));        //add square root to res
        }
        
        return res;                             //return result
   }
   
   Pierwiastek *sklonuj() const {               //creates a new Pierwiastek algorithm
        return new Pierwiastek();               //note that returned value has to be deleted later to avoid memory leak
   }
};
