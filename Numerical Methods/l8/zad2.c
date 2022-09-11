#include <stdio.h>
#include <math.h>

double f_a(double x) {
    return x*x*x*x*x + 3*x*x*x +2;
}

double f_a_prim(double x) {
    return 5*x*x*x*x + 9*x*x;
}

double f_b(double x) {
    return exp(x) - x*x - 1;
}

double f_b_prim(double x) {
    return exp(x) - x*2;
}

double f_c(double x) {
    return atan(x) - x/(x*x+1);
}

double f_c_prim(double x) {
    return 1/(x*x+1) - (1-x*x)/((x*x + 1)*(x*x + 1));
}

double f_d(double x) {
    return sin(sin(x));
}

double f_d_prim(double x) {
    return cos(sin(x))*cos(x);
}

typedef double (*one_arg_fun)(double); 
double newton(one_arg_fun fun, one_arg_fun der, double point, double eps);

int main() {
    
    double eps = 1e-6;

    one_arg_fun funs[4] = {f_a,f_b,f_c,f_d};
    one_arg_fun funs_ders[4] = {f_a_prim,f_b_prim,f_c_prim,f_d_prim};

    for(int i=0;i<4;i++) {
        printf("miejsce zerowe: %.4f\n", newton(funs[i],funs_ders[i],10,eps));
    }
    
    return 0;
}

double newton(one_arg_fun fun, one_arg_fun der, double point, double eps) {

    double f,fprim;
    f = fun(point);
    int k=0;

    do {
    
        point = point - (fun(point)/der(point));
    
        if (k++ < 10000) {return point;}
    
    }   while(fabs(fun(point)) > eps);

    return point;
}