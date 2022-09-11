#pragma once

/**Creates function object that checks 
    if given number is divisible by divider*/
class DivisibleBy {
    
    private:
    
    int divider;
    
    public:
    
    DivisibleBy(int divider) {      //initialises divider
        this->divider = divider;
    }
    
    bool operator()(int x) {        //checks if x is divisible by divider
        return x%divider == 0;
    }

};

/**Creates function object that checks 
    if given number is greater than x*/
class GreaterThan {

    private:
    
    int x;
    
    public:
    
    GreaterThan(int x) {        //initialises x
        this->x = x;
    }
    
    bool operator()(int x) {    //checks if x is greater than object's x
        return x > this->x;
    }

};
