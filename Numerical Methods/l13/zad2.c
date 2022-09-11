#include <stdio.h>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_errno.h"
#include "/usr/include/gsl/gsl_fft_complex.h"
#include <stdlib.h>

#define N 1024
#define PI 3.14159

double f(double x) {
    return 5.3*sin(2*PI*x) - 6.7*sin(2*PI*4*x) + 2.1*sin(2*PI*7*x);
}

int main() {

    double x,y[2*N];

    double start = 0;
    double end = PI;

    for(int i=0;i<N;i++) {

        x = (fabs(end-start)/N) * i + start;

        y[2*i] = f(x) + ((rand() % 2001) - 1000.0)/1000.0;
        y[2*i + 1] = 0;
    }

    FILE *f = fopen("zad2_dane.txt", "w");
    for(int i=0;i<N;i++)
        fprintf(f,"%f\n",y[i]);

    fclose(f);


    f = fopen("zad2_dane.txt", "r");
    for(int i=0;i<N;i++)
        fscanf(f,"%lf",y + i);

    fclose(f);


    gsl_fft_complex_radix2_forward(y, 1, N);
    
    for(int i=0;i<N;i++)
        printf("moc %d^2 = %.2f\n",i,y[2*i]*y[2*i] + y[2*i+1]*y[2*i+1]);
    
    f = fopen("zad2_zrobione.txt", "w");
    for(int i=0;i<N;i++)
        fprintf(f,"%f\n",y[i]);

    fclose(f);

    return 0;
}