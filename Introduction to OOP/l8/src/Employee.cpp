#include <iostream>
#include "Employee.h"

void Employee::print() const{
    std::cout<<"Employee print ID="<<this->id<<" tasks:";   //print id and text
    for(int i=0;i<this->tasks_count;i++) {                  //print tasks' values
        std::cout<<" "<<(this->tasks)[i]->getValue();
    }
    std::cout<<std::endl;
}

int Employee::getId() const {
    return this->id;
}

Employee::Employee(int id) {
    this->id=id;
    this->tasks=nullptr;
    this->tasks_count=0;
}

Employee::~Employee() {
    delete[] this->tasks;
}

void Employee::addTask(Task *new_task) {
    if (this->tasks) {                                  //case 1: at least 1 task already present
        this->tasks_count+=1;                           //increase count
        Task **aux = this->tasks;                       //copy current tasks
        this->tasks = new Task*[this->tasks_count];     //allocate new memory for tasks
        
        for(int i=0;i<this->tasks_count-1;i++) {        //copy old tasks
            (this->tasks)[i] = aux[i];
        }
        
        (this->tasks)[this->tasks_count-1] = new_task;  //add new tasks
        
        delete[] aux;                                   //free memory
    }
    
    else {                                              //case 2: no tasks present so far
        this->tasks_count=1;
        this->tasks = new Task*[1];
        (this->tasks)[0] = new_task;
    }
}

