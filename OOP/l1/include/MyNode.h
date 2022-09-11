#pragma once

class MyNode {

    MyNode *next;       //next node
    int value;          //data 

    public:
    MyNode(int newValue);   

    MyNode *getNext();

    void setNext(MyNode *newNext);

    int val();  //returns value
};
