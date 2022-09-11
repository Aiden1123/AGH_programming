#include <stdio.h>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_errno.h"
#include "/usr/include/gsl/gsl_fft_complex.h"
#include <stdlib.h>

#define N 128
#define PI 3.14159

double f(double x) {
    return 5.3*cos(2*PI*x) - 8*sin(PI*4.2*x) + 2.1*cos(2*PI*7*x)+ 0.7*cos(PI*15*x);
}

int main() {

    gsl_fft_complex_wavetable *wavetable = gsl_fft_complex_wavetable_alloc(N);
    gsl_fft_complex_workspace *workspace = gsl_fft_complex_workspace_alloc(N);
    double x,y[2*N];

    double start = 0;
    double end = 4*PI;

    for(int i=0;i<N;i++) {

        x = (fabs(end-start)/N) * i + start;

        y[2*i] = f(x) + ((rand() % 2001) - 1000.0)/1000.0;
        y[2*i + 1] = 0;
    }

    FILE *f = fopen("zad3_dane.txt", "w");
    for(int i=0;i<N;i++)
        fprintf(f,"%f\n",y[i]);

    fclose(f);


    f = fopen("zad3_dane.txt", "r");
    for(int i=0;i<N;i++)
        fscanf(f,"%lf",y + i);

    fclose(f);

    gsl_fft_complex_forward(y, 1, N, wavetable, workspace);
    
    double s=0;
    for(int i=0;i<N;i++)
        s+=y[2*i]*y[2*i] + y[2*i+1]*y[2*i+1];

    s/=N;
    s*=0.7;

    printf("limit: %.2f\n",s);

    for(int i=0;i<N;i++) {
        if (y[2*i]*y[2*i] + y[2*i+1]*y[2*i+1] > s)
            printf("moc %d^2 = %.2f\n",i,y[2*i]*y[2*i] + y[2*i+1]*y[2*i+1]);
    }

    f = fopen("zad3_zrobione.txt", "w");
    for(int i=0;i<N;i++)
        fprintf(f,"%f\n",y[i]);

    fclose(f);

    return 0;
}