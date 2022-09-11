#pragma once
//#include "student.h"
#include <string>
#include <vector>
#include <algorithm>

class Student;

class School {
    
    std::string name;
    int max_students;
    std::vector<Student *> accepted;
    
    public:
    
    School(std::string name,int max_students) {
        
        this->name = name;
        this->max_students = max_students;
        accepted = std::vector<Student *>();
        
    }
    
    std::string getclass() {
        return name;
    }
    
    int getmax() {
        return max_students;
    }
    
    void print() {

        auto print = [](Student *student) { 
            student->print(); 
        };

        std::cout<<name<<" - "<<max_students<<": ";
        if (accepted.empty()) {
            std::cout<<"brak przyjetych";
        }
        else {
            std::for_each(accepted.begin(),accepted.end(),print);
        }
        std::cout<<std::endl;
    }    
};

