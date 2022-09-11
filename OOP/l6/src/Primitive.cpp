#include "Primitive.h"
#include <iostream>

Primitive::Primitive(double value) {
    val = value;
}

void Primitive::Set(double value) {
    val = value;
}

void Primitive::print() {
    std::cout<<val;
}

double Primitive::eval() {
    return val;
}
