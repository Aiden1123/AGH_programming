#include <stdio.h>
#include <math.h>

double f1(double x, double y) {
    return -0.5*cos(x) + 0.1*y*y;
}

double f2(double x, double y) {
    return 0.34*sin(x) + 0.5*y*y*y*y;
}


void FixedPoint2D(double x, double y,int maxIter) {

    double x1;

    for(int i=0;i<maxIter;i++) {
        
        x1 = f1(x,y);
        y = f2(x,y);
        
        x = x1;

        if (!(i%10)) {
            printf("%d:\tx:%.4f\ty:%.4f\n",i,x,y);
        }
    }
}

int main() {

    FixedPoint2D(0.21,0,100);
    return 0;
}