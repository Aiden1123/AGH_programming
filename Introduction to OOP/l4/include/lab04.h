#include <iostream>
#define MAX_SIZE 30

struct myContainer {
    /** Struktura opisujaca kontener tablicy */
    int N;
    int array[MAX_SIZE];
    myContainer *spouse;
    myContainer *parent_a;
    myContainer *parent_b;
    myContainer(){
        N=0;
        for(int i=0;i<MAX_SIZE;i++) {
            array[i]=0;
        }
        spouse=nullptr;
        parent_a=nullptr;
        parent_b=nullptr;
    }
};

void printContainer(myContainer cont);
/** wypisuje zawartosc kontenera w terminalu */

int fillContainerWithFibonacci(myContainer *cont, int size);
/** wypelnia size elementow tablicy cont ciagiem fibonacciego zaczynajac
    od dwoch "1". jezeli size przekracza rozmiar tablicy to tablica nie jest wypelniania 
    Zwraca 1 jezeli operacja zakonczyla sie poprawnie lub 0 w przeciwnym wypadku */
                                                                                        
void checkContainerSpouse(myContainer *cont);
/** sprawdza czy cont posiada spouse i wypisuje stosowny komunikat w terminalu */

void marry(myContainer *a, myContainer *b);
/** laczy a i b w malzenstwo pod warunkiem ze a i b nie sa takie same */

void divorce(myContainer *a, myContainer *b);
/** pozbawia a i b malzonka*/

myContainer formChild(myContainer *a, myContainer *b); 
/** tworzy dziecko z a i b pod warunkiem ze a i b istnieja oraz sa malzenstwem 
    zwraca dziecko powstale z posrod a i b lub w przypadku niepowodzenia zwraca
    dziecko z 0 rozmiarem*/

void printParents(myContainer *cont);
/**wypisuje informacje o rodzicach w terminalu*/
