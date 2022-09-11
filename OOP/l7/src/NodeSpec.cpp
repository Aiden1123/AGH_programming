#include <string>
#include "NodeSpec.h"

//////////////////Int//////////////////////

NodeInt::NodeInt(int newVal){
    val = newVal;
}

int &NodeInt::valInt() {
    return val;
}
    
Node *NodeInt::clone() const {
    return new NodeInt(val);
}

std::string NodeInt::toString() const {
    return std::to_string(val);
}

////////////////Float/////////////////////

NodeFloat::NodeFloat(float newVal){
    val = newVal;
}

float &NodeFloat::valFloat() {
    return val;
}
    
Node *NodeFloat::clone() const {
    return new NodeFloat(val);
}

std::string NodeFloat::toString() const {
    return std::to_string(val);
}

///////////////////String/////////////////

NodeString::NodeString(std::string newVal){
    val = newVal;
}

std::string &NodeString::valString() {
    return val;
}
    
Node *NodeString::clone() const {
    return new NodeString(val);
}

std::string NodeString::toString() const {
    return val;
}
