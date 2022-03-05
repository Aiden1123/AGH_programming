#include "Sprzety.h"
#include <iostream>

TelewizorLCD::TelewizorLCD(int w, int h) {
    this->width=w;
    this->height=h;
}

void TelewizorLCD::Wyswietl(OutputDevice &data)  const{

    std::cout<<"Polaczono telewizor i "<< data.identifyDevice() << std::endl;

    for(int j=0;j<this->width;j++)
        std::cout<<"*";
    std::cout<<std::endl;


    this->show(data.getOutput());

    
    for(int j=0;j<this->width;j++)
        std::cout<<(j%2 ? " ": "*" );
    std::cout<<std::endl;
    
    for(int j=0;j<this->width;j++)
        std::cout<<(j%2 ? "&": " " );
    std::cout<<std::endl;
    
    for(int j=0;j<this->width;j++)
        std::cout<<(j%2 ? " ": "*" );
    std::cout<<std::endl;

}
