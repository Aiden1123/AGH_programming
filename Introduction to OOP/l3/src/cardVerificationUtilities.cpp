#include <string.h>
#include <iostream>
#include "cardVerificationUtilities.h"

int digit_sum(int *input) {
    /** 
    Funkcja digit_sum przyjmuje wskaznik do tablicy 16 liczb calkowitych 
    oraz zwraca sume cyfr liczb ktore znajduja sie w tablicy.
    Funkcja wymaga aby cyfry byly maksymalnie dwucyfrowe
    **/
    
    int res = 0; //zmienna trzymajaca wynik   
    
    for(int i=0;i<16;i++) {
    
        if (input[i]<10)    //jezeli liczba jest jednocyfrowa to moze zostac dodana
            res+=input[i];
    
        else {
            res+=input[i]%10;   //jezeli liczba jest dwucyfrowa to najpierw dodawana jest cyfra jednosci
            res+=input[i]/10;   //a potem dziesiatek
        }
    
    }
    return res;
}

int checkNum(const char *card) {
    /** 
    Funkcja checkNum przyjmuje string zawierajacy numer karty
    oraz zwraca wartosc 1 jezeli numer karty jest poprawny
    albo 0 jezeli jest bledny. 
    **/
    int number = getControlNum(card);
    number-=48;     //poprawna konwersja z char na int
    if (number % 10) {
        return 0;
    }
    return 1;
}

char getControlNum(const char *card) {
    /** 
    Funkcja getControlNum przyjmuje string zawierajacy numer karty 
    oraz zwraca cyfre kontrolna jako char.
    **/
    char numbers[16];       //tablica do przechowywania numeru karty z ewentualnymi zerami
    int multiplication[16] = {2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1}; //tablica na ktorej wykonywane sa obliczenia
    int input_length = strlen(card);    //dlugosc wprowadzonego numeru karty
    int i;                              //zmienna sluzaca do iteracji
    for(i=0;i<16 - input_length;i++) {  //ewentualne uzupelnienie zer
        numbers[i] = 48;
    }
    for(;i<16;i++) {                    //przepisanie karty
        numbers[i] = card[i - (16 - input_length)];        
    }
    
    for(i=0;i<16;i++) {                 //pomnozenie cyfr przez wagi
        multiplication[i] = multiplication[i] * (numbers[i]-48); 
    }
    
    return (digit_sum(multiplication) % 10) + 48;  //zwrocenie char ktory reprezentuje uzyskana liczbe kontrolna
}
