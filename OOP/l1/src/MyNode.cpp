#include "MyNode.h"

    MyNode::MyNode(int newValue) {
        this->next = nullptr;
        this->value = newValue;
    }

    MyNode *MyNode::getNext() {
        return this->next;
    }

    void MyNode::setNext(MyNode *newNext) {
        this->next = newNext;
    }

    int MyNode::val() {
        return this->value;
    }
