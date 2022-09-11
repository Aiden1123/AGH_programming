#include "ubranie.h"
#include "zelazko.h"
#include <string>
#include <iostream>

//////////////////////Ubranie/////////////////////////

Ubranie::Ubranie(double price, std::string name, unsigned int maxTemp = 9) {
    this->price = price;
    this->name = name;
    this->maxTemp = maxTemp;
    ironed = false;
}

void Ubranie::Wypisz() {
    std::cout<<name<<" cena: "<<price<<". "<<(ironed ? "Wyprasowane. " : "Pogniecione. "); 
}

void Ubranie::Pogniec() {
    this->ironed = false;
}

void Ubranie::Prasuj(const Zelazko &iron) {
    if (iron.getTemp() > maxTemp) {
        std::cout<<"Zelazko za gorace."<<std::endl;
    }
    else if (ironed) {
        std::cout<<"---Ubranie nie wymaga prasowania."<<std::endl;
    }
    else {
        std::cout<<"---Prasuje "<<name<<" zelazkiem o temp. "<<iron.getTemp()<<"."<<std::endl;
        ironed = true;
    }
}

//////////////////////Koszula/////////////////////////

Koszula::Koszula(double price,std::string name, bool longSleeve, unsigned int maxTemp = 9) : Ubranie(price,name,maxTemp) {
    this->longSleeve = longSleeve;
}

void Koszula::Wypisz() {
    std::cout<<name<<" cena: "<<price<<". "<<(ironed ? "Wyprasowane. " : "Pogniecione. ")<<(longSleeve ? "Dlugi rekaw. " : "Krotki rekaw. ")<<std::endl; 
}

void Koszula::SkrocRekawy() {
    this->longSleeve = false;
}

//////////////////////Koszula subclasses/////////////////////////

KoszulaBawelniana::KoszulaBawelniana(double price,bool longSleeve) : Koszula (price,"Koszula bawelniana",longSleeve,7) {}

KoszulaJedwabna::KoszulaJedwabna(double price,bool longSleeve) : Koszula (price,"Koszula jedwabna",longSleeve,3) {}

//////////////////////Spodnie/////////////////////////

Spodnie::Spodnie(double price,std::string name, unsigned int maxTemp)  : Ubranie(price,name,maxTemp) {
    this->Kanty = false;
}

void Spodnie::Wypisz() {
    std::cout<<name<<" cena: "<<price<<". "<<(ironed ? "Wyprasowane. " : "Pogniecione. ")<<(Kanty ? "Kanty. " : "Brak kantow. ")<<std::endl; 
}

void Spodnie::PrasujKanty(const Zelazko &iron) {
    if (iron.getTemp() > maxTemp) {
        std::cout<<"Zelazko za gorace."<<std::endl;
    }
    else if (Kanty) {
        std::cout<<"Ubranie ma Kanty."<<std::endl;
    }
    else {
        std::cout<<"---Prasuje nogawki "<<name<<" zelazkiem o temp."<<iron.getTemp()<<std::endl;
        Kanty = true;
    }
}

//////////////////////Spodnie subclasses/////////////////////////

SpodnieJedwabne::SpodnieJedwabne(double price) : Spodnie(price,"Spodnie jedwabne",3) {}

SpodnieBawelniane::SpodnieBawelniane(double price) : Spodnie(price,"Spodnie bawelniane",7) {}

