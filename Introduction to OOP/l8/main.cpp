#include <iostream>
#include "Employee.h"
#include "Task.h"

int main() {
  using std::cout;

  cout<<"Denis\n";
  const Employee denis(2);
  denis.print();

  const Task denisUnfinishedJob(235, denis);
  denis.print();
  
  const Task denisNewJob(745, denis);
  denis.print();

  denisUnfinishedJob.print();


  cout<<"\nMark\n";
  const Employee mark(3);
  mark.print();

  const Task markJobInProgress(311, mark);
  mark.print();
  markJobInProgress.print();

  cout<<"\nDenis and Mark\n";
  mark.print();
  denis.print();

  return 0;
}

/* //OUTPUT: ./Lab08
Denis
Employee print ID=2 tasks:
Employee print ID=2 tasks: 235
Employee print ID=2 tasks: 235 745
Task print value=235 EmployeeID=2

Mark
Employee print ID=3 tasks:
Employee print ID=3 tasks: 311
Task print value=311 EmployeeID=3

Denis and Mark
Employee print ID=3 tasks: 311
Employee print ID=2 tasks: 235 745
*/