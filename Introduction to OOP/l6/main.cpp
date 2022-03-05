#include "lab06.h"
#include <iostream>
#include "lab06.h"

int main(){

  const double* sequence_1 = initGeometricalSequence(1, -0.5, 0);
  sequence_1 = initGeometricalSequence(1, -0.5, 8);
  const double* sequence_2 = initArithmeticSequence(0, 0.5, 5);
  
  std::cout << "----------" << std::endl;

  printSequence(sequence_1, 0);
  printSequence(sequence_1, 8);
  printSequence(sequence_2, 3);
  
  deleteSequence(&sequence_1);
  deleteSequence(&sequence_1);
  deleteSequence(&sequence_2);

  std::cout << "----------" << std::endl;

  const double** sequencesList = 0;
  int* sequencesLenghtsList = 0;

  for(int i=0; i<3; ++i){
    int length = 3*i+1;
    addSequence(&sequencesList, &sequencesLenghtsList, initGeometricalSequence(1+i, -0.5 * (i+1), length), length);
    addSequence(&sequencesList, &sequencesLenghtsList, initArithmeticSequence(2+i, 0.5 * (i+1), length), length);
  }
  
  std::cout << "All sequences added so far: " << std::endl;
  printSequence(sequencesList, sequencesLenghtsList);

  std::cout << "----------" << std::endl;

  deleteSequence(sequencesList, sequencesLenghtsList);
}

/* //OUTPUT: ./Lab06
Size must be non-zero (and positive)
----------
Nothing to print.
(1,-0.5,0.25,-0.125,0.0625,-0.03125,0.015625,-0.0078125)
(0,0.5,1)
Sequence deleted.
Nothing to delete.
Sequence deleted.
----------
All sequences added so far: 
Sequence 1: (1)
Sequence 2: (2)
Sequence 3: (2,-2,2,-2)
Sequence 4: (3,4,5,6)
Sequence 5: (3,-4.5,6.75,-10.125,15.1875,-22.7812,34.1719)
Sequence 6: (4,5.5,7,8.5,10,11.5,13)
----------
Sequence deleted.
Sequence deleted.
Sequence deleted.
Sequence deleted.
Sequence deleted.
Sequence deleted.
*/
