#include <iostream>
#include <string>
#include <sstream>
#include "CyclicList.h"

CyclicList::CyclicList() {
    start = nullptr;        //sets start and end to nullptr
    end = nullptr;
    counter = 0;            //sets counter to 0
}

CyclicList::CyclicList(CyclicList &older) : CyclicList() {
    for(Node *it = older(); it!= nullptr; it = it->getNext()) {
        (*this) << it->clone();         //append deep copy to the list
    }    
}

CyclicList::~CyclicList() {
    Node *it = start;
    Node *aux;
    
    while(it) { 
        aux = it->getNext();
        delete it;                  //free memory allocated for each node
        it = aux;
    }
}
    
CyclicList &CyclicList::operator<<(Node *data) {

    if (start) {            //case 1: list not empty
        end->setNext(data);
        end = data;
    } else {                //case 2: list empty
        start = data;
        end = data;
    }
    
    data->setNext(nullptr);
    counter++;
    
    return *this;           //returns reference to list
}    

Node *CyclicList::operator()() const{
    return start;
}

int CyclicList::count() const {
    return counter;
}

CyclicList &CyclicList::rotate() {

    end->setNext(start);
    end = start;
    start = start->getNext();
    end->setNext(nullptr);

    return *this;
}

CyclicList &CyclicList::rotate_back() {

    end->setNext(start);
    start = end;

    Node *iterator = start;
    while(iterator->getNext() != end) {
        iterator = iterator->getNext();
    }

    end = iterator;
    end->setNext(nullptr);

    return *this;
}

std::ostream &operator<<(std::ostream &out,const CyclicList &list) {
    
    for(Node *it = list(); it!= nullptr; it = it->getNext()) {
        out << it->toString() << " ";
    }
    
    return out;
}
