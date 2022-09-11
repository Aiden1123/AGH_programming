#include <stdio.h>

int main() {

    double a = 0.25;
    double x = 1;

    for(int i=0;i<15;i++) {
        x = 0.5*(x + a/x);
        printf("%d: %f\n",i+1,x);
    }

    return 0;
}

//gcc <name>.c -lgsl -lgslcblas -lm (-o <nazwa pliku wykonywalnego>)