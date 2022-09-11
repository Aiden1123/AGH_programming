#pragma once
#include <string>

///////////////////////////Zelazko//////////////////////

class Zelazko {

    protected:

    double price;
    unsigned int maxTemp;       //maximal temperature Zelazko can produce
    unsigned int currTemp;      //current temperature of zelazko
    bool ironed;
    std::string name;

    public:
  
    Zelazko(double price, std::string name,unsigned int maxTemp);  
    void Wypisz() const;        //prints information about object to console
    void UstawTemperature(unsigned int newTemp);    //sets the temperature to newTemp if newTemp is smaller or equal to maxTemp
    int getTemp() const;

};

///////////////////////Zelazko subclasses//////////////////

class ZelazkoPhilips : public Zelazko{
    public:
    ZelazkoPhilips(double price);
};

class ZelazkoTefal : public Zelazko{
    public:
    ZelazkoTefal(double price);
};
