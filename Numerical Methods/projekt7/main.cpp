#include <iostream>
#include <math.h>
#include <vector>
#include <functional>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

typedef double (*one_arg_fun)(double);


double bisect(one_arg_fun fun, double start, double end, double eps,int message = 10) {

    double mid;
    int i=0;
    double fstart = fun(start);
    double fmid;
    double fend = fun(end);

    while (0.5 * (end-start) > eps) {
        
        i++;
        mid = (start+end)/2.0;
        fmid = fun(mid);

        if (!fmid) {return mid;}
        else if (fstart*fmid < 0) {
            end = mid;
            fend = fmid;
        }
        else {
            start = mid;
            fstart = fmid;
        }

        if (!(i%message)) {
            std::cout<<"Iteracja: "<<i<<"\tx = "<<mid<<std::endl;
        }

    }   

    return mid;

}


double newton(one_arg_fun fun, one_arg_fun der, double point, double eps, int message = 10) {

    int k=0;

    do {
        
        point = point - (fun(point)/der(point));

        if (!(k%message)) {
            std::cout<<"Iteracja: "<<k<<"\tx = "<<point<<std::endl;
        }

        if (k++ > 10000) {return point;}
    
    }   while(fabs(fun(point)) > eps);

    return point;
}



int size = 2;

double f_zad1_a_1(double x) {
    return 2*x*x + 5 * (3*x*x*x/2) * (3*x*x*x/2) - 2;
}
double f_zad1_a_2(double x) {
    return cos(2*x*x*x) - 3*(2*log(1+x*x)*2*log(1+x*x)*2*log(1+x*x)*2*log(1+x*x)*2*log(1+x*x)) + 1;
}
double f_zad1_a_2_prim(double x) {
    return -sin(2*x*x*x)*6*x*x - 3*(2*5*2*log(1+x*x)*2*log(1+x*x)*2*log(1+x*x)*2*log(1+x*x))*(1/(1+x*x))*2*x;
}

double f_zad2_a_1(double *x) {
    return sin(0.5*x[0] + x[1])/2.0;
}

double f_zad2_a_2(double *x) {
    return 0.5*cos(x[0] - 0.5*x[1]);
}

double f_zad2_b_1(double *x) {
    return -x[0]/(1+x[0]*x[0]) + (1.0/3)*sin(x[1]);
}

double f_zad2_b_2(double *x) {
    return (0.4*cos(x[0]) + x[1]/(3+x[1]*x[1]))/2.0;
}

double f_zad3_a_1(double *x) {
    return 2*x[0]*x[0] + 3*x[1]*x[1]-5;
}

double f_zad3_a_2(double *x) {
    return x[0]*x[0]*x[0] - log(x[1]);
}

double f_zad3_b_1(double *x) {
    return 8*x[0]*x[0]*x[0]+x[1]*x[1]*x[1]-12*x[0]*x[1];
}

double f_zad3_b_2(double *x) {
    return cos(2*x[0])-x[1]*x[1] + 1;
}

double f_zad3_c_1(double *x) {
    return (1.0/5)*(x[0]-1)*(x[0]-1) + x[1]*x[1] + (1.0/3)*x[2]*x[2] - 6;
}

double f_zad3_c_2(double *x) {
    return x[0]*x[0]-2.4*x[0]+2*x[1]*x[1]-x[2] + 0.06;
}

double f_zad3_c_3(double *x) {
    return pow(x[2],1.0/3)+21 * pow(x[0],0.5) + 20*pow(x[1],0.5)-25;
}

