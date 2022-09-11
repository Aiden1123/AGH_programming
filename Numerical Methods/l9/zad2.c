#include <stdio.h>
#include <math.h>
#define A1SIZE 5
#define A2SIZE 6

double metoda_rayleigha(int size, double A[size][size], double *x, int iterations);

int main() {

    double A1[A1SIZE][A1SIZE] = { {79,27, 95,28,74},
                                  {27,55, 39, 0,10},
                                  {95,39,118,31,93},
                                  {28, 0, 31,42,27},
                                  {74,10, 93,27,95} };
    double x1[A1SIZE] = {1,2,3,4,5};

    double A2[A2SIZE][A2SIZE] = { {  8, 2.6, 9.6,2.8,7.2, 6.5},
                                  {2.6,13.6, 1.8,6.6,5.4, 3.1},
                                  {9.6, 1.8,16.7,2.7,7.0,14.2},            
                                  {2.8, 6.6, 2.7,4.2,2.7, 2.4},
                                  {7.2, 5.4, 7.0,2.7,9.9, 4.3},
                                  {6.5, 3.1,14.2,2.4,4.3,16.0} };
    double x2[A2SIZE] = {20,40,80,160,100,10};

    int iter = 100;

    double lambda = metoda_rayleigha(A1SIZE,A1,x1,iter);
    printf("macierz A1\n");
    printf("wartosc wlasna: %.4f\n", lambda);
    printf("wektor wlasny:\n");
    for(int i=0;i<A1SIZE;i++) {
        printf("%.2f ", x1[i]);
    }
    printf("\n");

    lambda = metoda_rayleigha(A2SIZE,A2,x2,iter);
    printf("macierz A2\n");
    printf("wartosc wlasna: %.4f\n", lambda);
    printf("wektor wlasny:\n");
    for(int i=0;i<A2SIZE;i++) {
        printf("%.2f ", x2[i]);
    }
    printf("\n");


    return 0;
}

double product(double *vec1, double *vec2, int size) {
    double res = 0;
    for(int i=0;i<size;i++)
        res += vec1[i] * vec2[i];
    
    return res;
}

double dist_sum(double *vec1, double *vec2, int size) {
    double res = 0;
    for(int i=0;i<size;i++)
        res += fabs(vec1[i] - vec2[i]);

    return res;
}

double metoda_rayleigha(int size, double A[size][size], double *x, int iterations) {
    double y[size];
    double r,y_length;
    double prev_r;
    for(int i=0;i<iterations;i++) {
        
        for(int j=0;j<size;j++) {        // y = A*x
            y[j] = 0;
            for(int k=0;k<size;k++) {
                y[j] += A[j][k] * x[k];
            }
        }

        prev_r = r;
        r = product(y,x,size)/product(x,x,size);      //r



        y_length = 0;               //x = y/|y|
        for(int j=0;j<size;j++)
            y_length += y[j] * y[j];
        y_length = sqrt(y_length);

        for(int j=0;j<size;j++)
            y[j] = y[j]/y_length;

        //printf("fabs : %.4f dist_sum : %.4f\n",fabs(prev_r - r),dist_sum(x,y,size));
        if ((fabs(prev_r - r) < 1e-6) && (dist_sum(x,y,size) < 1e-6)) {
            break;
        } 

        for(int j=0;j<size;j++)
            x[j] = y[j];
        
        if (!(i%10)) {
            printf("%d: %.4f\n",i,r);
        }

    }
    return r;
}