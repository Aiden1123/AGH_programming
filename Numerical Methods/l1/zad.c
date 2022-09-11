#include <stdio.h>
//#include <gsl.h>

int main() {

    double prevprev = 1;
    double prev = 1.0/3;
    double curr;

    for(int i=0;i<120;i++) {
        curr = (13.0/3) * prev - (4.0/3) * prevprev;
        printf("%d: %f\n",i+1,curr);
        prevprev = prev;
        prev = curr;
    }

    return 0;
}