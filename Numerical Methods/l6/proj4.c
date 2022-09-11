#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double norma2 (double *x,unsigned size) {
    double sum = 0;
    for(int i=0;i<size;i++)
        sum+=x[i]*x[i];
    return sqrt(sum);
}

double abs_double(double x) {
    return x>0 ? x : -x;
}

void check20(double *x) {
    for(int i=0;i<20;i++) {
        if (fabs(x[i]-i) > 1e-3) {
            printf("BLEDNY WYNIK\n");
            return;
        }
    }
    printf("wszystkie wartosci sa poprawne\n");
}

void check10(double *x) {
    for(int i=0;i<10;i++) {
        if (fabs(x[i]-i) > 1e-3) {
            printf("BLEDNY WYNIK\n");
            return;
        }
    }
    printf("wszystkie wartosci sa poprawne\n");
}

void solve_gauss_siegel(unsigned size, double (*A)[size], double *b, double *xk, unsigned iterations, double epsilon);
int solve_sor(unsigned size, double (*A)[size], double *b, double *x,double omega, unsigned iterations, double epsilon, int info);

int main() {

    FILE *fp;
    unsigned size;

    if((fp = fopen("u4.txt","rt"))==NULL) {
        printf("did not open file\n");
        return 1;
    }

    fscanf(fp,"%d",&size);

    int kmax = 5000;
    double eps = 0;
    double xk[size];

    double A[size][size];
    double b[size];

    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            fscanf(fp,"%lf",&(A[i][j]));
        }
        fscanf(fp,"%lf",&(b[i]));
    }

    fclose(fp);

    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            printf("%lf ",A[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<size;i++) {
        double sum = 0;
        for(int j=0;j<size;j++) {
            if (i!=j) {
                sum+=abs_double(A[i][j]);
            }
        }
        if (abs_double(A[i][i]) <= sum) {
            printf("Macierz nie spelnia warunku dominujacej przekatnej\n");
            return 1;
        }
    }

    double sample_eps[4] = {0.1, 0.01, 0.001, 0.0001};

    for(int i=0;i<4;i++) {

        printf("========eps: %.4f========\n\n",sample_eps[i]);

        printf("gauss-siegel\n");

        solve_gauss_siegel(size,A,b,xk,kmax,sample_eps[i]);

        printf("ostateczny wynik:\n");
        for(int l=0;l<size;l++) {
            printf("%.4f  ", xk[l]);
        }
        printf("\n\n");

        printf("sor\n");

        solve_sor(size,A,b,xk,0.2,kmax,sample_eps[i],1);

        printf("ostateczny wynik:\n");
        for(int l=0;l<size;l++) {
            printf("%.4lf  ", xk[l]);
        }
        printf("\n\n");

    }

    double A_10[10][10];
    double A_20[20][20];

    if((fp = fopen("u10.txt","rt"))==NULL) {
        printf("did not open file\n");
        return 1;
    }

    fscanf(fp,"%d",&size);
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            fscanf(fp,"%lf",&(A_10[i][j]));
        }
        fscanf(fp,"%lf",&(b[i]));
    }

    fclose(fp);

    if((fp = fopen("u20.txt","rt"))==NULL) {
        printf("did not open file\n");
        return 1;
    }

    fscanf(fp,"%d",&size);
    for(int i=0;i<20;i++) {
        for(int j=0;j<20;j++) {
            fscanf(fp,"%lf",&(A_20[i][j]));
        }
        fscanf(fp,"%lf",&(b[i]));
    }

    fclose(fp);

    double solution_ten[10] = {0,1,2,3,4,5,6,7,8,9};
    double solution_twenty[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

    double b_ten[10];
    double b_twenty[20];

    for(int i=0;i<10;i++) {
        b_ten[i] = 0;
        for(int j=0;j<10;j++) {
            b_ten[i] += A_10[i][j] * solution_ten[j];
        }
    }

    for(int i=0;i<20;i++) {
        b_twenty[i] = 0;
        for(int j=0;j<20;j++) {
            b_twenty[i] += A_20[i][j] * solution_twenty[j];
        }
    }

    printf("\n===========test dla n=20 i n=10=========\n\n");
    printf("Gauss_Siegel n=20\n");
    solve_gauss_siegel(20, A_20, b_twenty, solution_twenty, 1000, 0.000001);
    check20(solution_twenty);
    
    printf("Gauss_Siegel n=10\n");
    solve_gauss_siegel(10, A_10, b_ten, solution_ten, 1000, 0.000001);
    check10(solution_ten);
    
    printf("SOR n=10\n");
    solve_sor(10, A_10, b_ten, solution_ten, 0.2, 1000, 0.00001,1);
    check10(solution_ten);

    printf("SOR n=20\n");
    solve_sor(20, A_20, b_twenty, solution_twenty, 0.2, 1000, 0.00001,1);
    check20(solution_twenty);

    printf("\nZnajdowanie optymalnego paramateru relaksacji\n\n");
    int min = kmax;
    int curr;
    double optimal;

    double eps_values[] = {0.01,0.001};
    for(int i=0;i<2;i++) {
        eps = eps_values[i];
        min = kmax;
        for(double omega = 0.2;omega<1.81;omega+=0.05) {
            curr = solve_sor(10,A_10,b_ten,solution_ten,omega,kmax,eps,0);
            if (curr < min)  {
                min = curr;
                optimal = omega;
            }
            printf("eps: %f, omega: %f, iterations: %d\n",eps,omega,curr);
        }
        printf("\nZnaleziona optymalna wartosc dla eps = %f i n = 10 to: %.3f\n\n",eps,optimal);
    }

    for(int i=0;i<2;i++) {
        eps = eps_values[i];
                min = kmax;
        for(double omega = 0.2;omega<1.81;omega+=0.05) {
            curr = solve_sor(20,A_20,b_twenty,solution_twenty,omega,kmax,eps,0);
            if (curr < min)  {
                min = curr;
                optimal = omega;
            }
            printf("eps: %f, omega: %f, iterations: %d\n",eps,omega,curr);
        }
        printf("\nZnaleziona optymalna wartosc dla eps = %f i n = 20 to: %.3f\n\n",eps,optimal);
    }

    return 0;
}



