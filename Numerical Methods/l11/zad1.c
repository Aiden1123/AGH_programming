#include <stdio.h>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#define SIZE 3

typedef double (*fun)(double *);

//funckje

double f0(double *x) {
    return x[0]*x[0] + x[1]*x[1] + x[2]*x[2] - 9;
}

double f1(double *x) {
    return x[0]*x[0] + x[1]*x[1] - 2;
}

double f2(double *x) {
    return x[0] + x[1] - 1;
}

//pochodne

double df0dx0(double *x) {
    return 2*x[0];
}

double df0dx1(double *x) {
    return 2*x[1];
}

double df0dx2(double *x) {
    return 2*x[2];
}



double df1dx0(double *x) {
    return 2*x[0];
}

double df1dx1(double *x) {
    return 2*x[1];
}

double df1dx2(double *x) {
    return 0;
}



double df2dx0(double *x) {
    return 1;
}

double df2dx1(double *x) {
    return 1;
}

double df2dx2(double *x) {
    return 0;
}


int main() {

    fun funs[SIZE][SIZE] = { {df0dx0,df0dx1,df0dx2},
                             {df1dx0,df1dx1,df1dx2},
                             {df2dx0,df2dx1,df2dx2} };

    fun fs[SIZE] = { f0,f1,f2 };


    int iter = 1e2;
    double x[SIZE] = {0.5,1,0.2};
    gsl_vector *delta = gsl_vector_calloc(SIZE);
    gsl_vector *b = gsl_vector_calloc(SIZE);
    gsl_matrix *A = gsl_matrix_calloc(SIZE,SIZE);

    for(int i=0;i<SIZE;i++) {
        gsl_vector_set(delta,i,0);
    }


    for(int k=0;k<iter;k++) {
        for(int i=0;i<SIZE;i++) {
            for(int j=0;j<SIZE;j++) {
                gsl_matrix_set(A,i,j,funs[i][j](x));
            }
        }

        for(int i=0;i<SIZE;i++) {
            gsl_vector_set(b,i,-fs[i](x));
        }
            //tu rozwiazujemy uklad

        for(int i=0;i<SIZE;i++) {
            x[i] += gsl_vector_get(delta,i);
        }
    }

    return 0;
}