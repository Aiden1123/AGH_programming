#include <stdio.h>
#define N 4


int main() {
    double d[N] = {5,7,-8,9};           //w projekcie wczytac z pliku
    double x[N];                        //kolejnosc dowolna
    double c[N-1] = {2,1,-1};
    double a[N] = {0,1,-1,2};
    double b[N] = {7,3,-2,4};

    for(int i=1;i<N;i++) {
        d[i] = d[i] - c[i-1] * (a[i]/d[i-1]);
        b[i] = b[i] - b[i-1] * (a[i]/d[i-1]);       
    }

    x[N-1] = b[N-1]/d[N-1];

    for (int i=N-2;i>=0;i--) {
        x[i] = (b[i] - c[i] * x[i+1])/d[i];
    }

    for(int i=0;i<N;i++) {
        printf("%.2f ",x[i]);
    }

    printf("\n");

    return 0;
}

/*
for i = 2 to n do {
    d[i] = d[i] - c[i-1] * (a[i]/d[i-1])
    b[i] = b[i] - b[i-1] * (a[i]/d[i-1])
}

x[n] = b[n]/d[n]

for i = n-1 to 1 do {
    x[i] = (b[i] - c[i] * x[i+1])/d[i]
}
*/