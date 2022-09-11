#pragma once

/*Drawable shapes*/
class Drawable {
    public:
    double virtual length() const = 0 ;     //returns length or perimeter of given shape
    void virtual draw() const = 0;      
};

/*Geomteric structures that can be moved*/
class Transformable {
    public:
    void virtual shift(double deltaX, double deltaY) = 0;   //moves shape in given direction
};

/*shapes that have finite area*/
class ClosedShape {
    public:
    double virtual area() const = 0;    //returns area of the shape
};
