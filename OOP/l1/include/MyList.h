#pragma once
#include "MyNode.h"
#include <iostream>
#include <initializer_list>
#include <utility>

/**Containter for ints
    implemented as one-way linked list */
class MyList {

    MyNode *head;       //first node
    MyNode *tail;       //last node
    int length;         //number of nodes in container

    public:

    MyList();       //basic constructor

    MyList(int count);      //constructs list with elements from 0 to count (not inclusive)

    MyList(std::initializer_list<int> list);    //constructs list with int given as arguments

    MyList(MyList &cpy);                    //copy constructor

    MyList(MyList &&mv);                    //move constructor

    MyList(int (*fun)(MyNode *),int count); //constructs list with count nodes and assigns them values based on fun

    ~MyList();          //destructor

    void clear();       //clears the list

    void add(int newValue); //adds new value to the list

    bool empty() const;     //checks if the list is empty

    int size() const;       //returns length of the list

    void print() const;     //prints the list to terminal

};