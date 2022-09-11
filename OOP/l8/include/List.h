#pragma once
#include <iostream>
#include <sstream>
#include <vector>


/**List implemented using vector*/
template<typename T>
class List {

    private:
    std::vector<T> vec; 

    public:

    //default constructor - creates new vector
    List<T>() {              
        vec = std::vector<T>();
    }

    //copy constructor which copies each element of vector
    List(List &old) {
        for(int i=0;i<old.size();i++) {
            vec.push_back(old.get(i));
        }
    }

    //move constructor, copies vector to new list and clears old vector
    List(List &&old) {
        vec = old.vec;
        old.vec.clear();
    }

    //destructor - clears vector
    ~List() {
        vec.clear();
    }

    //adds element to the end of list
    //returns updated list
    List &add(T data) {
        vec.push_back(data);
        return (*this);
    }

    //checks if list contains data, if so returns 1 and 0 otherwise
    int contains(T data) {
        for(int i=0;i<vec.size();i++) {
            if (vec[i] == data) {
                return 1;
            }
        }
        
        return 0;
    }

    //returns size of the list
    int size() const{
        return vec.size();
    }
    
    //returns element with given index in the list
    T get(int i) const{
        return vec[i];
    }
};

//<< overload used for printing to output stream
template<typename T>
std::ostream &operator<<(std::ostream &out,const List<T> &list) {

    for(int i = 0; i < list.size(); i++) {
        out << list.get(i) << " ";
    }

    return out;
}

