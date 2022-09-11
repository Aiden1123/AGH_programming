#pragma once
//#include "student.h"
//#include "school.h"
#include <vector>

class Student;
class School;
class Table {
    
    std::vector<Student> students;
    std::vector<School *> schools;
    
    public:
    
    Table(std::vector<Student> students) {
        this->students = students;
        this->schools = std::vector<School *>();
    }
    
    Table(std::vector<School *> schools) {
        this->students = std::vector<Student>();
        this->schools = schools;
    }
    
    
    Table(School *new_school) {
        this->students = std::vector<Student>();
        this->schools = std::vector<School *>();
        schools.push_back(new_school);
    }
    
    void operator+=(Student new_student) {
        students.push_back(new_student);
    }
    
    void operator+=(School *new_school) {
        schools.push_back(new_school);
    }
    
    void sortpoints() {
        auto cmp = [](Student a, Student b) { 
            return a.getPoints() > b.getPoints(); 
        };
        std::sort(students.begin(),students.end(),cmp);
    }
    
    void printStud() {
        auto print = [](Student student) { 
            student.print(); 
        };
        std::for_each(students.cbegin(), students.cend(), print);
    }

    double getAverageStudScore() {
        double sum=0;
        auto sum_fun = [&sum](Student student) {
            sum+=student.getPoints();
        };
        std::for_each(students.cbegin(), students.cend(), sum_fun);
        return sum/students.size();
    }

    void printRecruit() {
        auto print = [](School *school) { 
            school->print(); 
        };
        std::for_each(schools.begin(),schools.end(),print);
    }
};
