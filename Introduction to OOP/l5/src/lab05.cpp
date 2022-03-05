#include <iostream>
#include "lab05.h"

void printArray(myArray array) {

    if (array.N<=0) {   //check if array is not empty
        std::cout<<"Cannot print empty array."<<std::endl;
        return;
    }
    
    std::cout<<"[";
    
    for(int i=0;i<array.N;i++) {    //print array
        std::cout<<array.data[i];
        if (i!=array.N-1)
            std::cout<<",";
    }
    
    std::cout<<"]";
    return;
}

int fibonacci(int n) {
    /*function that returns n element of fibonacci sequence,
    it is not verified if n is non-negative*/
    return (n<2)? 1 : (fibonacci(n-1) + fibonacci(n-2));
}

int fillArrayWithFibonacci(myArray *array, int size) {
    if (!array) {       //check if array exists
        std::cout<<"Empty pointer provided."<<std::endl;
        return 0;
    }
    
    if (size<=0 || size>MAX_SIZE) {      //check if size is valid
        std::cout<<"Wrong number of dimensions."<<std::endl;
        return 0;
    }
    
    array->N=size;      //update size
    
    for(int i=0;i<array->N;i++) {   //fill array with fibonacci
        array->data[i]=fibonacci(i);
    }

    return 1;
}
void revert(myArray *array){
    if (!array) {       //check if array exists
        std::cout<<"Empty pointer provided."<<std::endl;
        return;
    }
    
    int aux;
    for(int i=0;i<(array->N)/2;i++) {   //revert array
        aux = array->data[i];           //swap data[i] with data[array->N-i-1]
        array->data[i] = array->data[array->N-i-1];
        array->data[array->N-i-1] = aux;
    }
    
    printArray(*array);                 //show success message
    std::cout<<" (reverting done)"<<std::endl;
    
    return;
}
void extend(myArray *array, int extend_num){
    if (!array) {       //check if array exists
        std::cout<<"Empty pointer provided."<<std::endl;
        return;
    }
    
    if(extend_num<=0) {      //check if extend_num is positive
        std::cout<<"Wrong number of dimensions."<<std::endl;
        return;
    }
    
    if (extend_num + array->N > MAX_SIZE) {     //check if extend_num is valid
        std::cout<<"Wow, you've just gone crazy ("<<extend_num + array->N<<">"<<MAX_SIZE<<")."<<std::endl;
        return;
    }
    
    array->N+=extend_num;               //update size
    
    printArray(*array);                 //show success message
    std::cout<<" (extending by "<<extend_num<<" done)"<<std::endl;
    
}
void truncate(myArray *array, int truncate_num){
    if (!array) {       //check if array exists
        std::cout<<"Empty pointer provided."<<std::endl;
        return;
    }
    
    if(truncate_num<=0) {      //check if truncate_num is positive
        std::cout<<"Wrong number of dimensions."<<std::endl;
        return;
    }
    
    if (array->N - truncate_num <= 0) {     //update size
        array->N=0;
    }
    else {
        array->N-=truncate_num;
    }
    
    printArray(*array);                 //show success message
    std::cout<<" (truncation by "<<truncate_num<<" done)"<<std::endl;
    
    return;    
    
}
void checkArraySpouse(myArray *array) {
    
    if (array->spouse) {                //case 1: spouse exists
        printArray(*array);
        std::cout<<" is paired with ";
        printArray(*(array->spouse));
        std::cout<<std::endl;
    }
    
    else {                              //case 2: spouse does not exist
        printArray(*array);
        std::cout<<" has no spouse."<<std::endl;
    }
    
    return;
}

int check_twin(myArray *array_a, myArray *array_b) {
    /*checks if array_a and array_b are twins*/
    if (!array_a || !array_b) {     //check if arrays exist
        return 0;
    }
    
    if (array_a->N!=array_b->N) {   //check if sizes are the same
        return 0;
    }
    
    for(int i=0;i<array_a->N;i++) {     //check if data is the same
        if (array_a->data[i]!=array_b->data[i]) {
            return 0;
        }
    }
    
    return 1;   //return 1 if there are no differences
}
void marry(myArray *array_a, myArray *array_b) {
    if (!array_a || !array_b) {     //check if arrays exist
        std::cout<<"Empty pointer provided."<<std::endl;
        return;
    }
    
    if (array_a==array_b) {     //check if arrays are not the same
        std::cout<<"Can't marry myself"<<std::endl;
        return;
    }
    
    if (check_twin(array_a,array_b)) {
        std::cout<<"Can't marry my twin"<<std::endl;
        return;
    }
    
    //update spouse information
    array_a->spouse = array_b;
    array_b->spouse = array_a;
   
    return;
}
void divorce(myArray *array_a, myArray *array_b) {
    if (!array_a || !array_b) {     //check if arrays exist
        std::cout<<"Empty pointer provided."<<std::endl;
        return;
    }
    
    //update spouse information
    array_a->spouse=nullptr;
    array_b->spouse=nullptr;
    return;
}

