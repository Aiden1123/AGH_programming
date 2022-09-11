#include <iostream>
#include <math.h>

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

double falsi(one_arg_fun fun, double start, double end, double eps,int message = 10) {

    double x;
    int i = 0;
    double fstart = fun(start);
    double fx;
    double fend = fun(end);

    while (0.5 * fabs(end-start) > eps) {
        
        i++;
        x = (start*fend-end*fstart)/(fend-fstart);
        fx = fun(x);

        if (!fx) {return x;}
        else if (fstart*fx < 0) {
            end = x;
            fend = fx;
        }
        else {
            start = x;
            fstart = fx;
        }

        if (!(i%message)) {
            std::cout<<"Iteracja: "<<i<<"\tx = "<<x<<std::endl;
        }

    }   

    return x;

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

double f_zad1_a(double x) {
    return x*x*x + 2*x - 1;
}

double f_zad1_b(double x) {
    return x -3*sin(x)-1;
}

double f_zad1_c(double x) {
    return x*log(x) + sin(x);
}

double f_zad1_d(double x) {
    return exp((-3)*x) + x*x*x*x*x -3*x*x + 1;
}

double f_zad2_a(double x) {
    return x*x*x*x*x + 3*x*x*x +2;
}

double f_zad2_a_prim(double x) {
    return 5*x*x*x*x + 9*x*x;
}

double f_zad2_b(double x) {
    return exp(x) - x*x - 1;
}

double f_zad2_b_prim(double x) {
    return exp(x) - x*2;
}

double f_zad2_c(double x) {
    return atan(x) - x/(x*x+1);
}

double f_zad2_c_prim(double x) {
    return 1/(x*x+1) - (1-x*x)/((x*x + 1)*(x*x + 1));
}

double f_zad2_d(double x) {
    return sin(sin(x));
}

double f_zad2_d_prim(double x) {
    return cos(sin(x))*cos(x);
}

double root(double c, int n, int iterNum) {
    double x = 10;

    for(int i=0;i<iterNum;i++) {
        x = x - (pow(x,n)-c)/(n*pow(x,n-1));
    }

    return x;
}

double f1(double x) {
    return x*x - 5;
}

double f1_prim(double x) {
    return 2*x;
}

double f2(double x) {
    return x-300;
}

double f2_prim(double x) {
    return 1;
}

int main() {

    double res;
    double eps = 1e-6;

    //1a
    std::cout<<"Funkcja x^3+2x-1"<<std::endl;
    res = bisect(f_zad1_a,0,1,eps);
    std::cout<<"Znalezione miejsce zerowe: "<<res<<std::endl;
    std::cout<<"------------"<<std::endl;

    //1b
    std::cout<<"Funkcja x-3sinx-1"<<std::endl;
    res = bisect(f_zad1_b,-1,2,eps);
    std::cout<<"Znalezione miejsce zerowe: "<<res<<std::endl;
    std::cout<<"------------"<<std::endl;

    //1c
    std::cout<<"Funkcja xlnx+sinx"<<std::endl;
    res = bisect(f_zad1_c,0.1,1,eps);
    std::cout<<"Znalezione miejsce zerowe: "<<res<<std::endl;
    std::cout<<"------------"<<std::endl;

    //1d
    std::cout<<"Funkcja e^(-3x)+x^5-3x^2+1"<<std::endl;
    res = bisect(f_zad1_d,1,4,eps);
    std::cout<<"Znalezione miejsce zerowe: "<<res<<std::endl;
    std::cout<<"------------"<<std::endl;

    //2a
    std::cout<<"Funkcja x^5+3x^3+2"<<std::endl;
    res = newton(f_zad2_a,f_zad2_a_prim,-1,eps);
    std::cout<<"Znalezione miejsce zerowe: "<<res<<std::endl;
    std::cout<<"------------"<<std::endl;
    
    //2b
    std::cout<<"Funkcja e^x-x^2-1"<<std::endl;
    res = newton(f_zad2_b,f_zad2_b_prim,-1,eps);
    std::cout<<"Znalezione miejsce zerowe: "<<res<<std::endl;
    std::cout<<"------------"<<std::endl;
    
    //2c
    std::cout<<"Funkcja arctan(x)-x/(x^2+1)"<<std::endl;
    res = newton(f_zad2_c,f_zad2_c_prim,-1,eps);
    std::cout<<"Znalezione miejsce zerowe: "<<res<<std::endl;
    std::cout<<"------------"<<std::endl;
    
    //2d
    std::cout<<"Funkcja sin(sin(x))"<<std::endl;
    res = newton(f_zad2_d,f_zad2_d_prim,-1,eps);
    std::cout<<"Znalezione miejsce zerowe: "<<res<<std::endl;
    std::cout<<"------------"<<std::endl;

    //3
    std::cout<<"Square root of 4: "<<root(4,2,100)<<std::endl;
    std::cout<<"81^(1/4) : "<<root(81,4,100)<<std::endl;

    std::cout<<bisect(f1,0,10,eps,1)<<std::endl;
    std::cout<<newton(f1,f1_prim,10,eps,1)<<std::endl;
    std::cout<<bisect(f2,200,350,eps,1)<<std::endl;
    std::cout<<newton(f2,f2_prim,50,eps,1)<<std::endl;
}