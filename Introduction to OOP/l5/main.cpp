#include <iostream>
#include "lab05.h"


int main(){

  std::cout << "\n>> Let's start it!" << std::endl;
  myArray a;
  printArray(a);
  std::cout << ">> OK, I forgot to define the number of elements. What about now?" << std::endl;
  a.N = 6;
  printArray(a);

  std::cout << "\n\n>> So far, so good... Do you remember recursion? Try it with Fibonacci." << std::endl;
  myArray b;
  std::cout << (fillArrayWithFibonacci(&b, 0) ? "OK!" : "Trying again.") << std::endl;
  std::cout << (fillArrayWithFibonacci(0, 17) ? "OK!" : "One more time.") << std::endl;
  std::cout << (fillArrayWithFibonacci(&b, 17) ? "OK!" : "I give up.") << std::endl;
  printArray(b);

  std::cout << "\n\n>> Let's try to do some fancy staff." << std::endl;
  revert(&b);
  extend(&b, 190);
  extend(&b, 3);
  truncate(&b, 5);
  revert(&b);
  truncate(&b, 9);

  std::cout << "\n>> What if the two arrays couple? Let's check it." << std::endl;
  checkArraySpouse(&a);
  checkArraySpouse(&b);
  std::cout << ">> Will you marry me?" << std::endl;
  myArray c = a;
  marry(&a, &c);
  std::cout << ">> Again, will you marry me?" << std::endl;
  marry(&a, &a);
  std::cout << ">> Last time, will you marry me?" << std::endl;
  marry(&a, &b);
  checkArraySpouse(&a);
  checkArraySpouse(&b);
  std::cout << ">> \"It's your fault! I quit!\"" << std::endl;
  divorce(&a, &b);
  checkArraySpouse(&a);
  checkArraySpouse(&b);

  std::cout << "\n>> The end." << std::endl;

}


/*
// Output: ./Lab05

>> Let's start it!
Cannot print empty array.
>> OK, I forgot to define the number of elements. What about now?
[0,0,0,0,0,0]

>> So far, so good... Do you remember recursion? Try it with Fibonacci.
Wrong number of dimensions.
Trying again.
Empty pointer provided.
One more time.
OK!
[1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597]

>> Let's try to do some fancy staff.
[1597,987,610,377,233,144,89,55,34,21,13,8,5,3,2,1,1] (reverting done)
Wow, you've just gone crazy (207>50).
[1597,987,610,377,233,144,89,55,34,21,13,8,5,3,2,1,1,0,0,0] (extending by 3 done)
[1597,987,610,377,233,144,89,55,34,21,13,8,5,3,2] (truncation by 5 done)
[2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597] (reverting done)
[2,3,5,8,13,21] (truncation by 9 done)

>> What if the two arrays couple? Let's check it.
[0,0,0,0,0,0] has no spouse.
[2,3,5,8,13,21] has no spouse.
>> Will you marry me?
Can't marry my twin
>> Again, will you marry me?
Can't marry myself
>> Last time, will you marry me?
[0,0,0,0,0,0] is paired with [2,3,5,8,13,21]
[2,3,5,8,13,21] is paired with [0,0,0,0,0,0]
>> "It's your fault! I quit!"
[0,0,0,0,0,0] has no spouse.
[2,3,5,8,13,21] has no spouse.

>> The end.
*/
