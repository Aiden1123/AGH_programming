#pragma once
#include "Task.h"

class Task;

class Employee{
    /**contains information about single employee's id and their tasks */
    private:
        int id;             //id of employee
        Task **tasks;       //list of tasks
        int tasks_count;    //number of tasks
    public:
        Employee(int id);
        /**constructor which takes id of the employee as parameter */
        ~Employee();
        /**Destructor used to deallocate memory */
        void print() const;
        /**Prints information about employee to terminal*/
        int getId() const;
        void addTask(Task *new_task);
        /**Adds new Task object to employee's task list*/
};
