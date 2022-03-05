#pragma once

#include <iostream>


class MathV{
    
    /**N-dimensional vector with integers*/
    
    private:
    
    int len;    //number of vector dimensions
    int *array; //dynamic array with vector coordinates
    
    public:
    
    explicit MathV(int dim);
    /**creates new vector with dim dimensions and sets all coordinates to 0.
       if dim is negative or zero then vector with 1 dimension is created.*/
    
    MathV(const MathV &old);
    /**copy constructor, creates a copy of vector*/
    
    MathV(MathV &&old);
    /**move constructor, creates a copy of vector*/
    
    ~MathV();
    /**destructor used to free memory*/
    
    int &at(int index) const;
    /**returns reference to coordinate of dimension specified by index.
       Dimensions' indexes start from 0. If index is higher than the highest index
       then reference to the last coordinate is returned. If index is < 0 then
       reference to first coordinate is returned.*/ 
    
    void print(const char *message) const;
    /**prints message and vector */
    
    double static dot(const MathV &vector_a,const MathV &vector_b);
    /**returns dot value of vector_a and vector_b. If dimensions of vectors do not match
       then error message is displayed and 0 is returned.*/
    
    double norm() const;
    /**returns length of the vector */
    
    MathV add(int x);
    /**adds x to all coordinates and also returns vector which is result of addition*/
    
    MathV add(const MathV &vector);
    /**adds vector and also returns vector which is result of addition.
       If dimensions do not match then method doesn't add anything and returns
       same vector on which method was called.*/
    
    operator double() const{
    /**transforms vector to it's length while casting vector to double*/

    return this->norm();

    }
};
