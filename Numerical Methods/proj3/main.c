#include <stdio.h>
#include <stdlib.h>

double abs_double(double x) {
    return x>0 ? x : -x;
}

void solve_jacobi(unsigned size, double (*A)[size], double *b, double *xk, double *xkp1, unsigned iterations);

int main(int argc, char **argv) {

    if (argc==1) {
        printf("enter name of file with A matrix as program argument\n");
        return 1;
    }

    FILE *fp;
    unsigned size;



    if((fp = fopen(argv[1],"rt"))==NULL) {
        printf("did not open file\n");
        return 1;
    }

    fscanf(fp,"%d",&size);

    double xk[size];
    double xkp1[size];

    double A[size][size];
    double b[size];

    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            fscanf(fp,"%lf",&(A[i][j]));
        }
        fscanf(fp,"%lf",&(b[i]));
        xk[i] = argc>3 ? atoi(argv[3]) : 0;
    }

    fclose(fp);

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

    solve_jacobi(size,A,b,xk,xkp1,atoi(argv[2]));

    printf("ostateczny wynik:\n");
    for(int l=0;l<size;l++) {
        printf("%.4lf  ", xkp1[l]);
    }
    printf("\n");

    return 0;
}

void solve_jacobi(unsigned size, double (*A)[size], double *b, double *xk, double *xkp1, unsigned iterations) {
    for(int k=0;k<iterations;k++) {

        for(int i=0;i<size;i++) {
            xkp1[i] = b[i]/A[i][i];
            for(int j=0;j<size;j++) {
                if (i==j)
                    continue;
                xkp1[i] -= (A[i][j]/A[i][i])*xk[j];
            }
        }

        if (!(k%10)) {
            printf("iteracja %3d:  ",k);
            for(int l=0;l<size;l++) {
                printf("%.4lf  ", xkp1[l]);
            }
            printf("\n");
        }

        for(int l=0;l<size;l++)
            xk[l] = xkp1[l];
    }
}