void prosteIteracje( std::vector<std::function<double (double *)>> funs,
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

    std::cout<<"Znalezione rozwiazanie"<<std::endl;
    for(int i=0;i<size;i++) {
        std::cout<<startVector[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Sprawdzenie"<<std::endl;
    for(int i=0;i<size;i++) {
        std::cout<<"x"<<i<<": "<<funs[i](startVector)<<std::endl;
    }

    delete[] aux;
}

void newtonRaphson( std::vector<std::function<double (double *)>> funs,
                    double *startVector,  
                    int maxIter) {

    gsl_matrix *D = gsl_matrix_calloc(size,size);
    gsl_matrix *inverse = gsl_matrix_calloc(size,size);                    
    double *aux = new double[size];
    double *startPlusH = new double[size];
    double sum;
    double h = 0.001;
    int s;
    gsl_permutation *p = gsl_permutation_calloc(size);

    for(int i=0;i<maxIter;i++) {
        for(int j=0;j<size;j++) {
            for(int k=0;k<size;k++) {
                startPlusH[k] = startVector[k];
                if (k==j) {
                    startPlusH[k] += h;
                }
            }
            for(int k=0;k<size;k++) {
                 gsl_matrix_set(D,k,j,(funs[k](startPlusH) - funs[k](startVector))/h);
            }
        }

        gsl_linalg_LU_decomp(D,p,&s);
        gsl_linalg_LU_invert(D,p,inverse);

        for(int j=0;j<size;j++) {

            sum = 0;
            for(int k=0;k<size;k++) {
                sum += gsl_matrix_get(inverse,j,k)*funs[k](startVector);
            }

            aux[j] = startVector[j] - sum;
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

    std::cout<<"Znalezione rozwiazanie"<<std::endl;
    for(int i=0;i<size;i++) {
        std::cout<<startVector[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Sprawdzenie"<<std::endl;
    for(int i=0;i<size;i++) {
        std::cout<<"rownanie "<<i+1<<": "<<funs[i](startVector)<<std::endl;
    }
    delete[] aux;
    delete[] startPlusH;                        
}

int main() {

    std::cout<<"Zadanie 1a)"<<std::endl;
    std::cout<<"przedzial startowy [0,10]"<<std::endl;

    double a1_x = bisect(f_zad1_a_1,0,10,1e-6);
    double a1_y = 3*a1_x*a1_x*a1_x/2;

    std::cout<<"Znalezione rozwiazanie: ["<<a1_x<<","<<a1_y<<"]"<<std::endl;
    std::cout<<"Sprawdzenie: "<<std::endl;
    

    std::cout<<"Rownanie 1: "<<2*a1_x*a1_x+5*a1_y*a1_y - 2<<std::endl;
    std::cout<<"Rownanie 2: "<<-3*a1_x*a1_x*a1_x + 2*a1_y<<std::endl;

    std::cout<<std::endl;
    std::cout<<"Zadanie 1b)"<<std::endl;
    std::cout<<"punkt startowy 1"<<std::endl;

    double b1_x = newton(f_zad1_a_2,f_zad1_a_2_prim,1,1e-6);
    double b1_y = 2*log(1+b1_x*b1_x);

    std::cout<<"Znalezione rozwiazanie: ["<<b1_x<<","<<b1_y<<"]"<<std::endl;
    std::cout<<"Sprawdzenie: "<<std::endl;
    

    std::cout<<"Rownanie 1: "<<cos(2*b1_x*b1_x*b1_x)-3*b1_y*b1_y*b1_y*b1_y*b1_y + 1<<std::endl;
    std::cout<<"Rownanie 2: "<<2*log(1+b1_x*b1_x)-b1_y<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Zadanie 2a)"<<std::endl;
    std::cout<<"wektor startowy [0.1,0.1]"<<std::endl;
    std::vector<std::function<double (double *)>> funs;
    funs.push_back(f_zad2_a_1);
    funs.push_back(f_zad2_a_2);

    double startVector[2] = {0.1,0.1};

    prosteIteracje(funs,startVector,100);
    std::cout<<std::endl;

    std::cout<<"Zadanie 2b)"<<std::endl;
    std::cout<<"wektor startowy [0.1,0.1]"<<std::endl;
    
    funs.clear();
    funs.push_back(f_zad2_b_1);
    funs.push_back(f_zad2_b_2);
    startVector[0] = 0.1;
    startVector[1] = 0.1;
    prosteIteracje(funs,startVector,100);
    std::cout<<std::endl;

    std::cout<<"Zadanie 3a)"<<std::endl;
    std::cout<<"wektor startowy [0.47,2.2]"<<std::endl;
    
    funs.clear();
    funs.push_back(f_zad3_a_1);
    funs.push_back(f_zad3_a_2);
    startVector[0] = 0.47;
    startVector[1] = 2.2;
    newtonRaphson(funs,startVector,100);
    std::cout<<std::endl;

    std::cout<<"Zadanie 3b)"<<std::endl;
    std::cout<<"wektor startowy [0.1,0.1]"<<std::endl;
    
    funs.clear();
    funs.push_back(f_zad3_b_1);
    funs.push_back(f_zad3_b_2);
    startVector[0] = 0.1;
    startVector[1] = 0.1;
    newtonRaphson(funs,startVector,100);
    
    size = 3;
    std::cout<<std::endl;

    std::cout<<"Zadanie 3c)"<<std::endl;
    std::cout<<"wektor startowy [0,0,0]"<<std::endl;
    
    funs.clear();
    funs.push_back(f_zad3_c_1);
    funs.push_back(f_zad3_c_2);
    funs.push_back(f_zad3_c_3);
    double startVector2[3] = {0,0,0};
    newtonRaphson(funs,startVector2,100);
}
