#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

/**Cyclic list with various data types*/
class CyclicList {

    private:
    
    Node *start;    //head of the list
    Node *end;      //tail of the list
    int counter;    //number of elements in list
    
    public:
    
    CyclicList();                   
    CyclicList(CyclicList &older);  //copy constructor - creates deep copy of the list
    ~CyclicList();                  //destructor - frees memory allocated for each node
    
    CyclicList &operator<<(Node *data); //adds data to the end of list
                                        //Node that is being added **must be** allocated on heap
    Node *operator()() const;           //returns first element in the list
    int count() const;                  //returns number of elements in the list
    CyclicList &rotate();               
    CyclicList &rotate_back();
};

//<< overload for printing to output stream
std::ostream &operator<<(std::ostream &out,const CyclicList &list);   
