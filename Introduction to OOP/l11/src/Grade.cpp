#include <cstring>
#include <iostream>
#include "Grade.h"

int Grade::count = 0;

Grade::Grade(const char *new_name, double new_value) {
    this->name = new char[strlen(new_name) + 1];
    strcpy(this->name,new_name);
    this->value = new_value;
    Grade::count += 1;
    this->id = Grade::count;
}

Grade::Grade(const Grade &original) {
    this->name = new char[strlen(original.name) + strlen(" COPY") + 1];
    strcpy(this->name,original.name);
    strcat(this->name," COPY");
    
    this->value = original.value;
    this->id = original.id;
}

Grade::~Grade() {
    delete[] this->name;
}

void Grade::SetStudent(const char *new_name) {
    delete[] this->name;
    this->name = new char[strlen(new_name) + 1];
    strcpy(this->name,new_name);
    return;
}

void Grade::Print(const char *message) const {
    std::cout<<message<<"Student ("<<this->name<<") grade (ID="<<this->id<<") = "<<this->value<<std::endl;
}

double Grade::Value(double new_value) const {
    this->value = new_value;
    return this->value;
}
