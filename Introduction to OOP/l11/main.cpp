#include <iostream>
#include "GradeBook.h"

int main(){

  const Grade arek("Arkadiusz",3.0);
  //arek.SetStudent("Arek"); // error: passing ‘const Grade’ as ‘this’ argument discards qualifiers
  arek.Print("[info]:: ");
  std::cout<<"[info]:: grade value "<< arek.Value(4.0) << std::endl;
  
  GradeBook grades; // przechowuje oceny jako liste/tablice/vector: const Grade*
                    // jeśli ocena przekazana jest przez referencje, tworzona jest kopia tej oceny
  grades.Insert(arek);
  grades.GetPtrConst(0)->Value(5.0); // OK, z tego samego powodu co arek.Value(4.0)
  //grades.GetPtrConst(0)->SetStudent("Arkadiusz"); // error: passing ‘const Grade’ as ‘this’ argument discards qualifiers
  grades.Print("[info]:: GradeBook:: ");
  std::cout<<"\n";
  grades.Insert(new Grade("An", 3.0));
  grades.GetPtr(1)->SetStudent("Anna"); // OK, zwrócony ptr jest na typ Grade*, a wskazywany obiekt nie jest const

  grades.Insert(new const Grade("Jowita", 3.5));
  grades.Print("[info]:: GradeBook:: ");
  //grades.GetPtr(2)->SetStudent("Joanna"); // To może powodować Undefined Behavior, wskazywany obiekt jest const !!!

  return 0;
}

/* // Output: ./Lab11
[info]:: Student (Arkadiusz) grade (ID=1) = 3
[info]:: grade value 4
[info]:: GradeBook:: Student (Arkadiusz COPY) grade (ID=1) = 5

[info]:: GradeBook:: Student (Arkadiusz COPY) grade (ID=1) = 5
[info]:: GradeBook:: Student (Anna) grade (ID=2) = 3
[info]:: GradeBook:: Student (Jowita) grade (ID=3) = 3.5.
*/