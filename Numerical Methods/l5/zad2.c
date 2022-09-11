#include <stdio.h>
#define size 3

int main() {

    double xk[] = {0,0,0};
    double xkp1[size];

    double coefs[][size] = { {2,-1,0}, {1,6,-2}, {4,-3,8}};
    double res[] = {2,-4,5};

    printf("Jacobi\n");

    for(int i=0;i<100;i++) {

        for(int i=0;i<size;i++) {
            xkp1[i] = res[i]/coefs[i][i];
            for(int j=0;j<size;j++) {
                if (i==j)
                    continue;
                xkp1[i] -= (coefs[i][j]/coefs[i][i])*xk[j];
            }
        }

        if (!(i%10)) {
            printf("%.4lf %.4lf %.4lf\n", xkp1[0], xkp1[1],xkp1[2]);
        }

        xk[0] = xkp1[0];
        xk[1] = xkp1[1];
        xk[2] = xkp1[2];
    }

    printf("end:\n");
    printf("%.4lf %.4lf %.4lf\n", xkp1[0], xkp1[1],xkp1[2]);

    printf("Gaussa-Seidlea\n");

    xk[0] = 0;
    xk[1] = 0;
    xk[2] = 0;

    for(int i=0;i<100;i++) {

        for(int i=0;i<size;i++) {
            xk[i] = res[i]/coefs[i][i];
            for(int j=0;j<size;j++) {
                if (i==j)
                    continue;
                xk[i] -= (coefs[i][j]/coefs[i][i])*xk[j];
            }
        }

        if (!(i%10)) {
            printf("%.4lf %.4lf %.4lf\n", xk[0], xk[1],xk[2]);
        }
    }

    printf("end:\n");
    printf("%.4lf %.4lf %.4lf\n", xk[0], xk[1],xk[2]);
 
 
    return 0;
}