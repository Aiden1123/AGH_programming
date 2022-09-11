#pragma once
#include "abstract.h"
#include <iostream>

///////////////////Point//////////////////////////

class Point : public Transformable{

    double x;
    double y;
    
    public:
    
    Point();
    Point(double x, double y);
    double getX() const;
    double getY() const;
    void shift(double deltaX,double deltaY);
    
    double static distance(const Point &a,const Point &b);      //returns distance between 2 points
    
};

std::ostream& operator<<(std::ostream &out, const Point &p);    //<< operator overload


///////////////////Circle//////////////////////////

class Circle : public Drawable, public Transformable, public ClosedShape {
    
    Point center;
    double r;
    
    public:
    
    Circle(const Point &center, double r);
    void shift(double deltaX, double deltaY);
    void draw() const;
    double length() const;
    double area() const;
};

///////////////////Section//////////////////////////

class Section : public Drawable, public Transformable {
    
    Point a;
    Point b;
    
    public:
    
    Section(const Point &a,const Point &b);
    void shift(double deltaX, double deltaY);
    void draw() const;
    double length() const;
    const Point &getA() const;
    const Point &getB() const;
    
};

///////////////////Deltoid//////////////////////////

class Deltoid : public Drawable, public Transformable, public ClosedShape {
    
    Point p[4];
    
    public:
    
    Deltoid(const Section &a,const Section &b);
    Deltoid(const Point &a,const Point &b,const Point &c,const Point &d);
    void shift(double deltaX, double deltaY);
    void draw() const;
    double length() const;
    double area() const;
    
};
