#pragma once
//#include "school.h"
#include <string>
#include <vector>
#include <algorithm>

//class School;

class Student {

    std::string name;
    int points;
    std::vector<School *> wishlist;
    School *assigned_school;
    
    public:
    
    Student(std::string name, int points, std::vector<School *> wishlist) {
        this->name = name;
        this->points = points;
        this->wishlist = wishlist;
        assigned_school = nullptr;
    }
    
    int getPoints() {
        return points;
    }
    
    void print() {
        std::cout<<name<<": "<<points<<" [ ";
        auto print = [](School *school) { 
            std::cout << school->getclass() << " "; 
        };
        std::for_each(wishlist.cbegin(), wishlist.cend(), print);
        std::cout<<"] --> "<< (assigned_school ? assigned_school->getclass() : "nieprzyjetx");
        std::cout<<std::endl;
    }
};


