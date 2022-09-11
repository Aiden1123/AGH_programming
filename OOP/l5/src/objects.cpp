#include "objects.h"
#include <iostream>
#include <math.h>

///////////////////Point//////////////////////////

Point::Point() {}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::shift(double deltaX,double deltaY) {
    x+= deltaX;
    y+= deltaY;
}

double Point::distance(const Point &a,const Point &b) {
    return sqrt((a.getX() - b.getX())*(a.getX() - b.getX()) + 
                (a.getY() - b.getY())*(a.getY() - b.getY()));
}

std::ostream& operator<<(std::ostream &out, const Point &p) {
   return out<<"("<<p.getX()<<","<<p.getY()<<")";
}

///////////////////Circle//////////////////////////

Circle::Circle(const Point &center, double r) {
    this->center = center;
    this->r = r;
}

void Circle::shift(double deltaX, double deltaY) {
    center.shift(deltaX,deltaY);
}

void Circle::draw() const{
    std::cout<<"Rysujemy kolo o srodku "<<center<<" i promieniu "<<r<<std::endl;
}

double Circle::length() const{
    return r * 2 * 3.14159;
}

double Circle::area() const{
    return r * r * 3.14159;
}

///////////////////Section//////////////////////////

Section::Section(const Point &a, const Point &b) {
    this->a = a;
    this->b = b;
}

void Section::shift(double deltaX, double deltaY) {
    a.shift(deltaX,deltaY);
    b.shift(deltaX,deltaY);
}

void Section::draw() const {
    std::cout<<"Rysujemy odcinek od "<<a<<" do "<<b<<std::endl;
}

double Section::length() const {
    return Point::distance(a,b);
}

const Point &Section::getA() const {
    return a;
}

const Point &Section::getB() const {
    return b;
}

///////////////////Deltoid//////////////////////////

Deltoid::Deltoid(const Section &a,const Section &b) {
    p[0] = a.getA();
    p[1] = b.getA();
    p[2] = a.getB();
    p[3] = b.getB();
}

Deltoid::Deltoid(const Point &a,const Point &b,const Point &c,const Point &d) {
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
}

void Deltoid::shift(double deltaX, double deltaY) {
    for(int i=0;i<4;i++){
        (p[i]).shift(deltaX,deltaY);
    }
}

void Deltoid::draw() const {
    std::cout<<"Rysujemy deltoid o wierzcholkach ";
    for(int i=0;i<4;i++){
        std::cout<<p[i];
        if (i!=3)
            std::cout<<", ";
    }  
    std::cout<<std::endl;
}

double Deltoid::length() const {
    return (Point::distance(p[0],p[1]) + Point::distance(p[1],p[2]))*2; 
}

double Deltoid::area() const {
    return Point::distance(p[0],p[2]) * Point::distance(p[1],p[3]);
}
