#include "Vector2D.h"
#include <iostream>
#include <math.h>
#include <cstring>

int Vector2D::count = 0;        //initialise count to 0 at the start

Vector2D::Vector2D() {
    Vector2D::count++;
}

Vector2D::Vector2D(const Vector2D &vector) {
    vector.print("copying ");
    this->x = vector.x;
    this->y = vector.y;
    Vector2D::count++;
}

Vector2D::Vector2D(const Vector2D &&vector) {
    vector.print("moving ");
    this->x = vector.x;
    this->y = vector.y;
    Vector2D::count++;
}

Vector2D::~Vector2D() {
    Vector2D::count--;          
} 


Vector2D Vector2D::fromCarthesian(double x,double y) {
    Vector2D new_vector;        //create new object
    new_vector.x = x;           //initialise values
    new_vector.y = y;
    return new_vector;          //return object
}

Vector2D Vector2D::fromPolar(double r, double phi) {
    Vector2D new_vector;        //create new object
    new_vector.x = r * cos(phi * 3.14159 / 180);    //convert polar to carthesian and initialise values
    new_vector.y = r * sin(phi * 3.14159 / 180);    
    return new_vector;          //return object
}
        
void Vector2D::print(const char *message) const {
    std::cout<<message<<"("<<this->x<<", "<<this->y<<")"<<std::endl;
    return;
}
double Vector2D::dot(const Vector2D &vector) const {
    return (this->x * vector.x) + (this->y * vector.y);
}
Vector2D Vector2D::add(const Vector2D &vector) const {
    Vector2D new_vector;        //create new object
    new_vector.x = this->x + vector.x;      //add values of two vectors and save them to new vector
    new_vector.y = this->y + vector.y;      
    return new_vector;          //return object
}
