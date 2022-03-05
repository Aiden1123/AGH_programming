#pragma once
#include "Employee.h"

class Employee;

class Task{
    /**holds information about task*/
    private:
        int value;          //Number of task
        int employee_id;    //id of employee responsible for the task
    public:
        int getValue() const;
        void print() const;
        /**prints information about task to terminal*/
        Task(int value, const Employee &employee);
        /**constructor which takes value of task and Employee as parameters */ 
};
