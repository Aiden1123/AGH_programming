#include <iostream>
#include "lab04.h"


int main(){

  std::cout << "\n>> Let's start it!" << std::endl;
  myContainer a;
  printContainer(a);
  std::cout << ">> OK, I forgot to define the number of elements. What about now?" << std::endl;
  a.N = 6;
  printContainer(a);

  std::cout << "\n\n>> So far, so good... Do you remember recursion? Try it with Fibonacci." << std::endl;
  myContainer b;
  std::cout << (fillContainerWithFibonacci(&b, 0) ? "OK!" : "Trying again.") << std::endl;
  std::cout << (fillContainerWithFibonacci(0, 11) ? "OK!" : "One more time.") << std::endl;
  std::cout << (fillContainerWithFibonacci(&b, 11) ? "OK!" : "I give up.") << std::endl;
  printContainer(b);

  std::cout << "\n>> What if the two Containers couple? Let's check it." << std::endl;
  checkContainerSpouse(&a);
  checkContainerSpouse(&b);
  std::cout << ">> Will you marry me?" << std::endl;
  myContainer c = a;
  marry(&a, &c);
  std::cout << ">> Again, will you marry me?" << std::endl;
  marry(&a, &a);
  std::cout << ">> Last time, will you marry me?" << std::endl;
  marry(&a, &b);
  checkContainerSpouse(&a);
  checkContainerSpouse(&b);
  std::cout << ">> \"It's your fault! I quit!\"" << std::endl;
  divorce(&a, &b);
  checkContainerSpouse(&a);
  checkContainerSpouse(&b);

  std::cout << "\n>> Sometimes children show up." << std::endl;
  myContainer a1 = formChild(0, 0);
  printContainer(a1);
  std::cout << ">>" << std::endl;
  myContainer a2 = formChild(&a, 0);
  printContainer(a2);
  std::cout << ">>" << std::endl;
  formChild(&a, &b);
  std::cout << ">>" << std::endl;
  marry(&a, &b);
  myContainer a3 = formChild(&a, &b);
  printParents(&a);
  printParents(&b);
  printParents(&a3);
  std::cout << "\n>> The end." << std::endl;

}


/*
// Output:

>> Let's start it!
Cannot print empty Container.
>> OK, I forgot to define the number of elements. What about now?
[0,0,0,0,0,0]

>> So far, so good... Do you remember recursion? Try it with Fibonacci.
Wrong number of dimensions.
Trying again.
Empty pointer provided.
One more time.
OK!
[1,1,2,3,5,8,13,21,34,55,89]
>> What if the two Containers couple? Let's check it.
[0,0,0,0,0,0] has no spouse.
[1,1,2,3,5,8,13,21,34,55,89] has no spouse.
>> Will you marry me?
Can't marry my twin
>> Again, will you marry me?
Can't marry myself
>> Last time, will you marry me?
[0,0,0,0,0,0] is paired with [1,1,2,3,5,8,13,21,34,55,89]
[1,1,2,3,5,8,13,21,34,55,89] is paired with [0,0,0,0,0,0]
>> "It's your fault! I quit!"
[0,0,0,0,0,0] has no spouse.
[1,1,2,3,5,8,13,21,34,55,89] has no spouse.

>> Sometimes children show up.
I ain't God.
Cannot print empty Container.
>>
No partenogenesis possible.
Cannot print empty Container.
>>
Only spouses may have children.
>>
[0,0,0,0,0,0] has no parents.
[1,1,2,3,5,8,13,21,34,55,89] has no parents.
Parents of [0,0,0,0,0,0,1,1,2,3,5,8,13,21,34,55,89] are [0,0,0,0,0,0] and [1,1,2,3,5,8,13,21,34,55,89]

>> The end.
*/