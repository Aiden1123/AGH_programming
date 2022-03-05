#include "TwoWayList.h"
#include <cstring>
#include <iostream>

void TwoWayList::prepare() {
    this->head = nullptr;
    this->tail = nullptr;
    return;
}
void TwoWayList::prepend(const char *data) {
    if (this->head) {               //case 1: list is not empty
        Node *aux = this->head;         //store list here
        
        this->head = new Node;          //allocate new node
        
        this->head->setData(data);      //initialise values of new node
        this->head->setNext(aux);
        this->head->setPrev(nullptr);
        
        aux->setPrev(this->head);       //connect new node to the list
    }
    else {                          //case 2: list is empty
        this->head = new Node;          //allocate new node
        
        this->head->setData(data);      //initialise values of new node
        this->head->setNext(nullptr);
        this->head->setPrev(nullptr);
        
        this->tail = this->head;        //update TwoWayList object
    }
    return;
}
void TwoWayList::append(const char *data) {
    if (this->tail) {               //case 1: list is not empty
        Node *aux = this->tail;         //store list here
        
        this->tail = new Node;          //allocate new node
        
        this->tail->setData(data);      //initialise values of new node
        this->tail->setNext(nullptr);
        this->tail->setPrev(aux);
            
        aux->setNext(this->tail);       //connect new node to the List
    }
    else {                          //case 2: list is empty
        this->head = new Node;          //allocate new node
        
        this->head->setData(data);      //initialise values of new node
        this->head->setNext(nullptr);
        this->head->setPrev(nullptr);
        
        this->tail = this->head;        //update TwoWayList object
    }
    return;
}

bool TwoWayList::empty() const {
    return this->head ? false : true;
}
void TwoWayList::dump() const {
    Node *iterator = this->head;
    while(iterator) {                           //print data
        std::cout<<iterator->getData()<<" ";
        iterator = iterator->getNext();
    }
    return;
}
void TwoWayList::dumpBack() const {
    Node *iterator = this->tail;
    while(iterator) {                           //print data backwards
        std::cout<<iterator->getData()<<" ";
        iterator = iterator->getPrev();
    }
    return;
}
void TwoWayList::clear() {
    Node *iterator = this->head;
    Node *aux;
    while(iterator) {                   //for each node:
        aux = iterator->getNext();          //save next node before it disappears
        delete [] iterator->getData();      //deallocate memory used for data
        delete iterator;                    //deallocate memory used for nodes
        iterator = aux;         
    }
    this->head=nullptr;                 //set head and tail to null pointers
    this->tail=nullptr;
    return;
}
Node *TwoWayList::getHead() const {
    return this->head;
}
Node *TwoWayList::getTail() const {
    return this->tail;
}
