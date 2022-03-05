#include "Sprzety.h"
#include <iostream>

void Screen::show(char x) const{

    for(int i=0;i<this->height;i++) {
    
        for(int j=0;j<this->width;j++) {
            std::cout<<x;
        }
        std::cout<<std::endl;
        
    }
}
