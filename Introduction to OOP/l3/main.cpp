/*
 * Tematem zadania jest algorytm weryfikacji numeru karty kredytowej.
 * Prawidłowy numer karty może mieć różną liczbę cyfr, np. 
 * VISA 13 lub 16
 * Master Card 16
 * American Express 15
 * 
 * Weryfikację numeru karty można przeprowadzić algorytmem Luhna:
 * 
 * jeśli numer karty jest krótszy od 16 cyfr to przed numerem dopisujemy zera,
 * kolejne cyfry numeru mnożymy przez współczynniki wagowe,
 * kolejno 2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
 * sumujemy wszystkie _CYFRY_ otrzymanego wyniku,
 * numer karty jest prawidłowy jeśli ostatnia cyfra wyniku sumowania jest równa 0. 
 * 
 * Przykład:
 *  2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1   -> wagi
 * 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 2   -> nr karty 
 * ---------------------------------
 * 2*1 1*2 2*3 1*4 2*5 1*6 2*7 1*8 2*9 1*0 2*1 1*2 2*3 1*4 2*5 1*2  
 * 2   2   6   4  10   6  14   8  18   0   2   2   6   4  10   2 
 * 2 + 2 + 6 + 4+1+0 + 6+1+4 + 8+1+8 + 0 + 2 + 2 + 6 + 4+1+0 + 2=60
 *                     
 *           60 mod 10 = 0 ----> cyfra kontrolna prawidłowa
 * 
 * 
 * Proszę napisac dwie funkcje (i zawrzeć je w nagłówku cardVerificationUtilities.h): 
 * - do obliczania cyfry kontrolnej (getControlNum),
 * - sprawdzającą poprawność numeru (checkNum).
 * 
 * 
 * Uwagi:
 * -  Pliku main.cpp nie wolno modyfikować (Państwa kod będzie sprawdzany z oryginalną wersją pliku main.cpp).
 * -  Przy wykonaniu zadania nie wolno korzystać z pomocy kolegów, internetu, notatek, telefonu, smartwatcha itp.
 *    Próby oszustwa będą zgłaszane do Dziekana i dalej do Rektora (finalnie mogą skutkować wydaleniem ze studiów).
 * -  Można wykorzystać wcześniej przygotowany plik CMakeLists.txt - projekt musi zawierać taki plik,
 *    który umożliwia zbudowanie kodu poprzez 'cmake' bez użycia argumentów wywołania (bez opcji '-D...').
 * -  Proszę pamiętać o odpowiedniej strukturze katalogów (include, src).
 * -  UWAGA - zmienna PROCEED_WITH_VERIFICATION nie może być zdefiniowana w żadnym pliku nagłówkowym!!! W przeciwnym wypadku 0 pkt za output.
 * -  Zadanie wysyłamy na UPEL w formie archiwum ZIP o ustalonym formacie. Proszę pilnować czasu!
 */

#include "cardVerificationUtilities.h"
#include <iostream>
#include "cardVerificationUtilities.h"

int main(){
    const char* cardNum = "4222222222222";
    char ctrl = getControlNum(cardNum);
    
    std::cout << cardNum << "\t" << ctrl << std::endl;
    
    cardNum = "4111111111111111";
    ctrl = getControlNum(cardNum);
    std::cout << cardNum << "\t" << ctrl << std::endl;
    
    #ifdef PROCEED_WITH_VERIFICATION
    cardNum = "4012888888881881"; 
    if( checkNum(cardNum) ){
        std::cout << "number " << cardNum << " is valid " << std::endl; 
    }
    #endif
    
    cardNum = "4222222723122"; 
    if( !checkNum(cardNum) ){
        std::cout << "number " << cardNum << " is invalid " << std::endl; 
    }
    
    return 0;
}

/*
 //Output po uruchomieniu pliku wykonywalnego ./Lab03:
 4222222222222	0
 4111111111111111	0
 number 4012888888881881 is valid 
 number 4222222723122 is invalid 
*/
