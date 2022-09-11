#pragma once
#include <string>

/**Virtual node class used by cyclic list*/
class Node {
    
    private:
    
    Node *next;                         //pointer to next element in the list
    
    public:
    
    Node();
    void setNext(Node *newNext);
    Node *getNext() const;
    
    virtual Node *clone() const = 0;            //returns node with copy of the data
    virtual std::string toString() const = 0;   //converts data to string
};
