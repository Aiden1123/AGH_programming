#include "Num.h"

bool isPrime(unsigned int x) {
    
    if (!x || x==1)         //0 and 1 are not prime
        return false;
    
    for(int i=2;i<=sqrt(x);i++) { //check if x is divisible by any integer
                                  //between 2 and sqrt(x) if so it is not prime        
        if (!(x%i))
            return false;   
    
    }
    
    //if x doesn't have divisors in <2,sqrt(x)> then it is prime
    return true;
}

