#include "Sprzety.h"

char OutputDevice::getOutput() const{
    return this->output;
}

std::string OutputDevice::identifyDevice() const{
    switch(this->getOutput()) {
        case 'K':
            return "komputer";
        case 'D':
            return "DVD";
       }
    return "Nieznany obiekt";
}
