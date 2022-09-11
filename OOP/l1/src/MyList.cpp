#include "MyList.h"
#include "MyNode.h"
#include <iostream>
#include <initializer_list>
#include <utility>

    MyList::MyList() {
        std::cout<<"KONST: Domyslny"<<std::endl;
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    MyList::MyList(int count) : MyList(){
        std::cout<<"KONST: Jednoargumentowy"<<std::endl;

        for(int i=0;i<count;i++) {
            this->add(i);
        }  
    }

    MyList::MyList(std::initializer_list<int> list) {
        std::cout<<"KONST: std::initializer_list"<<std::endl;
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0; 
        
        for(const int *i=list.begin();i<list.end();i++) {
            this->add(*i);
        }  
    }

    MyList::MyList(MyList &cpy)  : MyList() {
        std::cout<<"KONST: kopiujacy"<<std::endl;
        
        for(MyNode *it = cpy.head;it != nullptr;it = it->getNext()) {
            this->add(it->val());
        }
    }

    MyList::MyList(MyList &&mv) {
        std::cout<<"KONST: przenoszacy"<<std::endl;
        this->head = nullptr;
        this->tail = nullptr;
        mv.head = std::exchange(this->head,mv.head);
        mv.tail = std::exchange(this->tail,mv.tail);
        this->length = mv.length;
        mv.length = 0;
    }

    MyList::MyList(int (*fun)(MyNode *),int count) {
        std::cout<<"KONST: funkcja generujaca"<<std::endl;
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;

        for(int i=0;i<count;i++) {
            this->add(fun(this->tail));
        }
    }

    MyList::~MyList() {
        std::cout<<"DESTRUKTOR (rozmiar="<<this->length<<")"<<std::endl;
        this->clear();
    }

    void MyList::clear() {
        MyNode *aux;
        MyNode *it = this->head;

        while(it) {
            aux = it->getNext();
            delete it;
            it = aux;
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    void MyList::add(int newValue) {

        if (!(this->head)) {
            this->head = new MyNode(newValue);
            this->tail = this->head;
        }
        else {
            this->tail->setNext(new MyNode(newValue));
            this->tail = this->tail->getNext();
        }
        this->length += 1;
    }

    bool MyList::empty() const{
        return this->head ? false : true;
    }

    int MyList::size() const{
        return this->length;
    }

    void MyList::print() const{
        std::cout<<"[";
        for(MyNode *it = this->head;it != nullptr; it = it->getNext()) {
            std::cout<<it->val();
            if (it->getNext()) {
                std::cout<<", ";
            }
        }
        std::cout<<"]"<<std::endl;
    }