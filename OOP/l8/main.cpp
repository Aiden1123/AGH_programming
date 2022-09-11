/*
Celem zadania jest napisanie szablonu listy polaczonej.
Ma to byc najprostsza lista, to znaczy polaczona jednokierunkowo.
Z roznych operacji, ktore oferuje lista potrzebne sa tylko:

+ add - dodajaca na koniec
+ contains - sprawdzajaca czy element o zadanej wartosci jest w liscie
+ operacje kopiowania i przesuwania listy
+ destruktor

UWAGA: kod metod moze sie znajdowac w ciele klasy

*/
#include <string>
#include <utility>
#include <iostream>

#include "List.h"
int main() {
    List<int> l1;
    l1.add(1).add(2).add(0).add(1).add(94);
    std::cout << "orginal " << l1 << std::endl;
    
    List<int> l2 = l1;
    std::cout << "kopia " << l2 << std::endl;

    List<int> l3(std::move(l1));
    std::cout << "orginal po przesunieciu "<< l1 << std::endl;
    std::cout << "w nowym miejscu "<< l3 << std::endl;
    std::cout << "Jest 94? " << l3.contains(94) << " A jest 6? "<<l3.contains(6) << std::endl;


    List<std::string> s;
    s.add("Another").add("brick").add("in").add("the").add("wall");
    std::cout << s << std::endl;
    
}
/* wynik
orginal 1 2 0 1 94
kopia 1 2 0 1 94
orginal po przesunieciu
w nowym miejscu 1 2 0 1 94
Jest 3? 1 A jest 6? 0
Another brick in the wall
*/




