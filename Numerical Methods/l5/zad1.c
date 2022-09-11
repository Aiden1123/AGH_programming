#include <stdio.h>
#define size 3

int main() {

    //metoda jacobiego

    //x_i_k+1 = -sum((aij/aii)*x_j_k) + b_i/a_ii    j <> i
    //macierz musi byc przekatniowo dominujaca
    // |a_i_i| > sum(|a_i_j|)       j <> i

    //2 -1 0    2
    //1 6 -2    -4
    //4 -3 8    5

    //oczekiwany wynik: 0.62, -0.76, 0.03

    //int size = 3;

    double xk[size] = {0};
    double xkp1[size];

    double coefs[size][size] = { {2,-1,0}, {1,6,-2}, {4,-3,8}};
    double res[size] = {2,-4,5};

    printf("Jacobi\n");

    for(int i=0;i<100;i++) {


        xkp1[0] = res[0]/coefs[0][0] - (coefs[0][1]/coefs[0][0]) * xk[1] - (coefs[0][2]/coefs[0][0]) * xk[2];
        xkp1[1] = res[1]/coefs[1][1] - (coefs[1][0]/coefs[1][1]) * xk[0] - (coefs[1][2]/coefs[1][1]) * xk[2];
        xkp1[2] = res[2]/coefs[2][2] - (coefs[2][0]/coefs[2][2]) * xk[0] - (coefs[2][1]/coefs[2][2]) * xk[1];  

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


        xk[0] = res[0]/coefs[0][0] - (coefs[0][1]/coefs[0][0]) * xk[1] - (coefs[0][2]/coefs[0][0]) * xk[2];
        xk[1] = res[1]/coefs[1][1] - (coefs[1][0]/coefs[1][1]) * xk[0] - (coefs[1][2]/coefs[1][1]) * xk[2];
        xk[2] = res[2]/coefs[2][2] - (coefs[2][0]/coefs[2][2]) * xk[0] - (coefs[2][1]/coefs[2][2]) * xk[1];  

 
        if (!(i%10)) {
            printf("%.4lf %.4lf %.4lf\n", xk[0], xk[1],xk[2]);
        }
    }

    printf("end:\n");
    printf("%.4lf %.4lf %.4lf\n", xk[0], xk[1],xk[2]);
 
 
    return 0;
}