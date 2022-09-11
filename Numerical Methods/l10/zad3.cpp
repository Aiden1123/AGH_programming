//x1 = x - 1/det * ( Df1x(x,y) * f1(x,y) - Df1y(x,y)*f2(x,y));
//y1 = y - 1/det * (-Df2x(x,y) * f1(x,y) + Df1x(x,y)*f2(x,y));

#include <iostream>
#include <math.h>

double f1(double x, double y) {
    return 2*x*x + 3*y*y - 5; 
}

double f2(double x,double y) {
    return x*x*x - ln(y);
}

double Df1x(double x,double y) {
    return 4*x;
}

double Df2x(double x, double y) {
    return 3*x*x;
}



int main() {

}