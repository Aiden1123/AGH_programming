#include "Data.h"

Data::Data(std::string name,std::vector<double> data) {
    this->name=name;
    this->data=data;
}

void Data::print() const {

    std::cout<<std::setw(2);
    std::cout<<name;
    
    auto print = [](double x) {
        std::cout << "\t"<<x;
    };
    
    std::for_each(data.begin(),data.end(),print);
    std::cout<<std::endl;
}