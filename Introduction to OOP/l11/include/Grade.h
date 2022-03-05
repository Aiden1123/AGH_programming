#pragma once
#include <cstring>

class Grade {
    
    private:
    
    mutable double value;
    char *name;
    int id;
    int static count;
    
    public:
    
    Grade(const char *new_name, double new_value);
    Grade(const Grade &original);
    ~Grade();
    void SetStudent(const char *new_name);
    void Print(const char *message) const;
    double Value(double new_value) const;
};
