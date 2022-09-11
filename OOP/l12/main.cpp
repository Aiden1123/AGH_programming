 /* Celem zadania jest przeÄ‡wiczenie podstawowych algorytmĂłw STL. 
  Stworzymy klasÄ™ reprezentujÄ…cÄ… tablicÄ™ danych. MoĹĽna jÄ… sortowaÄ‡ na rĂłĹĽne sposoby.
 
 UWAGA!
    Zadanie naleĹĽy wykonaÄ‡ bez ĹĽadnych tradycyjnych pÄ™tli ze standardowego C (nawet w print), lecz z pomocÄ… tych dedykowanych kontenerom STL oraz iteratorĂłw.
	For dla kontenerĂłw jest OK, ale proszÄ™ choÄ‡ raz skorzystaÄ‡ z for_each.

 WskazĂłwki:
 - wypisanie rĂłwnej liczby znakĂłw: std::cout<<std::setw(liczba) -- nagĹ‚Ăłwek iomanip 
 - moĹĽe siÄ™ przydaÄ‡ namespace std::placeholders
 - moĹĽna korzystaÄ‡ z dokumentacji do algorytmĂłw: np. http://www.cplusplus.com/reference/
*/

#include "Sum.h"
#include "Data.h"
#include "Table.h"
#include <iostream>

bool greaterSum(const Data& d1, const Data& d2){
	return sumData(d1).value() < sumData(d2).value();
}

int main(){
	const Data day1("Monday", {1.5, 2, -3.2});
	day1.print();

	Sum suma = sumData(day1);
	std::cout << "suma z niedzieli: " << suma.value() << std::endl;
	suma(2); // to pokazuje co robi Sum
	std::cout << "suma z niedzieli + 2: " << suma.value() << std::endl;

	std::cout << "   ============= Table =============" << std::endl;
 	Table table;
	table += day1;
	table += Data("Friday", {3, 2.5, 13, 2});
	table += Data("Sunday", {1, -12.5, 1.3, 1.5, 12.3});

	table.print();
	std::cout << "======= sortowanie po kolumnie 3 =======" << std::endl;
	table.sort(2).print(); 

	std::cout << "======= sortowanie po kolumnie 2 =======" << std::endl;
	table.sort(1).print(); 

	table.sort(3); // uwaga, tutaj niedozwolony indeks 
	std::cout << "========= sortowanie po sumach =========" << std::endl;
	table.sortBy(greaterSum).print(); // sortowanie po zsumowanych kolumnach, rosnÄ…co
}

/* wynik dziaĹ‚ania programu:

Monday:    1.5     2  -3.2
suma z niedzieli: 0.3
suma z niedzieli + 2: 2.3
   ============= Table =============
Monday:    1.5     2  -3.2
Friday:      3   2.5    13     2
Sunday:      1 -12.5   1.3   1.5  12.3

======= sortowanie po kolumnie 3 =======
Monday:    1.5     2  -3.2
Sunday:      1 -12.5   1.3   1.5  12.3
Friday:      3   2.5    13     2

======= sortowanie po kolumnie 2 =======
Sunday:      1 -12.5   1.3   1.5  12.3
Monday:    1.5     2  -3.2
Friday:      3   2.5    13     2

Indeks 3 nieprawidlowy! 
========= sortowanie po sumach =========
Monday:    1.5     2  -3.2
Sunday:      1 -12.5   1.3   1.5  12.3
Friday:      3   2.5    13     2

*/