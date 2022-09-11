#include "ubranie.h"
#include <string>
#include <iostream>

///////////////////////////Zelazko//////////////////////

Zelazko::Zelazko(double price, std::string name,unsigned int maxTemp) {

    this->price = price;
    this->maxTemp = maxTemp;
    this->name = name;
    ironed = false;
    currTemp = 0;

}

void Zelazko::Wypisz() const{
    std::cout<<name<<" cena: "<<price<<". "<<"Temperatura "<<currTemp<<"."<<std::endl;
}

void Zelazko::UstawTemperature(unsigned int newTemp) {

    if (newTemp > maxTemp) {
        std::cout<<"Ten model nie obsluguje takiego zakresu temperatur."<<std::endl;
        return;
    }
    
    currTemp = newTemp;
}

int Zelazko::getTemp() const{
    return this->currTemp;
}

///////////////////////Zelazko subclasses//////////////////

ZelazkoPhilips::ZelazkoPhilips(double price) : Zelazko(price,"Philips",5) {}

ZelazkoTefal::ZelazkoTefal(double price) : Zelazko(price,"Tefal",7) {}
