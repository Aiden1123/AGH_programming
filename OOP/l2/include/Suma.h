#pragma once
#include "Algo.h"

class Suma : public Algo {

    public:

    Argumenty wykonaj(const Argumenty &args) const{     //returns Argumenty object with one value representing sum of args
        
        Argumenty res(1);                   //initialise new Argumenty object
        double sum = 0;                     //variable used to sum args   
        
        for(int i=0;i<args.getSize();i++) { //calculate sum
           sum += args.getArg(i);
        }
        
        res(0,sum);                         //assign sum to res
        
        return res;                         //return result    
    }
    
    Suma *sklonuj() const{                  //creates a new Pierwiastek algorithm
        return new Suma();                  //note that returned value has to be deleted later to avoid memory leak
    }
};
