#pragma once
#include <string>
#include "zelazko.h"

/////////////////////Ubranie////////////////////////

class Ubranie {

    protected:

    double price;       
    unsigned int maxTemp;        //maximal temperature of ironing
    bool ironed;        
    std::string name;

    public:
    
    
    Ubranie(double price, std::string name, unsigned int maxTemp);
    void Wypisz();          //prints information about object to console
    void Prasuj(const Zelazko &iron);   //irons the piece of clothing if iron has accepatble temperature
    void Pogniec();                     //folds piece of clothing    

};

/////////////////////Koszula and its subclasses////////////////////////

class Koszula : public Ubranie{
    
    protected:
    
    bool longSleeve;        
    
    public:
    
    Koszula(double price,std::string name, bool longSleeve, unsigned int maxTemp);
    void Wypisz();      //prints information about object to console
    void SkrocRekawy(); //makes sleeves short
};

class KoszulaBawelniana : public Koszula {

    public:
    KoszulaBawelniana(double price,bool longSleeve);

};

class KoszulaJedwabna : public Koszula {

    public:
    KoszulaJedwabna(double price,bool longSleeve);

};

/////////////////////Spodnie and its subclasses////////////////////////

class Spodnie : public Ubranie {

    protected:
    
    bool Kanty;
    
    public:
    
    Spodnie(double price,std::string name, unsigned int maxTemp);
    void Wypisz();          //prints information about object to console
    void PrasujKanty(const Zelazko &iron);  //irons Kanty

};

class SpodnieBawelniane : public Spodnie {

    public:
    SpodnieBawelniane(double price);

};

class SpodnieJedwabne : public Spodnie {

    public:
    SpodnieJedwabne(double price);

};
