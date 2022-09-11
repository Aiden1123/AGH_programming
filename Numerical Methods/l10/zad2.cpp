#include <iostream>
#include <math.h>
#include <vector>
#include <functional>

int size = 2;

double f1(double *x) {
    return -0.5*cos(x[0]) + 0.1*x[1]*x[1];
}

double f2(double *x) {
    return 0.34*sin(x[0]) + 0.5*x[1]*x[1]*x[1]*x[1];
}

double g1(double *x) {
    return 0.5*cos(x[1]*x[1] + x[2]) + 0.2*sin(sqrt(x[0]*x[1]));
}

double g2(double *x) {
    return 0.2*sin(x[0])*sin(x[0]) + 0.1*cos(x[1] + x[2])*cos(x[1] + x[2]);
}

double g3(double *x) {
    return 0.1*sin(x[0]*x[1]*x[2]) + 1/(10 + x[0]*x[0] + x[2]*x[2]);
}

void FixedPoint2D ( std::vector<std::function<double (double *)>> funs,
                    double *startVector,  
                    int maxIter) {
    
    double *aux = new double[size];

    for(int i=0;i<maxIter;i++) {
        
        for(int j=0;j<size;j++) {
            aux[j] = (funs[j])(startVector);
        }
        for(int j=0;j<size;j++) {
            startVector[j] = aux[j];
        }

        if (!(i%10)) {
            std::cout <<"i: " <<i ;
            for(int j=0;j<size;j++) {
                std::cout<< "\tx[" << j << "]: " << startVector[j];
            }
            std::cout<<std::endl;
        }
    }

    delete[] aux;
}

int main() {

    std::vector<std::function<double (double *)>> funs;
    funs.push_back(f1);
    funs.push_back(f2);

    double startVector[2] = {0.1,-0.1};

    FixedPoint2D(funs,startVector,100);
 
    size = 3;

    std::vector<std::function<double (double *)>> funs2;
    funs2.push_back(g1);
    funs2.push_back(g2);
    funs2.push_back(g3);
 
    double startVector2[3] = {0,0,0};

    FixedPoint2D(funs2,startVector2,100);

    return 0;

}