void solve_gauss_siegel(unsigned size, double (*A)[size], double *b, double *xk, unsigned iterations, double epsilon) {
    
    for(int i=0;i<size;i++) {
        xk[i] = 0;
    }

    double delta_x[size];
    double old_norm;

    for(int k=0;k<iterations;k++) {

        for(int i=0;i<size;i++) {
            delta_x[i] = -xk[i];
        }

        old_norm = norma2(xk,size);

        for(int i=0;i<size;i++) {
            xk[i] = b[i]/A[i][i];
            for(int j=0;j<size;j++) {
                if (i==j)
                    continue;
                xk[i] -= (A[i][j]/A[i][i])*xk[j];
            }
        }

        if (!(k%10)) {
            printf("iteracja %3d:  ",k);
            for(int l=0;l<size;l++) {
                printf("%.4lf  ", xk[l]);
            }
            printf("\n");
        }

        for(int i=0;i<size;i++) {
            delta_x[i] += xk[i];
        }

        if(norma2(delta_x,size) <= epsilon * old_norm) {
            break;
        }

    }
}

int solve_sor(unsigned size, double (*coefs)[size], double *b, double *x,double omega, unsigned iterations, double epsilon,int info) {

    for(int i=0;i<size;i++) {
        x[i] = 0;
    }

    double delta_x[size];
    double old_norm;    
    double prev;

    int k;

    for(k=0;k<iterations;k++) {

        for(int i=0;i<size;i++) {
            delta_x[i] = -x[i];
        }

        old_norm = norma2(x,size);

        for(int i=0;i<size;i++) {
            prev = x[i];
            x[i] = b[i];
            for(int j=0;j<size;j++) {
                if (i!=j)
                    x[i] -= coefs[i][j] * x[j];
                }
                x[i] *= omega/coefs[i][i];
                x[i] += (1-omega)*prev;
            }

        if (info) {
            if (!(k%10)) {
                printf("iteracja %3d:  ",k);
                for(int l=0;l<size;l++) {
                    printf("%.4lf  ", x[l]);
                }
                printf("\n");
            }
        }

        for(int i=0;i<size;i++) {
            delta_x[i] += x[i];
        }

        if(norma2(delta_x,size) <= epsilon * old_norm) {
            break;
        }
    }

    return k;
}