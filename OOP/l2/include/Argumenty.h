#pragma once
#include <iostream>

/**Class that holds arguments that can be passed to algorithms
    all arguments are of type double and there is size of them*/
class Argumenty{
    
    double *arr;    //array with arguments
    int size;       //number of arguments
    
    public:
    
    Argumenty(int size);    //creates Argumenty with given size of the array
    
    ~Argumenty();           //destructor to free memory
    
    Argumenty &operator()(unsigned int index,double val);       //() brackets are used for assigning values to the argument with given index
    
    void print(const char *message) const;                      //prints arguments preceeded by message to std::cout
    
    void print(const char *message, std::ostream &stream) const;    //prints arguments preceeded by message to given stream
    
    int getSize() const;                                            
    
    double getArg(unsigned int index) const;
};
