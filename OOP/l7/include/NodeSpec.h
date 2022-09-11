#pragma once
#include <string>
#include "Node.h"

//////////////////Int//////////////////

class NodeInt : public Node {
    
    int val;            //data stored in node
    
    public: 
    
    NodeInt(int newVal);    //constructor which sets val to newVal
    int &valInt();          //getter
    
    Node *clone() const;
    std::string toString() const;
};

///////////////Float//////////////////

class NodeFloat : public Node {
    
    float val;          //data stored in node
    
    public: 
    
    NodeFloat(float newVal);        //constructor which sets val to newVal
    float &valFloat();              //getter
    
    Node *clone() const;
    std::string toString() const;
};

/////////////String/////////////////

class NodeString : public Node {
    
    std::string val;    //data stored in node
    
    public: 
    
    NodeString(std::string newVal);     //constructor which sets val to newVal
    std::string &valString();           //getter
    
    Node *clone() const;
    std::string toString() const;
};
