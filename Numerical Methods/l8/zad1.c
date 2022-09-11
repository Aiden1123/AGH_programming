#include <stdio.h>
#include <math.h>

double f_a(double x) {
    return x*x*x + 2*x - 1;
}

double f_b(double x) {
    return x -3*sin(x)-1;
}

double f_c(double x) {
    return x*log(x) + sin(x);
}

double f_d(double x) {
    return exp((-3)*x) + x*x*x*x*x -3*x*x + 1;
}

typedef double (*one_arg_fun)(double); 
double bisect(one_arg_fun fun, double start, double end, double eps);

int main() {

    double eps = 1e-6;

    one_arg_fun funs[4] = {f_a,f_b,f_c,f_d};

    for(int i=0;i<3;i++) {
        printf("miejsce zerowe: %.4f\n", bisect(funs[i],0.1,4,eps));
    }

    printf("miejsce zerowe: %.4f\n", bisect(funs[3],1,2,eps));


    return 0;
}

double bisect(one_arg_fun fun, double start, double end, double eps) {

    double mid;

    double fstart = fun(start);
    double fmid;
    double fend = fun(end);

    while (0.5 * (end-start) > eps) {
        
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

    }   

    return mid;

}