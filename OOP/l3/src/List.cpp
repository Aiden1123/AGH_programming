#include "List.h"
#include <iostream>

List::List() {
    v = std::vector<int>();         //create new vector
}

void List::print() const {
    std::cout<<"[ ";
    for(int i = 0;i<v.size();i++) {
        std::cout<<v[i]<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void List::print(const char *message) const {
    std::cout<<message<<" ";                //print message
    this->print();                          //print vector's elements
}

void List::insert(int x) {
    v.push_back(x);
}

int &List::operator[](int k) {
        return v[k];
}

List List::filter(std::function<bool (int)> fun) const{
    List res;                       //create new list
    for(int i = 0;i<v.size();i++) { //for each element in old list
        if (fun(v[i])) {            //check if functions accepts element    
            res.insert(v[i]);       //if so insert it to new list
        }
    }
    return res;                     //return new list
}
