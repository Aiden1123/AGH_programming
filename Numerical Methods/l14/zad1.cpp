#include <iostream>
#include <math.h>

int main() {



    double a = 1;
    double b = 4;

    const int n = 5;
    double z[n+1];
    double x[n+1];

    for(int k=0;k<=n;k++) {
        //std::cout << k <<std::endl;
        z[k] = cos(((2.0*k+1)/(2.0*n+2))*3.14159);
        //std::cout<<z[k]<<std::endl;
        x[k] = (z[k]*(b-a)+a+b)/2;
        std::cout<<x[k]<<std::endl;
    }

    return 0;
}