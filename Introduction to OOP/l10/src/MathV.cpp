#include "MathV.h"
#include "math.h"

MathV::MathV(int dim) {

    if (dim <= 0)       //make sure dim is valid
        dim=1;

    this->len = dim;            
    this->array = new int[dim];     //allocate memory for array
    
    for(int i=0;i<dim;i++) {        //initialise array to zeros
        (this->array)[i] = 0;
    }
}

MathV::MathV(const MathV &old) {

    this->len = old.len;
    this->array = new int[this->len];       //create new dynamic array
    
    for(int i=0;i<this->len;i++)            //copy old arrray
        (this->array)[i] = (old.array)[i];
}

MathV::MathV(MathV &&old) {

    this->len = old.len;
    this->array = new int[this->len];       //create new dynamic array
    
    for(int i=0;i<this->len;i++)            //copy old array
        (this->array)[i] = (old.array)[i];
}

MathV::~MathV() {
    delete[] this->array;       //free memory
}

int &MathV::at(int index) const{
    
    if (index<0)                        
        return (this->array)[0];
    
    if (index>=this->len)                
        return (this->array)[len-1];
    
    return (this->array)[index];
}


void MathV::print(const char *message) const {
    
    std::cout<<message<<"[";
    
    for(int i=0;i<this->len;i++) {
    
        std::cout<<(this->array)[i];
    
        if (i != this->len - 1)
            std::cout<<", ";
    
    }
    
    std::cout<<"]"<<std::endl;
}

double MathV::dot(const MathV &vector_a,const MathV &vector_b) {
    
    //check if dimensions are the same
    if (vector_a.len != vector_b.len) {
        std::cout<<"Error, vectors of different dimensions!"<<std::endl;
        return 0;
    }
    
    //calculate dot value
    double res = 0;
    
    for(int i=0;i<vector_a.len;i++) {                   
        res+=(vector_a.array)[i] * (vector_b.array)[i];
    }
    
    return res;
}

double MathV::norm() const {
    
    double res = 0;
    
    for(int i=0;i<this->len;i++) {                  //calculate length
        res+= (this->array)[i] * (this->array)[i];
    }
    
    return sqrt(res);
}

MathV MathV::add(int x) {
    
    for(int i=0;i<this->len;i++)                //add integer
        (this->array)[i] += x; 
    
    return *this;
}

MathV MathV::add(const MathV &vector) {    
    if (this->len != vector.len)                //check if dimensions are the same
        return *this;

    for(int i=0;i<this->len;i++) {              //add vector
        (this->array)[i] += (vector.array)[i]; 
    }
    
    return *this;
}


