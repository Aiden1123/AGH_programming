#include <iostream>
#include "Task.h"

int Task::getValue() const {
    return this->value;
}
void Task::print() const {
    std::cout<<"Task print value="<<this->value
             <<" EmployeeID="<<this->employee_id<<std::endl; 
}

Task::Task(int value, const Employee &employee) {
    this->value = value;                        //initialise object's variables
    this->employee_id = employee.getId();
    Employee &employeee = (Employee &) employee;    //get rid of const
    employeee.addTask(this);                        //add task to employee's list
}
