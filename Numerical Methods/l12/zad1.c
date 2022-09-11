#include <stdio.h>
#include <math.h>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#define SIZE 6

double x[] = {-2,-0.5,0.7,1.3,2,6};
double y_dane[] = {7,1,3,-2,8,0};

double wielomian(double x, double *a, int size) {
    double res = 0;
    for(int i=0;i<size;i++) {
        res += a[i] * pow(x,i);
    }
    return res;
}

int main() {
    gsl_vector *a = gsl_vector_calloc(SIZE);
    gsl_vector *y = gsl_vector_calloc(SIZE);
    gsl_matrix *X = gsl_matrix_calloc(SIZE,SIZE);

    for(int i=0;i<SIZE;i++) {
        gsl_vector_set(y,i,y_dane[i]);
        for(int j=0;j<SIZE;j++) {
            gsl_matrix_set(X,i,j,pow(x[i],j));
        }
    }

    printf("macierz X: \n");

    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            printf("%.2f ",gsl_matrix_get(X,i,j));
        }
        printf("\n");
    }

    int s;
    gsl_permutation *p = gsl_permutation_calloc(SIZE);

    gsl_linalg_LU_decomp(X, p, &s);
    gsl_linalg_LU_solve(X, p, y, a);

    printf("otrzymane a: \n");
    for(int i=0;i<SIZE;i++) {
        printf("%f ",gsl_vector_get(a,i));
    }
    printf("\n");

    double a_otrzymane[SIZE];
    for(int i=0;i<SIZE;i++) {
        int target_num = gsl_permutation_get(p,i);
        a_otrzymane[target_num] = gsl_vector_get(a,i);
    }

    for(int i=0;i<SIZE;i++) {
        printf("x: %.2f\ty: %.2f\n",x[i],wielomian(x[i],a_otrzymane,SIZE));
    }

    return 0;
}