#include "Sprzety.h"
#include <iostream>

Rzutnik::Rzutnik(int w, int h) {
    this->width=w;
    this->height=h;
}

void Rzutnik::Wyswietl(OutputDevice &data)  const{

    std::cout<<"Polaczono rzutnik i "<< data.identifyDevice() << std::endl;

    this->show(data.getOutput());

}
