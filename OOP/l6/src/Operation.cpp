#include "Operation.h"
#include <iostream>

void Operation::PrintWithValue() {
    this->print();                              //print operation
    std::cout<<" = "<<this->eval()<<std::endl;  //print value
}
