#include <stdio.h>
#define size 3

int main() {

    double x[] = {0,0,0};

    double coefs[][size] = { {2,-1,0}, {1,6,-2}, {4,-3,8}};
    double res[] = {2,-4,5};

    double omega= 1.5;
    double prev;

    for(int i=0;i<100;i++) {

        for(int i=0;i<size;i++) {
            prev = x[i];
            x[i] = res[i];
            for(int j=0;j<size;j++) {
                if (i!=j)
                    x[i] -= coefs[i][j] * x[j];
            }
            x[i] *= omega/coefs[i][i];
            x[i] += (1-omega)*prev;
        }

        if (!(i%10)) {
            printf("%.4lf %.4lf %.4lf\n", x[0], x[1],x[2]);
        }
    }

    printf("end:\n");
    printf("%.4lf %.4lf %.4lf\n", x[0], x[1],x[2]);
 
 
    return 0;
}