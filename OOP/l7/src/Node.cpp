#include "Node.h"

Node::Node() {
    next = nullptr;
}
    
void Node::setNext(Node *newNext) {
    next = newNext;
}
    
Node *Node::getNext() const {
    return next;
}
