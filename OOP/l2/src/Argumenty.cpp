#include "Argumenty.h"

Argumenty::Argumenty(int size) {

    this->size = size;                  //initialise size    
    this->arr = new double[size];       //allocate array

}
    
Argumenty::~Argumenty() {

    delete[] this->arr;             //free memory    

}
   
Argumenty &Argumenty::operator()(unsigned int index,double val) {

    if (index<this->size)           //if index is valid then assign val to index
        (this->arr)[index] = val;

    return *this;                   //returns itself
}
    
void Argumenty::print(const char *message) const{
    
    std::cout<<message<<" ";            //print message


    for(int i=0;i<this->size;i++) {     //print arguments
        std::cout<<arr[i]<<" ";
    }
    
    std::cout<<std::endl;               //print new line character
}
    
void Argumenty::print(const char *message, std::ostream &stream) const{
    
    stream<<message<<" ";               //print message


    for(int i=0;i<this->size;i++) {     //print arguments
        stream<<arr[i]<<" ";
    }
    
    stream<<std::endl;                  //print new line character    
}
    
int Argumenty::getSize() const{
    return this->size;
}
    
double Argumenty::getArg(unsigned int index) const{         //returns element with given index on condition that index is valid
    return (index < this->size) ? (this->arr)[index] : 0;   //and 0 otherwise        
}
