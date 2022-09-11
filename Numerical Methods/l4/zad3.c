#include <stdio.h>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

//bedziemy tworzyc ciag ktory dazy do zadanej wartosci
//poprzednio mielismy wynik w skonczonej liczbie krokow

/*

    7a - 6b = 3
    -8a + 9b =  -4

    a^(k+1) = 6/7 * b^(k) + 3/7
    b^(k+1) = 8/9 * a^(k) - 4/9

    k = 0,1,2,...

    a0, b0 = 0

*/

int main() {

    //metoda jacobiego

    //x_i_k+1 = -sum((aij/aii)*x_j_k) + b_i/a_ii    j <> i
    //macierz musi byc przekatniowo dominujaca
    // |a_i_i| > sum(|a_i_j|)       j <> i

    double x1k,x2k,x1kp1,x2kp1;
    x1k = x2k = 0;

    for(int i=0;i<100;i++) {
        x1kp1 = 6.0/7.0 * x2k + 3.0/7.0;
        x2kp1 = 8.0/9.0 * x1k - 4.0/9.0;

        if (!(i%10)) {
            printf("%.4lf %.4lf\n", x1kp1, x2kp1);
        }

        x2k = x2kp1;
        x1k = x1kp1; 
    }

    printf("end:\n");
    printf("%.4lf %.4lf\n", x1kp1, x2kp1);
 
    return 0;
}