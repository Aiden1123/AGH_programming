#include "Node.h"
#include <cstring>

Node *Node::getPrev() const {
    return this->prev;
}
Node *Node::getNext() const {
    return this->next;
}
char *Node::getData() const {
    return this->data;
}
void Node::setPrev(const Node *new_prev) { 
    this->prev =(Node *) new_prev;
    return; 
}
void Node::setNext(const Node *new_next) {
    this->next =(Node *) new_next;
    return;
}
void Node::setData(const char *new_data) {
    this->data = new char[strlen(new_data)+1];  //allocate memory for string and '\0' character
    strcpy(this->data,new_data);
    return;
}
