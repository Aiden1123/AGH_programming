#include "Sprzety.h"
#include <iostream>

Monitor::Monitor(int w, int h) {
    this->width=w;
    this->height=h;
}

void Monitor::Wyswietl(OutputDevice &data)  const{

    std::cout<<"Polaczono monitor i "<< data.identifyDevice() << std::endl;

    for(int i=0;i<2;i++) {
        for(int j=0;j<this->width;j++)
            std::cout<<"+";
        std::cout<<std::endl;
    }

    this->show(data.getOutput());

    for(int i=0;i<2;i++) {
        for(int j=0;j<this->width;j++)
            std::cout<<"+";
        std::cout<<std::endl;
    }

}
